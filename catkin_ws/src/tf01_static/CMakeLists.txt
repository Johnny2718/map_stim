cmake_minimum_required(VERSION 3.0.2)
project(tf01_static)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  tf2
  tf2_geometry_msgs
  tf2_ros
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES tf01_static
  CATKIN_DEPENDS geometry_msgs roscpp rospy std_msgs tf2 tf2_geometry_msgs tf2_ros
  DEPENDS system_lib
)
# add_dependencies(demo01_static_pub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
# add_dependencies(demo02_static_sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

 add_executable(demo01_static_pub src/demo01_static_pub.cpp)
 target_link_libraries(demo01_static_pub
   ${catkin_LIBRARIES}
 )
 add_executable(demo02_static_sub src/demo02_static_sub.cpp)
 target_link_libraries(demo02_static_sub
   ${catkin_LIBRARIES}
 )