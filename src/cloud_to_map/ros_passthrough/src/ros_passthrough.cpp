#include <iostream>
#include <ros/ros.h>  
#include <sensor_msgs/PointCloud2.h>  
#include <visualization_msgs/Marker.h>
#include <pcl/point_types.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/passthrough.h>
#include <pcl_conversions/pcl_conversions.h>  
#include <pcl/io/pcd_io.h>
#include <dynamic_reconfigure/server.h>

ros::Publisher pcl_pub;

float top,bottom;


int main (int argc, char **argv)  
{  
  ros::init (argc, argv, "ros_passthrough");  
  ros::NodeHandle nh("~"); 
  nh.param<float>("top",top,2);
  nh.param<float>("bottom",bottom,-1.4);
  pcl_pub = nh.advertise<sensor_msgs::PointCloud2> ("/passthrough", 2);  //参数缓冲区大小　２

    // 将点云格式为sensor_msgs/PointCloud2 格式转为 pcl/PointCloud
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloudIn(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
while (ros::ok())
{
  if(pcl::io::loadPCDFile<pcl::PointXYZ>("/home/ysc/cpu_mapping/1.pcd",*cloudIn) == -1)
  {
    std::cerr << "open failed!" << std::endl;
		return -1;
  }
  pcl::PassThrough<pcl::PointXYZ> pass;
  pass.setInputCloud(cloudIn);
  pass.setFilterFieldName("z");
  pass.setFilterLimits(bottom,top);
  pass.setFilterLimitsNegative (false);
  //pass.setNegative(true);
  pass.filter(*cloud_filtered);

  //再rviz上显示所以要转换回PointCloud2
  sensor_msgs::PointCloud2 cloud_filteredMsg;  
  pcl::toROSMsg(*cloud_filtered,cloud_filteredMsg);
  cloud_filteredMsg.header.stamp=ros::Time::now();
  cloud_filteredMsg.header.frame_id="/world";
  pcl_pub.publish (cloud_filteredMsg);
}


  //ros::Rate loop_rate(0.5);　　//数据发送频率
  ros::spin();  
  return 0;  
}  

