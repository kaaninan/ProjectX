//
// daytime_server.cpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2015 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

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

int main()
{
    try
    {
        boost::asio::io_service io_service;
        
        tcp::endpoint endpoint(tcp::v4(), 8225);
        tcp::acceptor acceptor(io_service, endpoint);
        
        int a = 0, ok = 0;
        std::string dondur = "";
        int motor_id = 0;
        
        for (;;){
            tcp::iostream stream;
            boost::system::error_code ec;
            acceptor.accept(*stream.rdbuf(), ec);
            
            if (!ec){
                if(a == 1){
                    
                    std::ostringstream oss;
                    oss << stream.rdbuf();
                    std::string gelen = oss.str();
                    
                    if ("STARTING" == gelen) {
                        ok = 1;
                        std::cout << "ok" << std::endl;
                        
                    }else {
                        
                        char parse[1024];
                        strcpy(parse, gelen.c_str());
                    
                        if (parse[0] == 'S' && parse[1] == 'T' && parse[2] == 'O' && parse[3] == 'R' &&
                            parse[4] == 'Q' && parse[5] == 'E' && parse[6] == 'R') {
                        
                            dondur = "read_torque";

                            std::ostringstream oss2;
                            oss2 << parse[7] << parse[8];
                            std::string temp2 = oss2.str();
                            
                            std::stringstream s_str( temp2 );
                            s_str >> motor_id;

                            
                            std::cout << "Reading Torque Enable: " << motor_id << std::endl;
                            
                        }
                        
                        std::cout << parse[1] << std::endl;
                        
                    }
                    
                    a = 0;
                }else{
                    
                    if(ok == 1){
                        stream << "OK \n";
                        ok = 0;
                    
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
