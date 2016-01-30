#include <DynamixelSerial1.h>



int hiz = 500;

void setup() {
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(500);


  Dynamixel.moveSpeed(17, 512, hiz);
  delay(10);
  Dynamixel.moveSpeed(18, 512, hiz);
  delay(10);

  Dynamixel.moveSpeed(9, 480, hiz);
  delay(10);
  Dynamixel.moveSpeed(10, 520, hiz);
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


  Dynamixel.moveSpeedRW(15, 500, hiz);
  delay(50);
  Dynamixel.moveSpeedRW(16, 500, hiz);
  delay(50);

  Dynamixel.moveSpeedRW(13, 542, hiz);
  delay(50);
  Dynamixel.moveSpeedRW(14, 542, hiz);
  delay(50);

  Dynamixel.moveSpeedRW(11, 495, hiz);
  delay(50);
  Dynamixel.moveSpeedRW(12, 495, hiz);
  delay(50);

  Dynamixel.action();


  delay(10000000000);

}
