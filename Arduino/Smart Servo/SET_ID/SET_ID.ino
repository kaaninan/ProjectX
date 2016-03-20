#include <DynamixelSerial1.h>

void setup() {
  Serial.begin(9600);
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(1000);
}

int yap = 11;

void loop() {

  Dynamixel.setID(1,yap);

  delay(1000);

  Serial.println("Finish");

  Dynamixel.ledStatus(yap, ON);

  while (1) {}

}
