#include "ros/ros.h"
#include <tf/transform_listener.h>
#include <geometry_msgs/PointStamped.h>

void transformPoint(const tf::TransformListener & listener)
{
	geometry_msgs::PointStamped laser_point;

	//laser_point.header.frame_id = "laser_link";

	//laser_point.header.stamp = ros::Time();

	//laser_point.point.x = 1.0;
	//laser_point.point.y = 0.2;
	//laser_point.point.z = 0.0;

	geometry_msgs::PointStamped base_point;
	base_point.header.frame_id="base_link";
	base_point.header.stamp = ros::Time();


	base_point.point.x = 3.0;
	base_point.point.y = 4.0;
	base_point.point.z = 5.0;


	try
	{
		//geometry_msgs::PointStamped base_point;
		//listener.transformPoint("base_link", laser_point, base_point);
		listener.transformPoint("laser_link", base_point, laser_point);

		ROS_INFO("base_laser: (%.2f, %.2f. %.2f) -----> base_link: (%.2f, %.2f, %.2f) at time %.2f",
				 laser_point.point.x, laser_point.point.y, laser_point.point.z,
				 base_point.point.x, base_point.point.y, base_point.point.z, base_point.header.stamp.toSec());
	}
	catch(tf::TransformException& ex)
	{
		ROS_ERROR("Received an exception trying to transform a point from \"base_laser\" to \"base_link\": %s", ex.what());
	}



	
}
int main(int argc, char ** argv)
{
	ros::init(argc,argv,"setup_tf_listener");
	ros::NodeHandle node;

	tf::TransformListener listener(ros::Duration(10));

	//ros::Timer timer = node.createTimer(ros::Duration(1.0),boost::bind(&transformPoint,boost::ref(listener));
	ros::Timer timer = node.createTimer(ros::Duration(1.0), boost::bind(&transformPoint, boost::ref(listener)));

	ros::spin();
	return 0;
}

