// Program to demonstrate use of a MAX7291 controlled LED matrix
//
// Adapted from example code provided with the Majic Designs MD_MAX72XX library:
//   https://github.com/MajicDesigns/MD_MAX72XX
//
// Modified by cahamo 2024-04-23:
//   Changed HARDWARE_TYPE & MAX_DEVICES for 4 panel FC16 display
//   Changed output text
//   Converted for PlatformIO
//
// LED matrix comprises 4 linked 8x8 panels
//
// Uno is powered via its USB socket
// LED matrix is powered from a separate 5V power supply
//
// Pin connections:
//   Uno pin 10 (SPI CS pin) to matrix CS pin
//   Uno pin 11 (SPI COPI/MOSI pin) to matrix DIN pin
//   Uno pin 13 (SPI CLK pin) to matrix CLK pin
//   Uno GND pin to maxtrix GND pin
//   Power supply 5V to matrix VCC pin
//   Power supply ground to matrix GND pin
//
//   Note that the Uno's CIPO/MISO pin 12 is not used since communication is one way

#include <Arduino.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4   // four 8x8 segments

#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Hardware SPI connection
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
// MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup(void)
{
  P.begin();
}

void loop(void)
{
  if (P.displayAnimate())
    P.displayText("<Hello>", PA_CENTER, P.getSpeed(), 1000, PA_SCROLL_DOWN, PA_SCROLL_DOWN);
}
