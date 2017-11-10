#include "ros/ros.h"
#include <tf/transform_broadcaster.h>


int main(int argc ,char ** argv)
{
	ros::init(argc,argv,"robot_tf_publiser");
	ros::NodeHandle handle;

	ros::Rate r(10);

	tf::TransformBroadcaster broad;

	while(handle.ok())
	{
		broad.sendTransform(tf::StampedTransform(tf::Transform(tf::Quaternion(0,0,0,1),tf::Vector3(0.3,0.0,0.2)),
			ros::Time::now(),
			"base_link","laser_link"));
		r.sleep();
	}

	return 0;
}

