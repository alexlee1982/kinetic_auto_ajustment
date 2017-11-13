#include "ros/ros.h"
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/JointState.h>
#include <string>
#include "usr_motion_api.h"
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/TransformStamped.h>

#include <tf/transform_listener.h>


int main(int argc,char ** argv)
{
	int i=0;
	int count=0;
	ros::init(argc,argv,"control_my_robot");
	ros::NodeHandle node;
	ros::Rate loop_rate(100);

	ros::Publisher joint_pub = node.advertise<sensor_msgs::JointState>("joint_states",1);
	const double degree = M_PI/180;


	tf::TransformBroadcaster broadcaster;
	tf::TransformListener listener(ros::Duration(10));
	

	
	sensor_msgs::JointState joint_state;
	double joints[6];

	geometry_msgs::PoseStamped base_point;
	geometry_msgs::PoseStamped j6_point;

	base_point.header.frame_id="base_link";
	j6_point.header.frame_id="link_6";
	j6_point.pose.position.x=0;
	j6_point.pose.position.y=0;
	j6_point.pose.position.z=0;

	j6_point.pose.orientation.x=0;
	j6_point.pose.orientation.y=0;
	j6_point.pose.orientation.z=0;
	j6_point.pose.orientation.w=1;
	
	
	
//	cmd_ipc_init();
//	cmd_cmdbuf_init();
	CTRL_USR_Init();
	
	for(i=0;i<6;i++)
	{
		joints[i]=0.0;
	}

	while(ros::ok())
	{
		count++;	
		MotionFeedback fb;
    	CTRL_GetMotionStatus(&fb);
		joint_state.header.stamp = ros::Time::now();
		base_point.header.stamp = ros::Time(0);
		j6_point.header.stamp = ros::Time(0);

		try{
			listener.transformPose("base_link",j6_point,base_point);
			}
		
		catch(tf::TransformException& ex){
		   ROS_ERROR("Received an exception trying to transform a point from \"base_laser\" to \"base_link\": %s", ex.what());
			}
		
		joint_state.name.resize(7);
		joint_state.position.resize(7);

		joint_state.name[0]="joint_0";
		joint_state.name[1]="joint_1";
		joint_state.name[2]="joint_2";
		joint_state.name[3]="joint_3";
		joint_state.name[4]="joint_4";
		joint_state.name[5]="joint_5";
		joint_state.name[6]="joint_6";

		joint_state.position[1]=fb.jointCmd.j1*degree;
		joint_state.position[2]=fb.jointCmd.j2*degree;
		joint_state.position[3]=fb.jointCmd.j3*degree;
		joint_state.position[4]=fb.jointCmd.j4*degree;
		joint_state.position[5]=fb.jointCmd.j5*degree;
		joint_state.position[6]=fb.jointCmd.j6*degree;
		
		joint_pub.publish(joint_state);

		loop_rate.sleep();
		if(count>=100)
		{
			ROS_INFO("joint_6 position: x=%f y=%f z=%f ",base_point.pose.position.x*1000,base_point.pose.position.y*1000,base_point.pose.position.z*1000);
			count=0;
		}
	}

	

	return 0;
}

