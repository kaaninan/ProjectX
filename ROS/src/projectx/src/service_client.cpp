#include "ros/ros.h"
#include "projectx/AddTwoInts.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<projectx::AddTwoInts>("add_two_ints");
  
  for (int i = 0; i< 200; i++){

      projectx::AddTwoInts srv;
      srv.request.a = i;
      srv.request.b = 0;
      if (client.call(srv))
      {
        ROS_INFO("Sum: %ld", (long int)srv.response.sum);
      }
      else
      {
        ROS_ERROR("Failed to call service add_two_ints");
        return 1;
      }

  }

  return 0;
}