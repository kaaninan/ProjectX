// VALUE (with Default Values)
float temp = -1;
float temp_out = -1;
float humidity = -1;
int ldr = -1;
int uzaklik = -1;



// MAIN

void publishSensor() {
  read_uzaklik();
  read_ldr();
  read_temp();
  read_temp_out();

  sensor_data.ldr = ldr;
  sensor_data.temp = temp;
  sensor_data.temp_out = temp_out;
  sensor_data.humidity = humidity;
  sensor_data.dis = uzaklik;

  p_sensor.publish(&sensor_data);
}




// FUNCTIONS

void read_uzaklik() {
  uzaklik = sharp.distance();
}


void read_ldr() {
  ldr = analogRead(ldr_pin);
}

void read_temp() {
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius, fahrenheit;

  if ( !temp_pin.search(addr)) {
    temp_pin.reset_search();
    return;
  }

  temp_pin.reset();
  temp_pin.select(addr);
  temp_pin.write(0x44, 1);

  present = temp_pin.reset();
  temp_pin.select(addr);
  temp_pin.write(0xBE);
  for ( i = 0; i < 9; i++) {
    data[i] = temp_pin.read();
  }
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3;
    if (data[7] == 0x10) {
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    if (cfg == 0x00) raw = raw & ~7;
    else if (cfg == 0x20) raw = raw & ~3;
    else if (cfg == 0x40) raw = raw & ~1;
  }
  temp = (float)raw / 16.0;
}


void read_temp_out(){
  humidity = dht.readHumidity();
  temp_out = dht.readTemperature();
}
