#include <DynamixelSerial1.h>


int hiz = 110;

void setup() {
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(100);

  Dynamixel.moveSpeed(17, 508, hiz);
  delay(10);
  Dynamixel.moveSpeed(18, 508, hiz);
  delay(10);

  Dynamixel.moveSpeed(9, 512, hiz);
  delay(10);
  Dynamixel.moveSpeed(10, 512, hiz);
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

  Dynamixel.moveSpeed(1, 387, hiz);
  delay(10);
  Dynamixel.moveSpeed(2, 641, hiz);
  delay(10);

  Dynamixel.moveSpeed(3, 460, hiz);
  delay(10);
  Dynamixel.moveSpeed(4, 563, hiz);
  delay(10);

  Dynamixel.moveSpeed(5, 452, hiz);
  delay(10);
  Dynamixel.moveSpeed(6 , 572, hiz);
  delay(10);
}



void loop() {

  Dynamixel.moveSpeedRW(15, 531, 150);
  delay(10);
  Dynamixel.moveSpeedRW(16, 488, 150);
  delay(10);

  Dynamixel.moveSpeedRW(13, 498, 350);
  delay(10);
  Dynamixel.moveSpeedRW(14, 514, 350);
  delay(10);

  Dynamixel.moveSpeedRW(11, 494, 40);
  delay(10);
  Dynamixel.moveSpeedRW(12, 521, 40);
  delay(10);

  Dynamixel.action();

  

}
