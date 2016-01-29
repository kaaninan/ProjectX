#include <DynamixelSerial1.h>


int hiz = 250;

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
  delay(1000);

  

  
}


// VARSAYILAN OTURMA
int a1 = 430;
int a2 = 570;
int a3 = 430;


void loop() {

  // AYAKTA DUR

  Dynamixel.moveSpeedRW(1, a1, 150);
  delay(10);
  Dynamixel.moveSpeedRW(6, a1, 150);
  delay(10);
  Dynamixel.moveSpeedRW(3, a2, 350);
  delay(10);
  Dynamixel.moveSpeedRW(8, a2, 350);
  delay(10);
  Dynamixel.moveSpeedRW(4, a3, 140);
  delay(10);
  Dynamixel.moveSpeedRW(9, a3, 140);
  delay(10);
  Dynamixel.moveSpeedRW(10, 512, hiz);
  delay(10);
  Dynamixel.moveSpeedRW(7, 512, hiz);
  delay(10);

  Dynamixel.action();
  delay(1000);



  // Bir adım at (SAĞ)


  Dynamixel.moveSpeedRW(1, 450, hiz);
  delay(10);
  Dynamixel.moveSpeedRW(3, 550, hiz);
  delay(10);
  Dynamixel.moveSpeedRW(4, 380, hiz);
  delay(10);

  Dynamixel.moveSpeedRW(6, a1, hiz);
  delay(10);
  Dynamixel.moveSpeedRW(8, a2, hiz);
  delay(10);
  Dynamixel.moveSpeedRW(9, 480, hiz);
  delay(10);
  Dynamixel.moveSpeedRW(10, 520, hiz);
  delay(10);
  Dynamixel.moveSpeedRW(7, 520, hiz);
  delay(10);


  Dynamixel.action();

  delay(1500);

}
