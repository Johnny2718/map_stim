// subscribe the coordinate of the turtle and convert it to coordinate that relative to window
// topic:  /turtle1/pose
// msgs:   /turtlesim/Pose
/*
  rotation along x: pitch;
  rotation along y: roll;
  rotation along z; yaw;
*/
#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>          //convert coordinate
#include <tf2/LinearMath/Quaternion.h>
void doPose(const turtlesim::Pose::ConstPtr& pose)   //get pose information, convert to relative coordinate, then publish
{
    static tf2_ros::TransformBroadcaster pub;       //create publisher,    static: if the function is called, the value is constant
    geometry_msgs::TransformStamped ts;             //organize the data that is goning to be published
    ts.header.frame_id="world";                    //frame_id: the published data from which coordinate system
    ts.header.stamp=ros::Time::now();
    ts.child_frame_id="turtle1";
    ts.transform.translation.x=pose->x;           //translation setting
    ts.transform.translation.y=pose->y;
    ts.transform.translation.z=0;

    tf2::Quaternion qtn;                      // convert to quaternion
    qtn.setRPY(0,0,pose->theta);
    ts.transform.rotation.x=qtn.getX();
    ts.transform.rotation.y=qtn.getY();
    ts.transform.rotation.z=qtn.getZ();
    ts.transform.rotation.w=qtn.getW();
    pub.sendTransform(ts);
}
int main(int argc ,char*argv[] )
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dynamic_pub");
    ros::NodeHandle nh;
    ros::Subscriber sub=nh.subscribe("turtle1/pose",100,doPose);
    ros::spin();
}