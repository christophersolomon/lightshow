void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
void colorWipe2(uint32_t c2, uint8_t wait) {
  for(uint16_t i=0; i<strip2.numPixels(); i++) {
    strip2.setPixelColor(i, c2);
    strip2.show();
    delay(wait);
  }
}

void colorWipeRandom(uint8_t wait) {
  uint32_t c = strip.Color(random(256),random(256),random(256));
  colorWipe(c,wait);
}

void colorWipeRandom2(uint8_t wait) {
  uint32_t c = strip.Color(random(256),random(256),random(256));
  colorWipe2(c,wait);
}

void colorWipeRandomRandom(uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i,strip.Color(random(256),random(256),random(256)));
    strip.show();
    delay(wait);
  }
}

void colorWipeRandomRandom2(uint8_t wait) {
  for(uint16_t i=0; i<strip2.numPixels(); i++) {
    strip2.setPixelColor(i,strip.Color(random(256),random(256),random(256)));
    strip2.show();
    delay(wait);
  }
}

void colorChaseLoop(uint32_t c,uint8_t wait, uint8_t times) {
  for(uint16_t l=0; l<times; l++){
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      for(uint16_t j=0; j<strip.numPixels(); j++) {
        if (i==j){
          strip.setPixelColor(i, c);
        }
        else
        {
          strip.setPixelColor(j, strip.Color(0, 0, 0));
        }  
      }
      strip.show();
      delay(wait);   
    }
  }
}

void colorChaseLoop2(uint32_t c2,uint8_t wait, uint8_t times) {
  for(uint16_t l=0; l<times; l++){
    for(uint16_t i=0; i<strip2.numPixels(); i++) {
      for(uint16_t j=0; j<strip2.numPixels(); j++) {
        if (i==j){
          strip2.setPixelColor(i, c2);
        }
        else
        {
          strip2.setPixelColor(j, black);
        }  
      }
      strip2.show();
      delay(wait);   
    }
  }
}

void colorChaseLoopReverse(uint32_t c,uint8_t wait, uint8_t times) {
  for(uint16_t l=0; l<times; l++){
    for(uint16_t i=strip.numPixels(); i>0; i--) {
      for(uint16_t j=strip.numPixels(); j>0; j--) {
        if (i==j){
          strip.setPixelColor(i-1, c);
        }
        else
        {
          strip.setPixelColor(j-1, black);
        }   

      }
      strip.show();
      delay(wait);   
    } 
  }
}

void colorChaseLoopReverse2(uint32_t c2,uint8_t wait, uint8_t times) {
  for(uint16_t l=0; l<times; l++){
    for(uint16_t i=strip2.numPixels(); i>0; i--) {
      for(uint16_t j=strip2.numPixels(); j>0; j--) {
        if (i==j){
          strip2.setPixelColor(i-1, c2);
        }
        else
        {
          strip2.setPixelColor(j-1, black);
        }   

      }
      strip2.show();
      delay(wait);   
    } 
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void rainbow2(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip2.numPixels(); i++) {
      strip2.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip2.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void rainbowCycle2(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip2.numPixels(); i++) {
      strip2.setPixelColor(i, Wheel(((i * 256 / strip2.numPixels()) + j) & 255));
    }
    strip2.show();
    delay(wait);
  }
}


