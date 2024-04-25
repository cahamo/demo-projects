// Based on Adafruit_NeoMatrix example code for single NeoPixel Shield.
//
// Highly modified for an 8x8 matrix to run a snake of different coloured
// pixels from top left to bottom right of the matrix. For Arduino Uno.

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6

#define WIDTH 8
#define HEIGHT 8

#define PAUSE 75

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
  WIDTH, 
  HEIGHT, 
  PIN,
  NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB + NEO_KHZ800
);

int pixels;

const uint16_t colors[] = {
  matrix.Color(255, 0, 0),    // red
  matrix.Color(0, 255, 0),    // green
  matrix.Color(0, 0, 255),    // blue
  matrix.Color(255, 192, 0),  // yellow
  matrix.Color(255, 0, 192),  // magenta
  matrix.Color(0, 192, 160),  // cyan
  matrix.Color(192, 192, 192) // white
};

#define COLOURS ((sizeof colors / sizeof colors[0]))

#define OFFSET (2 * COLOURS)


void setup() {
  // put your setup code here, to run once:
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(30);
  matrix.setTextColor(colors[0]);
  matrix.fillScreen(matrix.Color(0, 0, 0));

  pixels = matrix.width() * matrix.height();
}

void loop() {
  // put your main code here, to run repeatedly:
  static int ci = 0;
  for (int i = 0; i < pixels; i++) {
    int x1 = i / matrix.width();
    int y1 = i % matrix.height();
    int j;
    if (i >= OFFSET) {
      j = i - OFFSET;
    }
    else {
      j = pixels - OFFSET + i;
    }
    int x0 = j / matrix.width();
    int y0 = j % matrix.height();
  
    matrix.drawPixel(x1, y1, colors[ci]);
    matrix.drawPixel(x0, y0, matrix.Color(0, 0, 0));
    matrix.show();
  
    ci = (ci + 1) % COLOURS;
  
    delay(PAUSE);
  }
}
