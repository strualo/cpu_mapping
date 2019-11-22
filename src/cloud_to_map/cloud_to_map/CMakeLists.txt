cmake_minimum_required(VERSION 2.8.3)
project(cloud_to_map)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  nav_msgs
  ##pcl
  pcl_ros
  roscpp
)

#add dynamic reconfigure api   ROS 动态参数
generate_dynamic_reconfigure_options(
  cfg/cloud_to_map_node.cfg
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES cloud_to_map
#  CATKIN_DEPENDS dynamic_reconfigure nav_msgs pcl pcl_ros roscpp
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(cloud_to_map_node src/cloud_to_map_node.cpp)
add_dependencies(cloud_to_map_node ${PROJECT_NAME}_gencfg)
target_link_libraries(cloud_to_map_node ${catkin_LIBRARIES})


