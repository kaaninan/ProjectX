//
//  MotorSubscriber.cpp
//
//
//  Created by Kağan İnan on 12.12.2015.
//
//

#include "motorSubscriber.h"
#include <unistd.h>


int main(int argc, char** argv){
    ros::init(argc,argv, "test_node");
    
    Motor motor;
    int* degerler = new int[4];
    
    while (1) {
        for(int i = 1; i < 21; i++){
            degerler = motor.degerBul(i);
            ROS_INFO("ID: %d - TEMP: %d POS %d VOLT %d",i, degerler[0], degerler[1], degerler[2]);
        }
        usleep(1000000);
    }
    
    ros::spin();
}