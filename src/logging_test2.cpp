#include "logging_test2.h"

#include <boost/bind.hpp>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Empty.h>

CbLogger2::CbLogger2() {}

void CbLogger2::run()
{
  int i=0;
  ros::Rate rate(0.6);
  while(ros::ok())
  {
    ROS_DEBUG_STREAM("3");
    ROS_INFO_STREAM("3");
    ROS_WARN_STREAM("3");
    ROS_ERROR_STREAM("3");
    ROS_FATAL_STREAM("3");
    rate.sleep();
  }
}


int main(int argc, char** argv) // Node Main Function
{
  ros::init(argc, argv, "cb_logger2");
  CbLogger2 cb_logger2;
  cb_logger2.run();
  return 0;
}