/* NOTLAR
 *  
 *  - Motorlardan gelen voltaj, sıcaklık vs. publisher ile yollanıyor.
 *  
 */


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
#include <projectx/MotorOutSingleArray.h>
#include <projectx/Gyro.h>
#include <projectx/Sensor.h>

ros::NodeHandle  nh;



// ROS PUBLISHER
projectx::MotorIn motorin_data;
ros::Publisher p_motor("arduinoMotorIncoming", &motorin_data);

projectx::Gyro gyro_data;
ros::Publisher p_gyro("arduinoGyroIncoming", &gyro_data);

projectx::Sensor sensor_data;
ros::Publisher p_sensor("arduinoSensorIncoming", &sensor_data);






// ### ROS -> SERVO (SUBSCRIBER)

// INCOMING DATA
void messageMotorIn( const projectx::MotorOut& msg) {
  
  int id = msg.id;
  int pos = msg.pos;
  int speed = msg.speed;
  int torque = msg.torque;
  int rw = msg.rw;
  int action = msg.action;

  writeServo(id, pos, speed, torque, rw, action);
}

ros::Subscriber<projectx::MotorOut> sub_motor("arduinoMotorOutgoing", messageMotorIn);

void writeServo(int motor_id, int pos, int speed, int torque, int rw, int action) {
  
  // Torque Status Ayarla
  // Action == 1 -> Komut Vert
  // ELSE -> RW == 1 -> moveRW
  //      -> RW == 0 -> move
  
  if(action == 1){
    Dynamixel.action();
  }else{
    if(rw == 1){ Dynamixel.moveSpeedRW(motor_id, pos, speed);  }
    else{ Dynamixel.moveSpeed(motor_id, pos, speed);  }  
  }
  
  Dynamixel.torqueStatus(motor_id, torque);
}






// ### ROS -> SERVO (SUBSCRIBER) ARRAY

// INCOMING DATA
void messageMotorInArray( const projectx::MotorOutSingleArray& msg) {
  digitalWrite(4, HIGH);
  
  for(int i = 1; i < 21; i++){
    int id = msg.id[i];
    int pos = msg.pos[i];
  
    writeServoArray(id, pos);
  }
}

ros::Subscriber<projectx::MotorOutSingleArray> sub_motor_array("arduinoMotorOutgoingArray", messageMotorInArray);

void writeServoArray(int motor_id, int pos) {
  
  digitalWrite(4, HIGH);
  
  Dynamixel.moveSpeed(motor_id, pos, 0);
  
  Dynamixel.torqueStatus(motor_id, 1);
}







// ### SERVO -> ROS (PUBLISHER)

// Motorların Sıcaklık, Voltaj ve Posizyon Bilgisi (Read)
int motor_temp[30];
int motor_pos[30];
int motor_volt[30];
int motor_torque[30];

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





void setup()
{

  //gyro_start();

  nh.initNode();

  // Publisher
  nh.advertise(p_motor);
  nh.advertise(p_gyro);
  nh.advertise(p_sensor);

  // Subscriber
  nh.subscribe(sub_motor_array);
  nh.subscribe(sub_motor);

  pinMode(4, OUTPUT);
  
  digitalWrite(4,HIGH);
  delay(400);
  digitalWrite(4,LOW);

  Dynamixel.begin(1000000, 2);
  
  delay(1000);
}

void loop()
{
  //gyro_loop();
  //read_sensor();
  //publishServo();
  nh.spinOnce();
  delay(1);
}



                                                                                   

