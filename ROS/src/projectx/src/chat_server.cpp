#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "projectx/MotorIn.h"
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
    using namespace std; // For time_t, time and ctime;
    time_t now = time(0);
    return ctime(&now);
}

// Degiskenler
int gelen_deger = 0;
int giden_deger = 0;
int motor_id = 0;



class Veri
{
public:
    Veri();
    void gonder(std::string type_char ,int motor_id, int in_data); // Veri gonder
    void al(); // Veri al
    
    void processing(std::string type, int out_data); // Gelen veriyi isle
    void callback(const projectx::MotorIn::ConstPtr& msg); // Motordan Gelen Veri
    
private:
    int a;
    int ok;
    std::string dondur;
    
    ros::NodeHandle n;
    
    int motor_id;
    
};

Veri::Veri(){
    a = 0;
    ok = 0;
    
    ros::Subscriber sub = n.subscribe<projectx::MotorIn>("topicMotorDataRead", 1000, &Veri::callback, this);
}


void Veri::callback(const projectx::MotorIn::ConstPtr& msg){
    
}


void Veri::gonder(std::string type_char ,int motor_id, int in_data){
    
    try{
        boost::asio::io_service io_service;
        
        tcp::endpoint endpoint(tcp::v4(), 8225);
        tcp::acceptor acceptor(io_service, endpoint);
        
        tcp::iostream stream;
        boost::system::error_code ec;
        acceptor.accept(*stream.rdbuf(), ec);
        
        std::ostringstream oss;
        oss << "C" << type_char << motor_id << "0000" << in_data;
        
        std::string gelen = oss.str();
        
        stream << gelen;
        
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }



}


void Veri::processing(std::string type, int out_data){
    
    std::string type_char = "";
    int in_data = 0;
    
    // Okuma
    if(type == "read_torque"){
        if(motor_id < 10){
            type_char = "TORQER0";
        }else{
            type_char = "TORQER";
        }
        
        // Oku ROS
        in_data = 203;
        
    }
    
    else if(type == "write_torque"){
        // Yaz ROS
    }
    
    
    // String Hazirla
    std::cout << "Yolla Torque ID: " << motor_id << std::endl; // LOG
    
    gonder(type_char, motor_id, in_data);
    
    
}



void Veri::al(){
    
    try{
        boost::asio::io_service io_service;
        
        tcp::endpoint endpoint(tcp::v4(), 8225);
        tcp::acceptor acceptor(io_service, endpoint);
    
        tcp::iostream stream;
        boost::system::error_code ec;
        acceptor.accept(*stream.rdbuf(), ec);
        
        if (!ec){
            // GELEN VERI
            
            // String'e donustur
            std::ostringstream oss;
            oss << stream.rdbuf();
            std::string gelen = oss.str();
            
            std::cout << "Gelen Data: " << gelen << std::endl; // LOG
            
            // Char Array'a donustur
            char parse[1024];
            strcpy(parse, gelen.c_str());
            
            
            // Motor ID'i cek
            std::ostringstream oss2;
            oss2 << parse[7] << parse[8];
            std::string temp2 = oss2.str();
            char id_temp[2];
            strcpy(id_temp, temp2.c_str());
            motor_id = atoi(id_temp);
            
            
            // Kategorilere ayir
            if (parse[0] == 'S' && parse[1] == 'T' && parse[2] == 'O' && parse[3] == 'R' &&
                parse[4] == 'Q' && parse[5] == 'E' && parse[6] == 'R') {
                
                dondur = "read_torque";
                std::cout << "Reading Torque Enable: " << motor_id << std::endl;
                
            }else if(parse[0] == 'S' && parse[1] == 'P' && parse[2] == 'R' && parse[3] == 'E' & parse[4] == 'P' && parse[5] == 'O' && parse[6] == 'S'){
                
                dondur = "read_present_pos";
                std::cout << "Reading Present Position: " << motor_id << std::endl;
            }
            
            std::cout << "Geçti" << std::endl;
            
            
            // KOMUTU ISLE
            processing(dondur, 123);
            
        }
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}








int main(int argc, char **argv){
    
    ros::init(argc, argv, "Motion_Data_Server");
    
    Veri veri = Veri();

    while (true) {
        veri.al();
    }
    
    ros::spin();
    
    return 0;
}
