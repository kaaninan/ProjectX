#include "ros/ros.h"
#include "projectx/MotorBoost.h"
#include "projectx/MotorInArray.h"
#include <typeinfo>

bool add(projectx::MotorBoost::Request  &req, projectx::MotorBoost::Response &res)
{
  res.out = "OK-TAMAM";
  return true;
}

void callback_motor_in(const projectx::MotorInArray::ConstPtr& msg){
  ROS_INFO_STREAM("TEST" << msg->pos[1]);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "node_server_motor_boost");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("motorIncomingData", 1000, callback_motor_in);

  ros::ServiceServer service = n.advertiseService("server_motor_boost", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}