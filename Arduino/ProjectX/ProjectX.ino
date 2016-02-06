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
#include <projectx/Hash.h>
#include <projectx/MotorIn.h>
#include <projectx/MotorOut.h>
#include <projectx/IntArray.h>
#include <projectx/Gyro.h>
#include <projectx/Sensor.h>

ros::NodeHandle  nh;


// DATA CONTROL
int ok_sensor = 0;
int ok_motor = 0;
int ok_gyro = 0;


// ROS PUBLISHER
projectx::Hash motorin_data;
ros::Publisher p_motor("Ami", &motorin_data);

projectx::Gyro gyro_data;
ros::Publisher p_gyro("Agi", &gyro_data);

projectx::Sensor sensor_data;
ros::Publisher p_sensor("Asi", &sensor_data);






// ### ROS -> SERVO TORQUE (SUBSCRIBER)

void messageMotorSingleIn( const projectx::MotorOut& msg) {
  if(msg.torque != -1){
    writeServoTorque(msg.id, msg.torque);
  }
  else if(msg.pos != -1){
    writeServoPos(msg.id, msg.pos);
  }
}

void writeServoTorque(int motor_id, int torque) {
  Dynamixel.torqueStatus(motor_id, torque);
}




// ### ROS -> SERVO POS (SUBSCRIBER)

void messageMotorPosIn( const projectx::IntArray& msg) {
  for(int i = 0; i < 20; i++){
    int pos = msg.deger[i];  
    writeServoPos(i+1, pos);
  }
}

void writeServoPos(int motor_id, int pos) {
  Dynamixel.move(motor_id, pos);
}



// ### ROS -> DATA CONTROL (SUBSCRIBER)

void messageDataControl( const projectx::IntArray& msg) {
  ok_sensor = msg.deger[0];
  ok_gyro = msg.deger[1];
  ok_motor = msg.deger[2];
}







// ### SERVO -> ROS (PUBLISHER)

int motorId = 1;

void publishServo() {
  int pos = Dynamixel.readPosition(motorId);
  motorin_data.id = motorId;
  motorin_data.deger = pos;
  p_motor.publish(&motorin_data);
  
  motorId++;
  
  if(motorId == 21) motorId = 1;

}


// ## SUBSCRIBER

ros::Subscriber<projectx::MotorOut> sub_motor_single("Amot", messageMotorSingleIn);
ros::Subscriber<projectx::IntArray> sub_motor_pos("Amop", messageMotorPosIn);
ros::Subscriber<projectx::IntArray> sub_data_control("Adc", messageDataControl);


void setup() {

  //gyro_start();

  nh.initNode();

  // Publisher
  nh.advertise(p_motor);
  nh.advertise(p_gyro);
  nh.advertise(p_sensor);

  // Subscriber
  nh.subscribe(sub_motor_pos);
  nh.subscribe(sub_motor_single);
  nh.subscribe(sub_data_control);

  Dynamixel.begin(1000000, 2);

  delay(1000);
}

void loop() {
  if(ok_sensor == 1) publishSensor();
  if(ok_gyro == 1) gyro_loop();
  if(ok_motor == 1) publishServo();

  nh.spinOnce();
  delay(1);
}

