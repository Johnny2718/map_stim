cmake_minimum_required(VERSION 3.0.2)
project(tf04_test)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  tf2
  tf2_geometry_msgs
  tf2_ros
  turtlesim
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES tf01_static
  CATKIN_DEPENDS geometry_msgs roscpp rospy std_msgs tf2 tf2_geometry_msgs tf2_ros
  DEPENDS system_lib
)



include_directories( 
  include
  ${catkin_INCLUDE_DIRS}
  
)


add_executable(test01_new_turtle src/test01_new_turtle.cpp)
target_link_libraries(test01_new_turtle
${catkin_LIBRARIES})






