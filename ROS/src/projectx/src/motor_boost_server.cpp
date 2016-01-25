#include "ros/ros.h"
#include "projectx/MotorOutArray.h"
#include "projectx/MotorInArray.h"
#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "projectx/MotorBoost.h"

using boost::asio::ip::tcp;

std::string node_name = "node_motor_boost_server";

ros::ServiceClient client;

int get_motor_id(char* parse){
    std::ostringstream oss2;
    oss2 << parse[7] << parse[8];
    std::string temp2 = oss2.str();
    char id_temp[2];
    strcpy(id_temp, temp2.c_str());
    int id = atoi(id_temp);
    return id;
}



std::string karsilastir(char* parse){
  std::string dondur = "";
  
  if (parse[0] == 'S' && parse[1] == 'T' && parse[2] == 'O' && parse[3] == 'R' && parse[4] == 'Q' && parse[5] == 'E' && parse[6] == 'R') {
    dondur = "read_torque";
  
  }else if(parse[0] == 'S' && parse[1] == 'P' && parse[2] == 'R' && parse[3] == 'E' && parse[4] == 'P' && parse[5] == 'O' && parse[6] == 'S'){
    dondur = "read_present_pos";
  }

  return dondur;
}


std::string motor_service(std::string veri_turu, int motor_id, int komut){
  projectx::MotorBoost srv;
  std::string cevap = "";

  std::ostringstream oss;
  oss << veri_turu << ":" << motor_id << ":" << komut;
  std::string gonder = oss.str();

  srv.request.in_data = gonder;
  if (client.call(srv)){
    cevap = srv.response.out_data;
  }else{
    ROS_ERROR("Failed to call service server_motor_boost");
  }
  return cevap;
}



int main(int argc, char **argv){

  ros::init(argc, argv, node_name);
  ros::NodeHandle n;
  client = n.serviceClient<projectx::MotorBoost>("server_motor_boost");
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

          }else if ("END" == gelen) {

            exit(0);

          }else {
            std::cout << "Gelen Boost Server: " << gelen << std::endl;
            char parse[1024];
            strcpy(parse, gelen.c_str());

            std::string veri_turu = karsilastir(parse);

            if (veri_turu == "read_torque") {

                int motor_id = get_motor_id(parse);

                
                std::cout << "Reading Torque Enable: " << motor_id << std::endl;
                
                
                
            }else if (veri_turu == "read_present_pos") {
                
                int motor_id = get_motor_id(parse);
                
                std::cout << "Reading Present Position: " << motor_id << std::endl;

                std::string cevap = motor_service(veri_turu, motor_id, 0);
                    
                std::ostringstream oss;
                if(motor_id < 10){
                    oss << "C" << "PREPOS0" << motor_id << "0000" << cevap;
                }else{
                    oss << "C" << "PREPOS" << motor_id << "0000" << cevap;
                }
                
                std::string dondur = oss.str();
                
            }



          }
          a = 0;
      }else{
          // YOLLANACAK VERI
        
          std::string giden = "";

  
          if(ok == 1){
            stream << "OK \n";
            ok = 0;
          }else {
            stream << giden;
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