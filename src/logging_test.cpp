#include "logging_test.h"

#include <boost/bind.hpp>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Empty.h>

CbLogger::CbLogger() {}

void CbLogger::run()
{
  int i=0;
  ros::Rate rate(0.5);
  while(ros::ok())
  {
    ROS_DEBUG_STREAM("1");
    ROS_INFO_STREAM("1");
    ROS_WARN_STREAM("1");
    ROS_ERROR_STREAM("1");
    ROS_FATAL_STREAM("1");
    rate.sleep();
  }
}


int main(int argc, char** argv) // Node Main Function
{
  ros::init(argc, argv, "cb_logger");
  CbLogger cb_logger;
  cb_logger.run();
  return 0;
}