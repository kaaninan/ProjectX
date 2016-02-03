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
#include <projectx/IntArray.h>
#include <projectx/Gyro.h>
#include <projectx/Sensor.h>

ros::NodeHandle  nh;


// DATA CONTROL
int ok_sensor = 0;
int ok_motor = 0;
int ok_gyro = 0;


// ROS PUBLISHER
projectx::MotorIn motorin_data;
ros::Publisher p_motor("Ami", &motorin_data);

projectx::Gyro gyro_data;
ros::Publisher p_gyro("Agi", &gyro_data);

projectx::Sensor sensor_data;
ros::Publisher p_sensor("Asi", &sensor_data);






// ### ROS -> SERVO TORQUE (SUBSCRIBER)

void messageMotorTorqueIn( const projectx::MotorOut& msg) {
  writeServoTorque(msg.id, msg.torque);
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

// Motorların Sıcaklık, Voltaj ve Posizyon Bilgisi (Read)
int motor_temp[22];
int motor_pos[22];
int motor_volt[22];
int motor_torque[22];

int motorOku = 1; // Her loop'da değer okunacak motor

void publishServo() {
  
  motorin_data.id = motorOku;
  motorin_data.temp = Dynamixel.readTemperature(motorOku);
  motorin_data.voltage = Dynamixel.readVoltage(motorOku);
  motorin_data.pos = Dynamixel.readPosition(motorOku);

  p_motor.publish(&motorin_data);
  
  motorOku++; // Bir Sonraki Motoru Oku ve Publish
  
  if(motorOku == 21)
    motorOku = 1;
  
}


// ## SUBSCRIBER

ros::Subscriber<projectx::MotorOut> sub_motor_torque("Amot", messageMotorTorqueIn);
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
  nh.subscribe(sub_motor_torque);
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
