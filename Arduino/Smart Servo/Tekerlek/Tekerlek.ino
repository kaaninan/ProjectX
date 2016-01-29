#include <DynamixelSerial1.h>

void setup(){
Dynamixel.begin(1000000,2);  // Inicialize the servo at 1Mbps and Pin Control 2
delay(1000);

  Dynamixel.setEndless(1,ON);
  delay(10);
  Dynamixel.setEndless(2,ON);
  delay(10);
  Dynamixel.setEndless(3,ON);
  delay(10);
  Dynamixel.setEndless(4,ON);
  delay(10);
  Dynamixel.setEndless(5,ON);
  delay(10);
  Dynamixel.setEndless(6,ON);
  delay(10);


  Dynamixel.ledStatus(1,ON);
  delay(10);
  Dynamixel.ledStatus(2,ON);
  delay(10);
  Dynamixel.ledStatus(3,ON); 
  delay(10);
  Dynamixel.ledStatus(4,ON);
  delay(10);
  Dynamixel.ledStatus(5,ON);
  delay(10);
  Dynamixel.ledStatus(6,ON);
  delay(10);
}

void loop(){

  delay(100);
  Dynamixel.turn(1,RIGTH,1000);
  delay(100);
  Dynamixel.turn(2,RIGTH,1000);
  delay(100);
  Dynamixel.turn(3,RIGTH,1000);
  delay(100);
  Dynamixel.turn(4,RIGTH,1000);
  delay(100);
  Dynamixel.turn(5,RIGTH,1000);
  delay(100);
  Dynamixel.turn(6,RIGTH,1000);

  delay(5000);

  delay(100);
  Dynamixel.turn(1,LEFT,1000);
  delay(100);
  Dynamixel.turn(2,LEFT,1000);
  delay(100);
  Dynamixel.turn(3,LEFT,1000);
  delay(100);
  Dynamixel.turn(4,LEFT,1000);
  delay(100);
  Dynamixel.turn(5,LEFT,1000);
  delay(100);
  Dynamixel.turn(6,LEFT,1000);

  delay(5000);

  
  delay(10);
  Dynamixel.ledStatus(1,ON);
  delay(10);
  Dynamixel.ledStatus(2,ON);
  delay(10);
  Dynamixel.ledStatus(3,ON); 
  delay(10);
  Dynamixel.ledStatus(4,ON);
  delay(10);
  Dynamixel.ledStatus(5,ON);
  delay(10);
  Dynamixel.ledStatus(6,ON);
  delay(10);


}
