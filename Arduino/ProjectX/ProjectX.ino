// GYRO
#include <Wire.h>
#include <L3G.h>
#include <LSM303.h>

// NRF
#include <SPI.h>
#include <nRF24L01p.h>

// SERVO
#include <DynamixelSerial1.h>

// SENSOR
#include <OneWire.h>
#include <SharpIR.h>
#include <DHT.h>
#include <SoftwareSerial.h>

// ROS
#include <ros.h>
#include <std_msgs/Int64.h>
#include <std_msgs/String.h>
#include <projectx/Hash.h>
#include <projectx/MotorIn.h>
#include <projectx/MotorOut.h>
#include <projectx/IntArray.h>
#include <projectx/Gyro.h>
#include <projectx/Sensor.h>

ros::NodeHandle  nh;


// ################################         PIN         ################################ //

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

// ILETISIM
nRF24L01p transmitter(53, 49); //CSN,CE


// DATA CONTROL (for loop)
int ok_sensor = 0;
int ok_motor = 0;
int ok_gyro = 0;



// ################################         PUBLISHER LIST         ################################ //

projectx::Hash motorin_data;
ros::Publisher p_motor("arduino_in_motor", &motorin_data);

projectx::Gyro gyro_data;
ros::Publisher p_gyro("arduino_in_gyro", &gyro_data);

projectx::Sensor sensor_data;
ros::Publisher p_sensor("arduino_in_sensor", &sensor_data);

std_msgs::String nrf_gelen;
ros::Publisher p_nrf("arduino_incoming_nrf", &nrf_gelen);

std_msgs::String gsm_gelen;
ros::Publisher p_gsm("arduino_incoming_gsm", &gsm_gelen);

std_msgs::String bt_gelen;
ros::Publisher p_bt("arduino_incoming_bt", &bt_gelen);




// ################################         SUBSCRIBER         ################################ //

// ROS -> SERVO TORQUE

void msgMotorSingleIn( const projectx::MotorOut& msg) {
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

void msgMotorArrayIn( const projectx::IntArray& msg) {
  for (int i = 0; i < 20; i++) {
    int pos = msg.deger[i];
    writeServoPos(i + 1, pos);
  }
}

void writeServoPos(int motor_id, int pos) {
  Dynamixel.moveSpeed(motor_id, pos, 900);
  delay(5);
}




// ### ROS -> DATA CONTROL

void messageDataControl( const projectx::IntArray& msg) {
  ok_sensor = msg.deger[0];
  ok_gyro = msg.deger[1];
  ok_motor = msg.deger[2];
}



void msgCallbackBuzzer( const std_msgs::Int64& msg) {
  int data = msg.data;
  digitalWrite(buzzer, data);
}

void msgCallbackRgb( const projectx::IntArray& msg) {
  setColourRgb(msg.deger[0], msg.deger[1], msg.deger[2]);
}



// POWER LED

void msgCallbackLed1( const std_msgs::Int64& msg) {
  int led = msg.data;
  analogWrite(power_led_1, led);
}
void msgCallbackLed2( const std_msgs::Int64& msg) {
  int led = msg.data;
  analogWrite(power_led_2, led);
}
void msgCallbackLed3( const std_msgs::Int64& msg) {
  int led = msg.data;
  analogWrite(power_led_3, led);
}


// ### ROS -> NRF DATA
void msgCallbackNrf( const std_msgs::String& msg) {
}

// ### ROS -> Bluetooth DATA
void msgCallbackBt( const std_msgs::String& msg) {
}

// ### ROS -> GSM DATA
void msgCallbackGsm( const std_msgs::String& msg) {
}





// ################################         PUBLISHER         ################################ //

int motorId = 1;
int pos = 0;

void publishServo() {
  pos = Dynamixel.readPosition(motorId);
  
  motorin_data.id = motorId;
  motorin_data.deger = pos;
  p_motor.publish(&motorin_data);
  
  motorId++;
  if (motorId == 21) motorId = 1;
}










// ################################         SUBSCRIBER LIST         ################################ //


// Motor
ros::Subscriber<projectx::MotorOut> sub_motor_single("arduino_motor_out_single", msgMotorSingleIn);
ros::Subscriber<projectx::IntArray> sub_motor_array("arduino_motor_out_array", msgMotorArrayIn);

// Out
ros::Subscriber<std_msgs::Int64> sub_out_led1("arduino_out_led_1", msgCallbackLed1);
ros::Subscriber<std_msgs::Int64> sub_out_led2("arduino_out_led_2", msgCallbackLed2);
ros::Subscriber<std_msgs::Int64> sub_out_led3("arduino_out_led_3", msgCallbackLed3);
ros::Subscriber<std_msgs::Int64> sub_out_buzzer("arduino_out_buzzer", msgCallbackBuzzer);
ros::Subscriber<projectx::IntArray> sub_out_rgb("arduino_out_rgb", msgCallbackRgb);

// Iletisim
ros::Subscriber<std_msgs::String> sub_out_nrf("arduino_send_nrf", msgCallbackNrf);
ros::Subscriber<std_msgs::String> sub_out_bt("arduino_send_bt", msgCallbackBt);
ros::Subscriber<std_msgs::String> sub_out_gsm("arduino_send_gsm", msgCallbackGsm);

// Data Control
ros::Subscriber<projectx::IntArray> sub_data_control("arduino_data_control", messageDataControl);




// ################################         SETUP        ################################ //

void setup() {

  gyro_start();

  // PIN MODE
  pinMode(buzzer, OUTPUT);
  pinMode(power_led_1, OUTPUT);
  pinMode(power_led_2, OUTPUT);
  pinMode(power_led_3, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);


  // DATA CONTROL (for loop)
  ok_sensor = 0;
  ok_motor = 0;
  ok_gyro = 0;

  // SENSOR BEGIN
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  transmitter.channel(90);
  transmitter.TXaddress("Artur");
  transmitter.init();
  dht.begin();
  Dynamixel.begin(1000000, 2);


  // AYDINLATMA
  analogWrite(power_led_1, 40);
  analogWrite(power_led_2, 20);
  analogWrite(power_led_3, 20);

  analogWrite(redPin, 240);
  analogWrite(greenPin, 230);
  analogWrite(bluePin, 230);


  nh.initNode();

  // Publisher
  nh.advertise(p_motor);
  nh.advertise(p_gyro);
  nh.advertise(p_sensor);
  nh.advertise(p_gsm);
  nh.advertise(p_nrf);
  nh.advertise(p_bt);

  // Subscriber
  nh.subscribe(sub_motor_array);
  nh.subscribe(sub_motor_single);
  nh.subscribe(sub_data_control);
  nh.subscribe(sub_out_led1);
  nh.subscribe(sub_out_led2);
  nh.subscribe(sub_out_led3);
  nh.subscribe(sub_out_rgb);
  nh.subscribe(sub_out_buzzer);
  nh.subscribe(sub_out_nrf);
  nh.subscribe(sub_out_gsm);
  nh.subscribe(sub_out_bt);

  delay(1000);
}



// ################################         LOOP        ################################ //


void loop() {
  
  if (ok_sensor == 1) publishSensor();
  if (ok_gyro == 1) gyro_loop();
  if (ok_motor == 1) publishServo();

  nh.spinOnce();
  delay(1);
}

