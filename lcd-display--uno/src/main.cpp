/*
  LCD "Jabberwocky" demo

  Demonstrates the use a LCD display to display the poem Jabberwocky by
  Lewis Carroll. Uses an Arduino Uno or clone.

  Uses the Arduino LiquidCrystal library that works with all LCD displays that
  are compatible with the Hitachi HD44780 driver using the usual 16 pin
  interface.

  By cahamo, 26 Apr 2024 (https://cahamo.delphidabbler.com)

  LCD Pinouts:
    VSS or GND    GND
    VDD or VCC    5V
    VO            Wiper of 10k potentiometer: pot has ends attached to Uno 5V & GND
    RS            Uno pin 12
    RW            GND
    E             Uno pin 11
    D0            Not connected
    D1            Not connected
    D2            Not connected
    D3            Not connected
    D4            Uno pin 5
    D5            Uno pin 4
    D6            Uno pin 3
    D7            Uno pin 2
    A or LED+     5V via 220 ohm resistor
    K or LED-     GND

  This example code is in the public domain.
*/

#include <Arduino.h>
#include <LiquidCrystal.h>

// Set COLUMNS to the number of columns on the display
#define COLUMNS 20
// Set ROW to the number of rows of on the display
#define ROWS 4

// Time between each scroll of the screen in millis
#define SCROLL_DELAY 1500

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define JLENGTH (sizeof(jabberwocky) / sizeof(jabberwocky[0]))

// The words of Jabberwocky
const String jabberwocky[] = {
    "Twas", "brillig,", "and", "the", "slithy", "toves",
    "did", "gyre", "and", "gimble", "in", "the", "wabe:",
    "All", "mimsy", "were", "the", "borogoves,",
    "and", "the", "mome", "raths", "outgrabe.",
    "\"Beware", "the", "Jabberwock,", "my", "son!",
    "The", "jaws", "that", "bite,", "the", "claws", "that", "catch!",
    "Beware", "the", "Jubjub", "bird,", "and", "shun",
    "the", "frumious", "Bandersnatch!\""
};

static unsigned int nextWord = 0;

String screen[ROWS];

String makeLine() {
  if (nextWord >= JLENGTH) {
    return "";
  }
  String line = String(jabberwocky[nextWord]);
  nextWord++;
  while ((nextWord < JLENGTH) && (line.length() + jabberwocky[nextWord].length() + 1 < COLUMNS)) {
    line = line + " " + jabberwocky[nextWord];
    nextWord++;
  }
  while (line.length() < COLUMNS) {
    line = line + " ";
  }
  return line;
}

void displayScreen() {
  for (unsigned int i = 0; i < ROWS; i++) {
    lcd.setCursor(0, i);
    lcd.print(screen[i]);
  }
}

void setup() {

  // Display as much of "Jabberwocky" as will fit on the screen
  lcd.begin(COLUMNS, ROWS);
  lcd.clear();

  // Intialise to empty screen
  for (unsigned int i = 0; i < ROWS; i++) {
    screen[i] = "";
  }

  while (nextWord < JLENGTH) {
    for (unsigned int i = 0; i < ROWS - 1; i++) {
      screen[i] = screen[i+1];
    }
    String line = makeLine();
    screen[ROWS - 1] = line;
    displayScreen();
    delay(SCROLL_DELAY);
  }

}

void loop() {
  // Do nothing to do: all code is in setup()
}
