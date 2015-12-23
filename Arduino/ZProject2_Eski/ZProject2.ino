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

// ROS PUBLISHER
projectx::MotorIn motorin_data;
ros::Publisher p_motor("arduinoMotorIncoming", &motorin_data);

projectx::Gyro gyro_data;
ros::Publisher p_gyro("arduinoGyroIncoming", &gyro_data);

projectx::Sensor sensor_data;
ros::Publisher p_sensor("arduinoSensorIncoming", &sensor_data);






// MOTOR

projectx::MotorOut motorout_data;

// Gelen Motor Açılarını Kaydet
// Açı Değişirse Motora Komut Yolla
int motorNo[30];
int motorAci[30];


// Motorların Sıcaklık, Voltaj ve Posizyon Bilgisi (Read)
int motor_temp = -1;
int motor_pos = -1;
int motor_volt = -1;
int motor_load = -1;


// INCOMING DATA
void messageMotorIn( const projectx::MotorOut& msg) {
  // Gelen veriyi kaydet (Motor açısı)
  int id = msg.id[1];
  int value = msg.value[1];
  int hiz = msg.hiz[1];
  int rw = msg.rw[1];

  // Eski açıyı kontrol et
  int old_value = motorAci[id];

  if(old_value != value){
    writeServo(id, value, hiz, rw);
    motorAci[id] = value;
  }
}



// ROS
ros::Subscriber<projectx::MotorOut> sub_motor("arduinoMotorOutgoing", messageMotorIn);



// OUTGOING DATA
void messageMotorOut( const projectx::MotorIn& msg) {

  motorin_data.id[1] = 0;
  motorin_data.temp[1] = 0;
  motorin_data.voltage[1] = 0;
  motorin_data.pos[1] = 0;
  motorin_data.load[1] = 0;
}





void motorNoTanimla() {
  for (int i = 0; i < 21; i++) {
    motorNo[i] = i;
    motorAci[i] = -1; // Ilk deger icin
  }
}

void writeServo(int motor_id, int value, int hiz, int rw) {
  if (rw == 0) {
    Dynamixel.moveSpeed(motor_id, value, hiz);
  } else {
    Dynamixel.moveSpeedRW(motor_id, value, hiz);
  }
}

void writeAction() {
  Dynamixel.action();
}




void readServo(int id) {
  motor_temp = Dynamixel.readTemperature(id);
  motor_volt = Dynamixel.readVoltage(id);
  motor_pos = Dynamixel.readPosition(id);
  motor_load = Dynamixel.readLoad(id);
}





void setup()
{

  //gyro_start();

  // Motor ID'lerini diziye yaz ve varsayılan aci degeri (0) ayarla
  //motorNoTanimla();
  
  nh.initNode();
  nh.advertise(p_motor);
  nh.advertise(p_gyro);
  nh.advertise(p_sensor);
  nh.subscribe(sub_motor);
  
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
