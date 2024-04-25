// Arduino Uno code to exercise a 12 LED RGB "neopixel" ring
// Greatly modified from code by Elon on Medium - https://tinyurl.com/3bc2fbb6

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LONG_PAUSE 100
#define SHORT_PAUSE 30

#define LED_PIN    7
#define LED_COUNT 12

Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  ring.begin();           
  ring.show();            
  ring.setBrightness(50); 
  for(int i = 0; i < ring.numPixels(); i++){
    ring.setPixelColor(i, 255, 0, 0);   // red
    ring.show();
    delay(LONG_PAUSE);
  }
  for(int i = 0; i < ring.numPixels(); i++){
    ring.setPixelColor(i, 0, 255, 0);   // green
    ring.show();
    delay(LONG_PAUSE);
  }
  for(int i = 0; i < ring.numPixels(); i++){
    ring.setPixelColor(i, 0, 0, 255);   // blue
    ring.show();
    delay(LONG_PAUSE);
  }
  for(int i = 0; i < ring.numPixels(); i++){
    ring.setPixelColor(i, 255, 255, 0);   // yellow-ish
    ring.show();
    delay(LONG_PAUSE);
  }
  for(int i = 0; i < ring.numPixels(); i++){
    ring.setPixelColor(i, 255, 0, 255);   // magenta-ish
    ring.show();
    delay(LONG_PAUSE);
  }
  for(int i = 0; i < ring.numPixels(); i++){
    ring.setPixelColor(i, 0, 255, 255);   // cyan-ish
    ring.show();
    delay(LONG_PAUSE);
  }
  for(int i = 0; i < ring.numPixels(); i++){
    ring.setPixelColor(i, 255, 255, 255);   // white
    ring.show();
    delay(LONG_PAUSE);
  }
}

void loop() {
  for(int i = 0; i < ring.numPixels(); i++){
    ring.setPixelColor(i, random(255), random(255), random(255));
    ring.show();
    delay(LONG_PAUSE);
  }
  for(int i = ring.numPixels()-1; i >= 0; i--){
    ring.setPixelColor(i, 0, 0, 0, 0);
    ring.show();
    delay(SHORT_PAUSE);
  }
  delay(2* LONG_PAUSE);
}
