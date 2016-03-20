int pin = 9;

void setup() {
  pinMode(pin, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  analogWrite(6, 20);
  analogWrite(4, 10);
  analogWrite(pin, 200);

//  digitalWrite(8, 1);
//  digitalWrite(11,1);
//  digitalWrite(12,1);

  analogWrite(8,  235);
  analogWrite(11, 235);
  analogWrite(12, 235);
}
