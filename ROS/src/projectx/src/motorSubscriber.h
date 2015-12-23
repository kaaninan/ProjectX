//
//  MotorSubscriber.hpp
//
//
//  Created by Kağan İnan on 12.12.2015.
//
//

#ifndef Motor_h
#define Motor_h

#include <stdio.h>
#include <sstream>
#include "ros/ros.h"

#endif /* MotorSubscriber_hpp */

class Motor{
    
public:
    
    Motor();
    
    int* degerBul(int);
    
    
private:
    int _temp, _voltage, _pos, _load, _moving;
    std::string _temp_name, _volt_name, _pos_name, _load_name, _moving_name;
    
    ros::NodeHandle nh_;
};





int* Motor::degerBul(int id){
    
    std::string _t = "motor_";
    std::ostringstream oss;
    oss << id;
    _t += oss.str();
    
    _temp_name = _t + "/temp";
    _volt_name = _t + "/voltage";
    _pos_name = _t + "/pos";
    _load_name = _t = "/load";
    _moving_name = _t = "/moving";
    
    nh_.getParam(_temp_name, _temp);
    nh_.getParam(_volt_name, _voltage);
    nh_.getParam(_pos_name, _pos);
    nh_.getParam(_load_name, _load);
    nh_.getParam(_moving_name, _moving);
    
    int* values = new int[4];
    values[0] = _temp;
    values[1] = _pos;
    values[2] = _voltage;
    values[3] = _load;
    values[4] = _moving;
    
    //ROS_INFO("ID: 1 - TEMP: %d POS %d VOLT %d",_temp, _pos, _voltage);
    
    return values;
    
}

Motor::Motor(){
    
}