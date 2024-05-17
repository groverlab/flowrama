// FS2012-1100-NG flow sensor from Renesas
// 0.015 to 10 Standard Liters Per Minute (SLPM)

#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(115200);  // start serial for output
}

void loop() {
  Wire.requestFrom(7, 2);    // request 2 bytes from peripheral device #7

  while (Wire.available()) { // peripheral may send less than requested
    uint8_t b1 = Wire.read();
    uint8_t b2 = Wire.read();
    uint16_t val = (b1 << 8) | b2;
    float rate = val/1000.0;  // SLPM
    Serial.println(rate);         // print the character
  }
  delay(500);
}