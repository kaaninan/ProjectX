#include "ros/ros.h"
#include "projectx/MotorOutArray.h"
#include "projectx/MotorInArray.h"
#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "projectx/AddTwoInts.h"

using boost::asio::ip::tcp;

int motor_id = 0;

bool add(projectx::AddTwoInts::Request  &req,
         projectx::AddTwoInts::Response &res)
{
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}


int main(int argc, char **argv){

  ros::init(argc, argv, "motor_boost_server2");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<projectx::AddTwoInts>("add_two_ints");
  ROS_INFO("Service Client Hazir");

  try{
    boost::asio::io_service io_service;
    tcp::endpoint endpoint(tcp::v4(), 8302);
    tcp::acceptor acceptor(io_service, endpoint);
    
    int a = 0, ok = 0;

    std::string gelen = ""; // Gelen Data
    
    for(;;){

      // MOTION - SERVER

      tcp::iostream stream;
      boost::system::error_code ec;
      acceptor.accept(*stream.rdbuf(), ec);
      
      if (!ec){
        if(a == 1){
          // GELEN VERI
          std::ostringstream oss;
          oss << stream.rdbuf();
          gelen = oss.str();

          if ("STARTING" == gelen) {
            ok = 1;
            std::cout << "MOTION STARTING" << std::endl; // Info
          }else {
            if(gelen != "GIDEN"){
              std::cout << "Gelen Data: " << gelen << std::endl;
              char parse[1024];
              strcpy(parse, gelen.c_str());
            }
          }
          a = 0;
      }else{
          // YOLLANACAK VERI
        

      projectx::AddTwoInts srv;
      srv.request.a = 2;
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

  
          if(ok == 1){
            stream << "OK \n";
            ok = 0;
          }else {
            stream << gelen;
          }
          a = 1;
        }
      }
      
    }
  }
  catch (std::exception& e)
  {
      std::cerr << e.what() << std::endl;
  }

  return 0;
}