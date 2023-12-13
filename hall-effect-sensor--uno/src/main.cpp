/*
  Arduino Uno sketch to demonstrate the use of a bare Hall effect sensor
  and a Hall effect sensor module.

  Copyright (c) 2023, Peter Johnson (delphidabbler).
  MIT license

  Pin connections:
  * Arduino 5V to 5v/VCC pins of module and sensor
  * Arduino GND to -ve pins of module and sensor
  * Arduino D8 to bare sensor signal pin
  * Arduino D9 to module signal pin
  * Arduino D12 to bare sensor LED anode
  * Arduino D11 to module LED anode
  * Both LED cathodes via 470ohm resistors to Arduino GND
  * Bare sensor signal pin via 5.1Kohm resitor to Arduino 5V
*/

#include <Arduino.h>

// Pins connected to sensor pins
#define HALL_EFFECT_SENSOR_PIN 8
#define HALL_EFFECT_MODULE_PIN 9
// Pins connected to feedback LED
#define SENSOR_LED_PIN 12
#define MODULE_LED_PIN 11

void setup() {
  // Set pin modes
  pinMode(HALL_EFFECT_SENSOR_PIN, INPUT);
  pinMode(HALL_EFFECT_MODULE_PIN, INPUT);
  pinMode(SENSOR_LED_PIN, OUTPUT);
  pinMode(MODULE_LED_PIN, OUTPUT);
  // Switch off LEDs
  digitalWrite(SENSOR_LED_PIN, LOW);
  digitalWrite(MODULE_LED_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  // NOTE: Hall effect sensors output LOW when magnet sensed, HIGH when not
  // We flip reading to get HIGH when magnet sensed
  int sensorState = ! digitalRead(HALL_EFFECT_SENSOR_PIN);
  int moduleState = ! digitalRead(HALL_EFFECT_MODULE_PIN);
  Serial.print(F("Module = "));
  Serial.print(moduleState);
  Serial.print(F(" | Sensor = "));
  Serial.println(sensorState);
  digitalWrite(SENSOR_LED_PIN, sensorState);
  digitalWrite(MODULE_LED_PIN, moduleState);
  delay(333);
}
