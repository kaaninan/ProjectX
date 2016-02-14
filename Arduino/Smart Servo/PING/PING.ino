#include <DynamixelSerial1.h>

void setup() {
  Serial.begin(115200);
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(1000);
}

void loop() {

  Serial.println("Start");

  for (int i = 1; i < 21; i++) {
    int a = Dynamixel.ping(1);
    Serial.print("ID: ");
    Serial.print(i);
    Serial.print(" -> ");
    Serial.println(a);
    delay(1);
  }

  delay(500);

  Serial.println("Finish");

  Dynamixel.ledStatus(2, ON);

  while (1) {}

}
