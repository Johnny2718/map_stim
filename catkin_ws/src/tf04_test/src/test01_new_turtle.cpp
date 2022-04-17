#include <ros/ros.h>
#include <turtlesim/Spawn.h>
int main(int argc,char*argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"service_call");
    ros::NodeHandle nh;
    ros::ServiceClient client=nh.serviceClient<turtlesim::Spawn>("/spawn");   //create client
    turtlesim::Spawn spawn;                                                  //organize request data
    spawn.request.x=1.0;
    spawn.request.y=4.0;
    spawn.request.theta=1.57;
    spawn.request.name="turtle2";
    client.waitForExistence();
    bool flag=client.call(spawn);

    if(flag)
    {
        ROS_INFO_STREAM("new turtle is"<<spawn.response.name);
    }
    else
    {
        ROS_INFO_STREAM("request failed");
    }
    return 0;
}
