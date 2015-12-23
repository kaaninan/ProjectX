//
//  MotorSubscriber.cpp
//
//
//  Created by Kağan İnan on 12.12.2015.
//
//

#include "ros/ros.h"
#include <sstream>

int temp, voltage, pos, load, moving;
std::string _temp_name, _volt_name, _pos_name, _load_name, _moving_name;


int* degerBul(int id, ros::NodeHandle nh){
    
    int _temp, _voltage, _pos, _load, _moving;
    
    std::string _t = "motor_";
    std::ostringstream oss;
    oss << id;
    _t += oss.str();
    
    _temp_name = _t + "/temp";
    _volt_name = _t + "/voltage";
    _pos_name = _t + "/pos";
    _load_name = _t = "/load";
    _moving_name = _t = "/moving";
    
    nh.getParam(_temp_name, _temp);
    nh.getParam(_volt_name, _voltage);
    nh.getParam(_pos_name, _pos);
    nh.getParam(_load_name, _load);
    nh.getParam(_moving_name, _moving);
    
    ROS_INFO("ID: 1 - TEMP: %d POS %d VOLT %d",_temp, _pos, _voltage);
    
    int values[5] = {_temp, _voltage, _pos, _load, _moving};
    
    return values;
}


int main(int argc, char** argv){
    ros::init(argc,argv, "test_node");
    ros::NodeHandle _nh;
    
    int* degerler = degerBul(1,_nh);
        
    ROS_INFO("ID: 1 - TEMP: %d POS %d VOLT %d",degerler[0],degerler[1],degerler[2]);
    
    
    ros::spin();
}