#include <xc.h>
#include "prototipos.h"
//#include "pic16f886.inc"

void main(void) {
  //  setup();
    TRISA = 0b00001111;
    TRISB = 0x00;

    unsigned Encoder1 = 0x04;
    unsigned Encoder2 = 0x05;
    
    motor();
    
    return;
}
