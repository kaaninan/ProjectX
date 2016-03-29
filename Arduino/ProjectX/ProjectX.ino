#include <SoftwareSerial.h>

// GYRO
#include <Wire.h>
#include <L3G.h>
#include <LSM303.h>

// SERVO
#include <DynamixelSerial1.h>

// SENSOR
#include <OneWire.h>
#include <SharpIR.h>
#include <DHT.h>

// ROS
#include <ros.h>
#include <std_msgs/Int64.h>
#include <projectx/Hash.h>
#include <projectx/MotorIn.h>
#include <projectx/MotorOut.h>
#include <projectx/IntArray.h>
#include <projectx/Gyro.h>
#include <projectx/Sensor.h>

ros::NodeHandle  nh;


// ### PIN ###

// OUT
const int power_led_1 = 4;
const int power_led_2 = 5;
const int power_led_3 = 6;
const int buzzer = 7;
const int redPin = 8;
const int greenPin = 11;
const int bluePin = 12;


// SENSOR
OneWire temp_pin(22);
SharpIR sharp(A1, 25, 93, 1080);
int ldr_pin = 0;
#define DHTPIN 23
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


// DATA CONTROL (for loop)
int ok_sensor = 0;
int ok_motor = 0;
int ok_gyro = 0;



// ROS PUBLISHER
projectx::Hash motorin_data;
ros::Publisher p_motor("arduino_in_motor", &motorin_data);

projectx::Gyro gyro_data;
ros::Publisher p_gyro("arduino_in_gyro", &gyro_data);

projectx::Sensor sensor_data;
ros::Publisher p_sensor("arduino_in_sensor", &sensor_data);




//### SUBSCRIBER ####

// ### ROS -> SERVO TORQUE

void messageMotorSingleIn( const projectx::MotorOut& msg) {
  if (msg.torque != -1) {
    writeServoTorque(msg.id, msg.torque);
  }
  else if (msg.pos != -1) {
    writeServoPos(msg.id, msg.pos);
  }
}

void writeServoTorque(int motor_id, int torque) {
  Dynamixel.torqueStatus(motor_id, torque);
}



// ### ROS -> SERVO POS

void messageMotorPosIn( const projectx::IntArray& msg) {
  for (int i = 0; i < 20; i++) {
    int pos = msg.deger[i];
    writeServoPos(i + 1, pos);
  }
}

void writeServoPos(int motor_id, int pos) {
  Dynamixel.move(motor_id, pos);
}


// ### ROS -> DATA CONTROL
void messageDataControl( const projectx::IntArray& msg) {
  ok_sensor = msg.deger[0];
  ok_gyro = msg.deger[1];
  ok_motor = msg.deger[2];
}

//
//// ### ROS -> OUT DATA LASER
//void messageOutDataLaser( const std_msgs::Int64& msg) {
//  int data = msg.data;
//  analogWrite(laser, data);
//}

// ### ROS -> OUT DATA BUZZER
void messageOutDataBuzzer( const std_msgs::Int64& msg) {
  int data = msg.data;
  digitalWrite(buzzer, data);
}

int temp_l1 = 0;
int temp_l2 = 0;
int temp_l3 = 0;

// ### ROS -> OUT DATA POWER LED
void messageOutDataPowerLed( const projectx::IntArray& msg) {
  int led_1 = msg.deger[0];
  int led_2 = msg.deger[1];
  int led_3 = msg.deger[2];
  
  if(temp_l1 != led_1) analogWrite(power_led_1, led_1);
  if(temp_l2 != led_2) analogWrite(power_led_2, led_2);
  if(temp_l3 != led_3) analogWrite(power_led_3, led_3);
  
  temp_l1 = led_1;
  temp_l2 = led_2;
  temp_l3 = led_3;
}




// ### SERVO -> ROS (PUBLISHER)

int motorId = 1;

void publishServo() {
  int pos = Dynamixel.readPosition(motorId);
  int pos2 = Dynamixel.ping(motorId);
  motorin_data.id = motorId;
  motorin_data.deger = pos;
  p_motor.publish(&motorin_data);

  motorId++;

  if (motorId == 21) motorId = 1;

}


void rgb(){
  unsigned int rgbColour[3];

  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(10);
    }
  }
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }
 

// ## SUBSCRIBER

ros::Subscriber<projectx::MotorOut> sub_motor_single("arduino_motor_out_single", messageMotorSingleIn);
ros::Subscriber<projectx::IntArray> sub_motor_pos("arduino_motor_out_array", messageMotorPosIn);
ros::Subscriber<projectx::IntArray> sub_data_control("arduino_data_control", messageDataControl);
ros::Subscriber<projectx::IntArray> sub_out_power_led("arduino_out_led", messageOutDataPowerLed);
ros::Subscriber<std_msgs::Int64> sub_out_buzzer("arduino_out_buzzer", messageOutDataBuzzer);


void setup() {

  //gyro_start();

  pinMode(buzzer, OUTPUT);
  pinMode(power_led_1, OUTPUT);
  pinMode(power_led_2, OUTPUT);
  pinMode(power_led_3, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  analogWrite(power_led_1, 40);  
  analogWrite(power_led_2, 20);
  analogWrite(power_led_3, 20);
  
  analogWrite(redPin, 240);
  analogWrite(greenPin, 230);
  analogWrite(bluePin, 230);
  

  dht.begin();
  
  nh.initNode();

  // Publisher
  nh.advertise(p_motor);
  nh.advertise(p_gyro);
  nh.advertise(p_sensor);

  // Subscriber
  nh.subscribe(sub_motor_pos);
  nh.subscribe(sub_motor_single);
  nh.subscribe(sub_data_control);
  nh.subscribe(sub_out_power_led);
//  nh.subscribe(sub_out_laser);
  nh.subscribe(sub_out_buzzer);

  Dynamixel.begin(1000000, 2);
  
  setColourRgb(10,10,10);

  delay(1000);
}

void loop() {
  //rgb();
  if (ok_sensor == 1) publishSensor();
  if (ok_gyro == 1) gyro_loop();
  if (ok_motor == 1) publishServo();

  nh.spinOnce();
  delay(1);
}

