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
                    }else{
                        std::cout << gelen << std::endl;
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
