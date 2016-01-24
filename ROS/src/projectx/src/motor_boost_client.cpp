#include "ros/ros.h"
#include "projectx/MotorOutArray.h"
#include "projectx/MotorInArray.h"
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "boost/bind.hpp"
#include "boost/asio.hpp"
#include "boost/thread/thread.hpp"

using boost::asio::ip::tcp;

class Veri{
public:
    Veri();
    void loop();
private:
    ros::NodeHandle n;
    ros::Subscriber sub;
    void motor_in_callback(const projectx::MotorInArray::ConstPtr& motor_data);
    int devam, a;
};


void Veri::motor_in_callback(const projectx::MotorInArray::ConstPtr& msg)
{
  ROS_INFO("I heard: ");
}

Veri::Veri(){
    sub = n.subscribe<projectx::MotorInArray>("motorIncomingData", 1000, &Veri::motor_in_callback, this);
    ros::spinOnce();
}


void Veri::loop(){
    ROS_INFO("1");
    devam = 1;
    while (devam) {
        ROS_INFO("2");
        a = 1;
        try{

            ROS_INFO("3");

            tcp::iostream s("127.0.0.1", "8300");
            
            if (!s){
                std::cout << "Unable to connect: " << s.error().message() << std::endl;
            }
            else if(a == 0){
                
                // GELEN
                std::string line;
                std::getline(s, line);
                
                std::cout << line << std::endl;
                
                if (line == "HATA ") {
                    std::cout << "HATA" << std::endl;
                    break;
                    
                }else{
                    std::cout << line << std::endl;
                    
                    char parse[1024];
                    strcpy(parse, line.c_str());
                    
                    if (parse[0] == 'C' && parse[1] == 'P' && parse[2] == 'R' && parse[3] == 'E' &&
                        parse[4] == 'P' && parse[5] == 'O' && parse[6] == 'S') {
                        
                        std::cout << "Cevap Pos: "<< parse[14] << parse[15] << parse[16] << std::endl;
                        
                        int value_motor = 599;
                        
                        break;
                        
                    }
                    
                    devam = 0;
                }
                
                
                
                a = 1;
                
            }else{
                
                // GIDEN
                s << "BOS";
                a = 0;
            }
            ros::spin();
        }
        catch (std::exception& e){
            std::cout << "Exception: " << e.what() << std::endl;
        }

        ros::spin();
    }
}


int main(int argc, char **argv){

    ros::init(argc, argv, "motor_boost_client2");
    Veri veri;
    veri.loop();

    // veri.loop();

    return 0;
}



/*



}else if(dondur == "read_torque"){
                    
                    std::cout << "Yolla Torque ID: " << motor_id << std::endl;

                    std::ostringstream oss;
                    if(motor_id < 10){
                        oss << "C" << "TORQER0" << motor_id << "0000" << "0001";
                    }else{
                        oss << "C" << "TORQER" << motor_id << "0000" << "0001";
                    }
                    
                    std::string gelen = oss.str();
                    stream << gelen;
                    
                    dondur = "";
                    
                }else if(dondur == "read_present_pos"){
                    
                    std::cout << "Yolla Pre Pos ID: " << motor_id << std::endl;
                    
                    std::ostringstream oss;
                    if(motor_id < 10){
                        oss << "C" << "PREPOS0" << motor_id << "0000" << "0123";
                    }else{
                        oss << "C" << "PREPOS" << motor_id << "0000" << "0123";
                    }
                    
                    std::string gelen = oss.str();
                    stream << gelen;
                    
                    dondur = "";




*/
/*

if (parse[0] == 'S' && parse[1] == 'T' && parse[2] == 'O' && parse[3] == 'R' &&
                        parse[4] == 'Q' && parse[5] == 'E' && parse[6] == 'R') {
                    
                        dondur = "read_torque";

                        std::ostringstream oss2;
                        oss2 << parse[7] << parse[8];
                        std::string temp2 = oss2.str();
                        char id_temp[2];
                        strcpy(id_temp, temp2.c_str());
                        motor_id = atoi(id_temp);

                        
                        std::cout << "Reading Torque Enable: " << motor_id << std::endl;
                        
                        
                        
                    }else if(parse[0] == 'S' && parse[1] == 'P' && parse[2] == 'R' && parse[3] == 'E' &&
                             parse[4] == 'P' && parse[5] == 'O' && parse[6] == 'S'){
                        
                        dondur = "read_present_pos";
                        
                        std::ostringstream oss2;
                        oss2 << parse[7] << parse[8];
                        std::string temp2 = oss2.str();
                        char id_temp[2];
                        strcpy(id_temp, temp2.c_str());
                        motor_id = atoi(id_temp);
                        
                        std::cout << "Reading Present Position: " << motor_id << std::endl;
                        
                    }

*/