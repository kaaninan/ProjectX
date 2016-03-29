#include <DynamixelSerial1.h>


int hiz = 110;

int pin = 9;

void setup() {
  pinMode(pin, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(100);

  Dynamixel.moveSpeed(17, 512, hiz);
  delay(10);
  Dynamixel.moveSpeed(18, 530, hiz);
  delay(10);

  Dynamixel.moveSpeed(9, 500, hiz);
  delay(10);
  Dynamixel.moveSpeed(10, 524, hiz);
  delay(10);
 
  Dynamixel.moveSpeed(7, 512, hiz);
  delay(10);
  Dynamixel.moveSpeed(8, 512, hiz);
  delay(10);

  Dynamixel.moveSpeed(19, 512, hiz);
  delay(10);
  Dynamixel.moveSpeed(20, 512, hiz);
  delay(10);

  // KOL

  Dynamixel.moveSpeed(1, 512, hiz);
  delay(10);
  Dynamixel.moveSpeed(2, 512, hiz);
  delay(10);

  Dynamixel.moveSpeed(3, 450, hiz);
  delay(10);
  Dynamixel.moveSpeed(4, 520, hiz);
  delay(10);

  Dynamixel.moveSpeed(5, 512, hiz);
  delay(10);
  Dynamixel.moveSpeed(6 , 512, hiz);
  delay(10);
}



void loop() {


  Dynamixel.moveSpeedRW(15, 430, 150);
  delay(10);
  Dynamixel.moveSpeedRW(16, 430, 150);
  delay(10);

  Dynamixel.moveSpeedRW(13, 440, 350);
  delay(10);
  Dynamixel.moveSpeedRW(14, 440, 350);
  delay(10);

  Dynamixel.moveSpeedRW(11, 410, 40);
  delay(10);
  Dynamixel.moveSpeedRW(12, 410, 40);
  delay(10);

  Dynamixel.action();

    analogWrite(6, 20);
  analogWrite(4, 10);
  analogWrite(pin, 200);

//  digitalWrite(8, 1);
//  digitalWrite(11,1);
//  digitalWrite(12,1);

  analogWrite(8,  215);
  analogWrite(11, 205);
  analogWrite(12, 205);

  

}
