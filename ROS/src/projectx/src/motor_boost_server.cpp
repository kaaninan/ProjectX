#include "ros/ros.h"
#include "projectx/MotorOutArray.h"
#include "projectx/MotorInArray.h"
#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int motor_id = 0;


int main(int argc, char **argv){

  try{
    boost::asio::io_service io_service;
    tcp::endpoint endpoint(tcp::v4(), 8256);
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