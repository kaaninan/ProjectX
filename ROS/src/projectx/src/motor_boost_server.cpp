#include "ros/ros.h"
#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "projectx/MotorBoost.h"
#include "std_msgs/Int64.h"
#include "projectx/MotorOut.h"

using boost::asio::ip::tcp;

std::string node_name = "node_motor_boost_server";

ros::ServiceClient client;
ros::Publisher motor_pub;
ros::Publisher motor_pub_played;

// RME'deki play komutun bittigini belirtir
int played = 0;
// Biten komutun bildirilmesini belirtir
int gonderildi = 0;

// Torque Buffer
int torque_buffer[20];

// Parse ile Motor ID bulunuyor
int get_motor_id(char* parse){
    std::ostringstream oss2;
    oss2 << parse[7] << parse[8];
    std::string temp2 = oss2.str();
    char id_temp[4];
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

  // std::cout << "Boost Server: "<<gonder << std::endl;

  if(motor_id != 0){
    srv.request.in_data = gonder;
    if (client.call(srv)){
      cevap = srv.response.out_data;
    }else{
      ROS_ERROR("Failed to call service server_motor_boost");
    }
  }

  return cevap;
}



int main(int argc, char **argv){

  ros::init(argc, argv, node_name);
  ros::NodeHandle n;
  client = n.serviceClient<projectx::MotorBoost>("server_motor_boost");

  motor_pub = n.advertise<projectx::MotorOut>("motor_out_single", 1000);
  motor_pub_played = n.advertise<std_msgs::Int64>("motor_out_played", 1000);

  ros::Rate loop_rate(100);

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

          // RME CLOSED
          }else if ("END" == gelen) {
            std::cout << "RME EXIT" << std::endl;

          // Main Program CLOSED
          }else if ("QUIT" == gelen) {
            std::cout << "Motor Boost Server: EXIT" << std::endl;
            exit(0);

          }else {
            // std::cout << "Gelen Boost Server: " << gelen << std::endl;
            char parse[1024];
            strcpy(parse, gelen.c_str());

            std::string veri_turu = karsilastir(parse);

            if (veri_turu == "read_torque") {

                // Verileri Al
                int motor_id = get_motor_id(parse);
                int goal = get_goal(parse);

                // if(motor_id == 1){
                //   std_msgs::Int64 data;
                //   data.data = goal;
                //   motor_pub_played.publish(data);
                //   ros::spinOnce();
                // }

                std::ostringstream oss2;
                oss2 << "000" << torque_buffer[motor_id];
                std::string cevap = oss2.str();
                
                // Cevap Hazirla
                std::ostringstream oss;
                if(motor_id < 10){ oss << "C" << "TORQER0" << motor_id << "0000" << cevap;
                }else{ oss << "C" << "TORQER" << motor_id << "0000" << cevap; }
                dondur = oss.str();

                // LOG
                // std::cout << "Reading Torque Status: " << motor_id << " Return: " << dondur << std::endl;
                
                
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
                // std::cout << "Reading Present Position: " << motor_id << " Return: " << dondur << std::endl;
                
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
                // std::cout << "Reading Goal Position: " << motor_id << " Return: " << dondur << std::endl;

            }else if (veri_turu == "write_goal_pos") {

                // Verileri Al
                int motor_id = get_motor_id(parse);
                int goal = get_goal(parse);

                projectx::MotorOut motorData;

                motorData.id = motor_id;
                motorData.pos = goal;
                motorData.torque = -1;

                // ROS_INFO("WRITE GOAL - %d -> %d",motor_id, goal);

                motor_pub.publish(motorData);
                ros::spinOnce();
                loop_rate.sleep();

                // Cevap Hazirla
                std::ostringstream oss;
                if(motor_id < 10){ oss << "C" << "GOALPS0" << motor_id << "00000000"; }
                else{ oss << "C" << "GOALPS" << motor_id << "00000000"; }
                dondur = oss.str();
                

            }else if (veri_turu == "write_torque") {

                // Verileri Al
                int motor_id = get_motor_id(parse);
                int goal = get_goal(parse);

                // Param String Icin
                std::ostringstream oss_param;
                oss_param << "/motor_" << motor_id << "_torque";
                std::string str_param = oss_param.str();

                // Buffer
                torque_buffer[motor_id] = goal; // Burasi Icin
                n.setParam(str_param, goal); // ROS Icin

                projectx::MotorOut motorData;

                motorData.id = motor_id;
                motorData.pos = -1;
                motorData.torque = goal;

                // ROS_INFO("WRITE TORQ - %d -> %d",motor_id, goal);

                motor_pub.publish(motorData);
                ros::spinOnce();
                loop_rate.sleep();

                // Cevap Hazirla
                std::ostringstream oss;
                if(motor_id < 10){ oss << "C" << "TORQER0" << motor_id << "00000000";
                }else{ oss << "C" << "TORQER" << motor_id << "00000000"; }
                dondur = oss.str();


                // motor_pub.publish(motorData);
                // ros::spinOnce();
                // loop_rate.sleep();
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