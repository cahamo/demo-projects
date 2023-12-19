/*
  Rotary Encoder Demo
  Demonstrates operation of Rotary Encoder
  Displays results on Serial Monitor
  Modified for Bodnar BBI-32 encoders by cahamo from DroneBot Workshop 2019 code: https://dronebotworkshop.com
*/

#include <Arduino.h>

// Rotary Encoder Inputs
#define inputS1 4
#define inputS2 5
#define inputKEY 3

// LED Outputs
#define ledCW 8
#define ledCCW 9
#define ledKEY 10


int counter = 0;
int currentStateS1;
int previousStateS1;

String encdir ="";

void setup() {

  // Set encoder pins as inputs
  pinMode(inputS1,INPUT);
  pinMode(inputS2,INPUT);
  pinMode(inputKEY,INPUT);

  // Set LED pins as outputs
  pinMode(ledCW,OUTPUT);
  pinMode(ledCCW,OUTPUT);
  pinMode(ledKEY, OUTPUT);

  // Setup Serial Monitor
  Serial.begin(9600);

  // Read the initial state of inputS1
  // Assign to previousStateS1 variable
  previousStateS1 = digitalRead(inputS1);

}

void loop() {

  // Check for switch being pressed: switch goes LOW when pressed
  if (digitalRead(inputKEY) == LOW) {
    Serial.println("Switch pressed");
    digitalWrite(ledKEY, HIGH);
  }
  else {
    digitalWrite(ledKEY, LOW);
  }


  // Read the current state of inputS1
  currentStateS1 = digitalRead(inputS1);

   // If the previous and the current state of the inputS1 are different then a pulse has occured
  if (currentStateS1 != previousStateS1) {

    // If the inputS2 state is different than the inputS1 state then
    // the encoder is rotating counterclockwise
    if (digitalRead(inputS2) != currentStateS1) {
      counter --;
      encdir ="CCW";
      digitalWrite(ledCW, LOW);
      digitalWrite(ledCCW, HIGH);

    } else {
      // Encoder is rotating clockwise
      counter ++;
      encdir ="CW";
      digitalWrite(ledCW, HIGH);
      digitalWrite(ledCCW, LOW);

    }
    Serial.print("Direction: ");
    Serial.print(encdir);
    Serial.print(" -- Value: ");
    Serial.println(counter);
  }
  // Update previousStateS1 with the current state
  previousStateS1 = currentStateS1;

}
