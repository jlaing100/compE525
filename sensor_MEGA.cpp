#include "./sensor_MEGA.h"

#include <Arduino.h>

unsigned long previousMillis = 0;
const long interval = 1000; 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; 
    int sensorValue = analogRead(A0);
    float voltage = sensorValue * (5.0 / 1023.0);
    Serial.println(voltage);
  }

}
