#include "ros/ros.h"
#include "projectx/MotorBoost.h"

bool add(projectx::MotorBoost::Request  &req, projectx::MotorBoost::Response &res)
{
  res.out = "OK-TAMAM";
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "node_server_motor_boost");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("server_motor_boost", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}