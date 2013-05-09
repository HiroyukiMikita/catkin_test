#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "catkin_test");
  ros::NodeHandle n;
  ros::Publisher test_pub = n.advertise<std_msgs::String>("test",100);

  ros::Rate loop_rate(1);

  while (ros::ok())
    {
      std_msg::String msg;
      msg.data = std::Sting("test");
      ROS_INFO("%s", msg.data.c_str());

      test_pub.publish(msg);

      ros::spinOnce();
      loop_rate.sleep();
    }

  return 0;
}
