
#include <Adafruit_NeoPixel.h>

#define PIN 9
#define PIN2 10
#define PIN3 11

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(14, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(14, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(14, PIN3, NEO_GRB + NEO_KHZ800);

uint32_t red = strip.Color(255,0,0);
uint32_t blue = strip.Color(0,0,255);
uint32_t green = strip.Color(0,255,0);

uint32_t orange = strip.Color(255,127,0);
uint32_t black = strip.Color(0,0,0);
uint32_t white = strip.Color(255,255,255);

uint32_t cyan = strip.Color(0,255,255);
uint32_t magenta = strip.Color(255,0,255);
uint32_t yellow = strip.Color(255,255,0);

void setup() {
  strip.begin();
  strip2.begin();
  strip3.begin();
  strip.show();
  strip2.show();
  strip3.show(); // Initialize all pixels to 'off'
  strip.setBrightness(60);
  strip2.setBrightness(60);
  strip3.setBrightness(60);
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  //colorWipe(strip.Color(255, 0, 0), 50); // Red
  //colorWipe(strip.Color(0, 255, 0), 50); // Green
  //colorWipe(strip.Color(0, 0, 255), 50); // Blue
  
//  for (int i=0;i<20;i++){
//  seizureMode();
//  }

//  bothRainbow(10);
  triRainbowCycle(5);
//  bothRainbowCycleAlt(5);
//  blank();
//
//  dualColorWipeRandom(50);
//  dualColorWipeRandomRandom(50);
//  bothColorWipeRandom(50);
//  bothColorWipeRandomRandom(50);
//    
//  dualColorWipe(red,red,50);
//  dualColorWipe(blue,blue,50);
//  dualColorWipe(green,green,50);
//  dualColorWipe(magenta,magenta,50);
//  dualColorWipe(yellow,yellow,50);
//  dualColorWipe(cyan,cyan,50);
//  
//  bothColorWipe(red,red,50);
//  bothColorWipe(blue,blue,50);
//  bothColorWipe(green,green,50);
//  bothColorWipe(magenta,magenta,50);
//  bothColorWipe(yellow,yellow,50);
//  bothColorWipe(cyan,cyan,50);
// 
//  blank();
//  
//  cwColorChaseLoop(red,red,20,5);
//  cwColorChaseLoop(blue,blue,20,5);
//  cwColorChaseLoop(green,green,20,5);
//  cwColorChaseLoop(magenta,magenta,20,5);
//  cwColorChaseLoop(yellow,yellow,20,5);
//  cwColorChaseLoop(cyan,cyan,20,5);
//  
//  blank();
//  
//  
}

void seizureMode() {
  
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i,red);
    strip2.setPixelColor(i,blue);
  }
  strip.show();
  strip2.show();
  delay(30);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i,blue);
    strip2.setPixelColor(i,green);
  }
  strip.show();
  strip2.show();
  delay(30);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i,green);
    strip2.setPixelColor(i,red);
  }
  strip.show();
  strip2.show();
  delay(30);
}

// Fill the dots one after the other with a color

//======= Simple Codes ==========

void blank(){
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, black);
    strip2.setPixelColor(i, black);
    strip.show();
    strip2.show();
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
