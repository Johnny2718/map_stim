#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>        
#include <geometry_msgs/PointStamped.h>  
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>                                 
//subscribe the relative coordinate,enter one coordinate and use tf to transform

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"static_sub");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;                                        //create buffer space
    tf2_ros::TransformListener listener(buffer);                   //create listener and save the data into buffer
    geometry_msgs::PointStamped ps;                                //create coordinate point data
    ps.header.frame_id="laser";
    ps.header.stamp=ros::Time::now();                             //current time
    ps.point.x=2.0;                                               //coordinate of detected objected relative to camera
    ps.point.y=3.0;
    ps.point.z=5.0;
    // ros::Duration(2).sleep();                                    // to ensure having data before transform    
    ros::Rate rate(10);

    while(ros::ok())
    {
        geometry_msgs::PointStamped ps_out;
        try 
        {
            ps_out=buffer.transform(ps,"base_link");                 //convert ps to coordiante that relative to base_link,include <tf2_geometry_msgs/tf2_geometry_msgs.h> 
            ROS_INFO_STREAM("aftertransform x="<<ps_out.point.x);
            ROS_INFO_STREAM("aftertransform y="<<ps_out.point.y);
            ROS_INFO_STREAM("aftertransform z="<<ps_out.point.z);
            ROS_INFO_STREAM("aftertransform z="<<ps_out.header.frame_id.c_str());
        }
        catch(const std::exception& e)
        {
            ROS_INFO_STREAM("error");
        }

    
        rate.sleep();
        ros::spinOnce();
    }


    return 0;
}
