

#include <fast_ndt_mapping/LidarMapping.h>
#include <iostream>
#include <ros/ros.h>

int main(int argc,char** argv){
	ros::init(argc,argv,"ndt_mapping_node");
	ros::NodeHandle nh;
	ros::NodeHandle private_nh("~");

	FAST_NDT::LidarMapping mapping;
	mapping.run(nh,private_nh);
	ros::Rate(10);
	ros::spin();
	return 0;
}











