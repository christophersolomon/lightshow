void bothColorWipe(uint32_t c,uint32_t c2, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip2.setPixelColor(i, c2);
    strip.show();
    strip2.show();
    delay(wait);
  }
}

void bothColorWipeRandom(uint8_t wait) {
  uint32_t c = strip.Color(random(256),random(256),random(256));
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip2.setPixelColor(i, c);
    strip.show();
    strip2.show();
    delay(wait);
  }
}

void bothColorWipeRandomRandom(uint8_t wait) {
  
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(random(256),random(256),random(256)));
    strip2.setPixelColor(i, strip.Color(random(256),random(256),random(256)));
    strip.show();
    strip2.show();
    delay(wait);
  }
}

void bothColorChaseLoop(uint32_t c,uint32_t c2,uint8_t wait, uint8_t times) {
  for(uint16_t l=0; l<times; l++){
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      for(uint16_t j=0; j<strip.numPixels(); j++) {
        if (i==j){
          strip.setPixelColor(i, c);
          strip2.setPixelColor(i, c2);
        }
        else
        {
          strip.setPixelColor(j, strip.Color(0, 0, 0));
          strip2.setPixelColor(j, strip2.Color(0, 0, 0));
        }  
      }
      strip.show();
      strip2.show();
      delay(wait);   
    }
  }
}

void bothRainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
      strip2.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    strip2.show();
    delay(wait);
  }
}

void bothRainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      strip2.setPixelColor(i, Wheel(((i * 256 / strip2.numPixels()) + j) & 255));
    }
    strip.show();
    strip2.show();
    delay(wait);
  }
}
void bothRainbowCycleAlt(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      strip2.setPixelColor(i, Wheel(((i * 256 / strip2.numPixels()) - j) & 255));
    }
    strip.show();
    strip2.show();
    delay(wait);
  }
}
