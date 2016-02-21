int lazer = 6;

void setup(){
  pinMode(lazer, OUTPUT);
}

void loop(){
  for(int a = 1; a < 255; a++){
    analogWrite(lazer, a);
    delay(100);
  }

}

