#include "ros/ros.h"
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

int main()
{
    try
    {
        boost::asio::io_service io_service;
        
        tcp::endpoint endpoint(tcp::v4(), 8225);
        tcp::acceptor acceptor(io_service, endpoint);
        
        int a = 0, ok = 0;
        std::string dondur = "";
        
        for (;;){
            tcp::iostream stream;
            boost::system::error_code ec;
            acceptor.accept(*stream.rdbuf(), ec);
            
            if (!ec){
                if(a == 1){
                    
                    // GELEN VERI
                    
                    std::ostringstream oss;
                    oss << stream.rdbuf();
                    std::string gelen = oss.str();
                    
                    if ("STARTING" == gelen) {
                        ok = 1;
                        std::cout << "ok" << std::endl; // Info
                        
                    }else {
                        
                        std::cout << "Gelen Data: " << gelen << std::endl;
                        
                        char parse[1024];
                        strcpy(parse, gelen.c_str());
                    
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
                        
                        //std::cout << parse[1] << std::endl;
                    
                    }
                    
                    a = 0;
                }else{
                    
                    // YOLLANACAK VERI
                    
                    if(ok == 1){
                        stream << "OK \n";
                        ok = 0;
                    
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
                        
                    }else {
                        stream << make_daytime_string();
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
