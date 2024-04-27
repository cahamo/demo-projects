/*
  TTP223 Touch Button Demo

  Lights a LED when the touch button is touched. Uses Arduino Uno.

  By cahamo, 27 Apr 2024

  Public domain

  Wiring:

    TTP223 VCC to breadboard 5V rail
    TTP223 GND to breadboard ground rail
    TTP223 I/O to Uno pin 2
    Uno pin 4 to LED anode via 470 ohm; resistor
    LED cathode to breadboard ground rail
    Uno 5V pin to breadboard 5V rail
    Uno GND to breadboard GND rail
*/

#include <Arduino.h>

#define TOUCH_PIN 2
#define LED_PIN 4

void setup() {
  pinMode(TOUCH_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(TOUCH_PIN) ==  HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("TOUCHING");
  }
  else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("OFF");
  }
  delay(100);
}
