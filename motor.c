
#include <xc.h>

void motor(void) {
    int8_t mask = 0b00000010;
    PORTA = PORTA | mask;
    mask = 0b00000001;
    PORTA = PORTA & mask;
}
