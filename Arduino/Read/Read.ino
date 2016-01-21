#include <DynamixelSerial1.h>

int Temperature, Voltage, Position, Load,Moving;

void setup() {
  Serial.begin(115200);              // Begin Serial Comunication
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(100);
}

int i = 1;

void loop() {
  for (int i = 1; i < 21; i++) {
    Temperature = Dynamixel.readTemperature(i); // Request and Print the Temperature
    Voltage = Dynamixel.readVoltage(i);         // Request and Print the Voltage
    Position = Dynamixel.readPosition(i);       // Request and Print the Position


    Serial.print(i);
    Serial.print(" -> TEMP: ");   // Print the variables in the Serial Monitor
    Serial.print(Temperature);
    Serial.print("  Voltage: ");
    Serial.print(Voltage);
    Serial.print("  Position: ");
    Serial.println(Position);

    delay(1000);
  }
  
  delay(1500);

}
