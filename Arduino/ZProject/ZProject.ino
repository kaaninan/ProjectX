// MINIMU
// GYRO
#include <Wire.h>
#include <L3G.h>
#include <LSM303.h>

// SERVO
#include <DynamixelSerial1.h>

// SENSOR
#include <OneWire.h>
#include <SharpIR.h>

// ROS
#include <ros.h>
#include <std_msgs/String.h>
#include <projectx/MotorIn.h>
#include <projectx/MotorOut.h>
#include <projectx/Gyro.h>
#include <projectx/Sensor.h>

ros::NodeHandle  nh;

// ROS
projectx::MotorIn motorin_data;
ros::Publisher p_motor("arduinoMotorIncoming", &motorin_data);




void setup()
{

  //gyro_start();

  // Motor ID'lerini diziye yaz ve varsayılan aci degeri (0) ayarla
  //motorNoTanimla();
  
  nh.initNode();
  nh.advertise(p_motor);
  nh.subscribe(sub);
  
  Dynamixel.begin(1000000, 2);

  pinMode(13, OUTPUT);
  
}

void loop()
{
  //gyro_loop();
  read_sensor();
  nh.spinOnce();
  delay(50);
}



                                                                                   
