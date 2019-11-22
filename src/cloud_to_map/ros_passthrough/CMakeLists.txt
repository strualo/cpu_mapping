cmake_minimum_required(VERSION 2.8.3)
project(ros_passthrough)

find_package(catkin REQUIRED
             roscpp
             rospy
             std_msgs
             sensor_msgs
             cv_bridge
             image_transport
             pcl_conversions
             pcl_ros
             geometry_msgs
             message_generation
)
#find_package(PCL 1.8 REQUIRED)

catkin_package( )

include_directories(include ${catkin_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS} )

add_executable(ros_passthrough src/ros_passthrough.cpp)
target_link_libraries(ros_passthrough ${catkin_LIBRARIES})

