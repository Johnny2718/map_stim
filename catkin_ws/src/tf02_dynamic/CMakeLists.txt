cmake_minimum_required(VERSION 3.0.2)
project(tf02_dynamic)


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

)


include_directories(

  ${catkin_INCLUDE_DIRS}
)
add_executable(demo01_dynamic_pub src/demo01_dynamic_pub.cpp)
target_link_libraries(demo01_dynamic_pub
${catkin_LIBRARIES}
)
add_executable(demo02_dynamic_sub src/demo02_dynamic_sub.cpp)
target_link_libraries(demo02_dynamic_sub
${catkin_LIBRARIES}
)



