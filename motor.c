
#include <xc.h>

void motor(void) {
    int8_t mask = 0b00000010;
    PORTC = PORTC | mask;
    mask = 0b00000001;
    PORTC = PORTC & ~mask;
}
