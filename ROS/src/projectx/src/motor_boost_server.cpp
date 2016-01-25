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


// Parse ile Motor ID bulunuyor
int get_motor_id(char* parse){
    std::ostringstream oss2;
    oss2 << parse[7] << parse[8];
    std::string temp2 = oss2.str();
    char id_temp[2];
    strcpy(id_temp, temp2.c_str());
    int id = atoi(id_temp);
    return id;
}

// Parse ile hedeflenen deger bulunuyor
int get_goal(char* parse){
    std::ostringstream oss2;
    oss2 << parse[9] << parse[10] << parse[11] << parse[12];
    std::string temp2 = oss2.str();
    char id_temp[4];
    strcpy(id_temp, temp2.c_str());
    int id = atoi(id_temp);
    return id;
}

// Gelen Data Parse edilerek turu bulunuyor
std::string karsilastir(char* parse){
  std::string dondur = "";
  
  if (parse[0] == 'S' && parse[1] == 'T' && parse[2] == 'O' && parse[3] == 'R' && parse[4] == 'Q' && parse[5] == 'E' && parse[6] == 'R') {
    dondur = "read_torque";
  
  }else if(parse[0] == 'S' && parse[1] == 'P' && parse[2] == 'R' && parse[3] == 'E' && parse[4] == 'P' && parse[5] == 'O' && parse[6] == 'S'){
    dondur = "read_present_pos";
  
  }else if(parse[0] == 'S' && parse[1] == 'T' && parse[2] == 'O' && parse[3] == 'R' && parse[4] == 'Q' && parse[5] == 'E' && parse[6] == 'W') {
    dondur = "write_torque";
  
  }else if(parse[0] == 'S' && parse[1] == 'G' && parse[2] == 'O' && parse[3] == 'A' && parse[4] == 'L' && parse[5] == 'P' && parse[6] == 'S') {
    dondur = "read_goal_pos";

  }else if(parse[0] == 'S' && parse[1] == 'G' && parse[2] == 'O' && parse[3] == 'A' && parse[4] == 'L' && parse[5] == 'P' && parse[6] == 'W') {
    dondur = "write_goal_pos";
  }

  return dondur;
}


// ROS Servisi ile Motorlardan bilgi aliniyor
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
  ROS_INFO("READY: Motor Boost Server ");

  try{
    boost::asio::io_service io_service;
    tcp::endpoint endpoint(tcp::v4(), 8302);
    tcp::acceptor acceptor(io_service, endpoint);
    
    int a = 0, ok = 0;

    std::string gelen = ""; // Gelen Data
    std::string dondur = ""; // Gidecek Data
    
    for(;;){

      tcp::iostream stream;
      boost::system::error_code ec;
      acceptor.accept(*stream.rdbuf(), ec);
      
      if (!ec){
        if(a == 1){
          
          // GELEN YOLCU

          std::ostringstream oss;
          oss << stream.rdbuf();
          gelen = oss.str();

          // Motion Programin Acilmasi Icin
          if ("STARTING" == gelen) {
            ok = 1;
            std::cout << "MOTION STARTING" << std::endl; // Info

          // TODO: TEST1
          }else if ("END" == gelen) {
            exit(0);

          }else {
            std::cout << "Gelen Boost Server: " << gelen << std::endl;
            char parse[1024];
            strcpy(parse, gelen.c_str());

            std::string veri_turu = karsilastir(parse);

            if (veri_turu == "read_torque") {

                // Verileri Al
                int motor_id = get_motor_id(parse);
                std::string cevap = motor_service(veri_turu, motor_id, 0);
                
                // Cevap Hazirla
                std::ostringstream oss;
                if(motor_id < 10){ oss << "C" << "TORQER0" << motor_id << "0000" << cevap;
                }else{ oss << "C" << "TORQER" << motor_id << "0000" << cevap; }
                dondur = oss.str();

                // LOG
                std::cout << "Reading Torque Status: " << motor_id << " Return: " << dondur << std::endl;
                
                
            }else if (veri_turu == "read_present_pos") {

                // Verileri Al
                int motor_id = get_motor_id(parse);
                std::string cevap = motor_service(veri_turu, motor_id, 0);
                
                // Cevap Hazirla
                std::ostringstream oss;
                if(motor_id < 10){ oss << "C" << "PREPOS0" << motor_id << "0000" << cevap; }
                else{ oss << "C" << "PREPOS" << motor_id << "0000" << cevap; }
                dondur = oss.str();

                // LOG
                std::cout << "Reading Present Position: " << motor_id << " Return: " << dondur << std::endl;
                
            }else if (veri_turu == "read_goal_pos") {

                // Verileri Al
                int motor_id = get_motor_id(parse);
                std::string cevap = motor_service(veri_turu, motor_id, 0);
                
                // Cevap Hazirla
                std::ostringstream oss;
                if(motor_id < 10){ oss << "C" << "GOALPS0" << motor_id << "0000" << cevap; }
                else{ oss << "C" << "GOALPS" << motor_id << "0000" << cevap; }
                dondur = oss.str();

                // LOG
                std::cout << "Reading Goal Position: " << motor_id << " Return: " << dondur << std::endl;

            }else if (veri_turu == "write_goal_pos") {

                // Verileri Al
                int motor_id = get_motor_id(parse);
                int goal = get_goal(parse);
                std::string cevap = motor_service(veri_turu, motor_id, goal);
                
                // Cevap Hazirla
                std::ostringstream oss;
                if(motor_id < 10){ oss << "C" << "GOALPW0" << motor_id << "0000" << cevap; }
                else{ oss << "C" << "GOALPW" << motor_id << "0000" << cevap; }
                dondur = oss.str();

                // LOG
                std::cout << "Write Goal Position: " << motor_id << " Return: " << dondur << std::endl;
                
            }else if (veri_turu == "write_torque") {

                // Verileri Al
                int motor_id = get_motor_id(parse);
                int goal = get_goal(parse);
                std::string cevap = motor_service(veri_turu, motor_id, goal);
                
                // Cevap Hazirla
                std::ostringstream oss;
                if(motor_id < 10){ oss << "C" << "TORQEW0" << motor_id << "0000" << cevap; }
                else{ oss << "C" << "TORQEW" << motor_id << "0000" << cevap; }
                dondur = oss.str();

                // LOG
                std::cout << "Write Torque Status: " << motor_id << " Return: " << dondur << std::endl;

            }
          }
          a = 0;

        }else{
          
          // GIDEN YOLCU
  
          if(ok == 1){
            stream << "OK \n";
            ok = 0;

          }else {
            stream << dondur;
            dondur = "";
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