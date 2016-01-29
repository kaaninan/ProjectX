#include <DynamixelSerial1.h>


int hiz = 110;

void setup() {
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(100);

  Dynamixel.moveSpeed(17, 520, hiz);
  delay(10);
  Dynamixel.moveSpeed(18, 520, hiz);
  delay(10);

  Dynamixel.moveSpeed(9, 500, hiz);
  delay(10);
  Dynamixel.moveSpeed(10, 500, hiz);
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

  Dynamixel.moveSpeed(1, random(400,600), hiz);
  Dynamixel.torqueStatus(1, true);
  Dynamixel.setCSlope(1, 1, 1);
  delay(2000);
  Dynamixel.torqueStatus(1, true);
  delay(10);
  Dynamixel.moveSpeed(2, 512, hiz);
  delay(10);

  Dynamixel.moveSpeed(3, 400, hiz);
  delay(10);
  Dynamixel.moveSpeed(4, 600, hiz);
  delay(10);

  Dynamixel.moveSpeed(5, 512, hiz);
  delay(10);
  Dynamixel.moveSpeed(6 , 512, hiz);
  delay(10);
}



void loop() {

  Dynamixel.moveSpeed(1, random(300,700), 1);


  Dynamixel.moveSpeedRW(15, 430, 150);
  delay(10);
  Dynamixel.moveSpeedRW(16, 430, 150);
  delay(10);

  Dynamixel.moveSpeedRW(13, 430, 350);
  delay(10);
  Dynamixel.moveSpeedRW(14, 430, 350);
  delay(10);

  Dynamixel.moveSpeedRW(11, 430, 40);
  delay(10);
  Dynamixel.moveSpeedRW(12, 430, 40);
  delay(10);

  Dynamixel.action();

  

}
