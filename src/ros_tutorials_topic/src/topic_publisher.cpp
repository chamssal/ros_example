#include "ros/ros.h"
#include "ros_tutorials_topic/MsgTutorial.h"

int main(int argc,char**argv)
{
    ros::init(argc,argv,"topic_publisher");
    ros::NodeHandle nh;
    ros::Publisher ros_tutorials_pub = nh.advertise<ros_tutorials_topic::MsgTutorial>("ros_tutorial_msg",100);
    ros::Rate loop_rate(10);
    ros_tutorials_topic::MsgTutorial msg;
    int count =0;
    while(ros::ok())
    {
        msg.stamp = ros::Time::now();
        msg.data = count;

        ROS_INFO("Send msg = %d %d %d",msg.stamp.sec,msg.stamp.nsec,msg.data); //printf

        ros_tutorials_pub.publish(msg);
        loop_rate.sleep();
        ++count;

    }
    return 0;
}
