#include <ros/ros.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2/LinearMath/Quaternion.h>
int main( int argc, char*argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"static_pub");
    ros::NodeHandle nh;
    tf2_ros::StaticTransformBroadcaster pub;                 //create publisher
    geometry_msgs::TransformStamped tfs;                     //create pubished messages
    tfs.header.stamp=ros::Time::now();                       //get current time
    tfs.header.frame_id="base_link";                         //reference points
    tfs.child_frame_id="laser";
    tfs.transform.translation.x=0.2;                        //coordinate of camera relative to base_link
    tfs.transform.translation.y=0.0;
    tfs.transform.translation.z=0.5;

    //use Eulerian angles to transform
    tf2::Quaternion qtn;                                      //create quaternion object
    qtn.setRPY(0,0,0);                                  //set qtn as Eulerian angles (of camera) and this object can transform from Eulerian angles to quaternion, angles are in radian
    tfs.transform.rotation.w=qtn.getW();
    tfs.transform.rotation.x=qtn.getX();
    tfs.transform.rotation.y=qtn.getY();
    tfs.transform.rotation.z=qtn.getZ();
    pub.sendTransform(tfs);                                  //publish message
    ros::spin();

    return 0;
    
}
//rosrun tf2_ros static_transform_publisher    0.2        0.5        0.6        0.1       0.5         0.3        /base_link to/camera
//                                          (x trans)  (y trans)  (z trans)   (z rota)  (y rota)    (x rota)

//rviz