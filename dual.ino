void dualColorWipe(uint32_t c, uint32_t c2, uint8_t wait) {
  colorWipe(c,wait);
  colorWipe2(c2,wait);
}

void dualColorWipeRandom(uint8_t wait) {
  colorWipeRandom(wait);
  colorWipeRandom2(wait);
}

void dualColorWipeRandomRandom(uint8_t wait) {
  colorWipeRandomRandom(wait);
  colorWipeRandomRandom2(wait);
}
void dualColorChaseLoop(uint32_t c,uint32_t c2,uint8_t wait, uint8_t times){
  for(uint16_t l=0; l<times; l++){
    colorChaseLoop(c,wait,1);
    blank();
    colorChaseLoop2(c2,wait,1);
    blank();
  }
}

void dualColorChaseLoopReverse(uint32_t c,uint32_t c2,uint8_t wait, uint8_t times){
  for(uint16_t l=0; l<times; l++){
    colorChaseLoopReverse(c,wait,1);
    blank();
    colorChaseLoopReverse2(c2,wait,1);
    blank();
  }
}

void cwColorChaseLoop(uint32_t c,uint32_t c2,uint8_t wait, uint8_t times){
  for(uint16_t l=0; l<times; l++){
    colorChaseLoopReverse2(c2,wait,1);
    blank();
    colorChaseLoop(c,wait,1);
    blank();
  }
}

void ccwColorChaseLoop(uint32_t c,uint32_t c2,uint8_t wait, uint8_t times){
  for(uint16_t l=0; l<times; l++){
    colorChaseLoopReverse(c,wait,1);
    blank();
    colorChaseLoop2(c2,wait,1);
    blank();
  }
}

void dualRainbow(uint8_t wait){
  rainbow(wait);
  blank();
  rainbow2(wait);
  blank();
}

void dualRainbowCycle(uint8_t wait){
  rainbowCycle(wait);
  blank();
  rainbowCycle2(wait);
  blank();
}
