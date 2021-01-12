#include <Wire.h>

const uint32_t ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(0x8);

  Wire.onReceive(receiveEvent);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}


void receiveEvent(int32_t howMany){
  while (Wire.available()){
    char c = Wire.read();
    digitalWrite(ledPin, c);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}
