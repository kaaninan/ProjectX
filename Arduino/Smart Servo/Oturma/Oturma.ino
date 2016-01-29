#include <DynamixelSerial1.h>


int hiz = 10;

void setup() {
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(100);

  Dynamixel.moveSpeed(2, 520, hiz);
  delay(10);
  Dynamixel.moveSpeed(7, 520, hiz);
  delay(10);

  Dynamixel.moveSpeed(5, 500, hiz);
  delay(10);
  Dynamixel.moveSpeed(10, 500, hiz);
  delay(10);
 
  Dynamixel.moveSpeed(11, 512, hiz);
  delay(10);
  Dynamixel.moveSpeed(12, 512, hiz);
  delay(10);

  Dynamixel.moveSpeed(15, 512, hiz);
  delay(10);
  Dynamixel.moveSpeed(16, 512, hiz);
  delay(10);

  // KOL

  Dynamixel.moveSpeed(13, 512, hiz);
  delay(10);
  Dynamixel.moveSpeed(14, 512, hiz);
  delay(10);

  Dynamixel.moveSpeed(17, 400, hiz);
  delay(10);
  Dynamixel.moveSpeed(19, 600, hiz);
  delay(10);

  Dynamixel.moveSpeed(18, 512, hiz);
  delay(10);
  Dynamixel.moveSpeed(20 , 512, hiz);
  delay(10);
}



void loop() {


  Dynamixel.moveSpeedRW(1, 244, 150);
  delay(10);
  Dynamixel.moveSpeedRW(6, 244, 150);
  delay(10);

  Dynamixel.moveSpeedRW(3, 320, 200);
  delay(10);
  Dynamixel.moveSpeedRW(8, 320, 200);
  delay(10);

  Dynamixel.moveSpeedRW(4, 380, 50);
  delay(10);
  Dynamixel.moveSpeedRW(9, 380, 50);
  delay(10);

  Dynamixel.action();



  delay(1000000000000);

}
