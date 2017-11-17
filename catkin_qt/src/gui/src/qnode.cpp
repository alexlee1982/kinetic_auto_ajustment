/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/gui/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace gui {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"gui");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
  //ros::NodeHandle n;
	// Add your ros communications here.
  //chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
	start();
	return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"gui");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
  //ros::NodeHandle n;
	// Add your ros communications here.
  //chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
	start();
	return true;
}

void QNode::run() {
  const double degree = M_PI/180;
  ros::NodeHandle node;
  ros::Publisher joint_pub = node.advertise<sensor_msgs::JointState>("joint_states",1);
  tf::TransformBroadcaster broadcaster;
  tf::TransformListener listener(ros::Duration(10));

  sensor_msgs::JointState joint_state;
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

  ros::Rate loop_rate(20);
//	int count = 0;
	while ( ros::ok() ) {
    mutex.lock();
//    std_msgs::String msg;
//		std::stringstream ss;
//		ss << "hello world " << count;
//		msg.data = ss.str();
//		chatter_publisher.publish(msg);
//		log(Info,std::string("I sent: ")+msg.data);

    joint_state.header.stamp = ros::Time::now();
    base_point.header.stamp = ros::Time(0);
    j6_point.header.stamp = ros::Time(0);

    try{
      listener.transformPose("base_link",j6_point,base_point);
      }

    catch(tf::TransformException& ex){
       ROS_ERROR("Received an exception trying to transform a point from \"link_6\" to \"base_link\": %s", ex.what());
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

    joint_state.position[1]=joint[0]*degree;
    joint_state.position[2]=joint[1]*degree;
    joint_state.position[3]=joint[2]*degree;
    joint_state.position[4]=joint[3]*degree;
    joint_state.position[5]=joint[4]*degree;
    joint_state.position[6]=joint[5]*degree;

    joint_pub.publish(joint_state);

    tran.x=base_point.pose.position.x*1000;
    tran.y=base_point.pose.position.y*1000;
    tran.z=base_point.pose.position.z*1000;

		ros::spinOnce();
		loop_rate.sleep();
//		++count;
    mutex.unlock();
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)

}


void QNode::log( const LogLevel &level, const std::string &msg) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Fatal) : {
				ROS_FATAL_STREAM(msg);
				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
				break;
		}
	}
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
	Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}
PmCartesian QNode::readPositon()
{
  PmCartesian out;

  out.x=tran.x;
  out.y=tran.y;
  out.z=tran.z;

  return out;
}

void QNode::writeJointPosition(double *jp)
{
  int i=0;

  for(i=0;i<6;i++)
  {
    joint[i]=jp[i];
  }

}

}  // namespace gui
