#ifndef LOGGING_TEST
#define LOGGING_TEST

#include <eigen3/Eigen/Dense>
#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <actionlib/server/simple_action_server.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/JointState.h>
#include <visualization_msgs/MarkerArray.h>
#include <std_msgs/Float32MultiArray.h>
#include "cb_msgs/LineSegmentList.h"
#include "cb_msgs/WeightedPidAction.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/buffer.h>

class CbLogger2
{
  public:
    CbLogger2();
    void run();

  private:
    std::string action_name_; 
    ros::NodeHandle nh_;
    ros::Publisher vel_pub_, error_debug_pub_;
    ros::Subscriber line_sub_, odom_sub_, emcy_sub_;
};

#endif