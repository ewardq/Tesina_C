// PIC16F886 Configuration Bit Settings
// 'C' source line config statements
    
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdbool.h>
#include "prototipos.h"
//#include "pic16f886.inc"

void main(void) {
    int8_t LED = 1; 
    TRISC = 0b11110000;
    TRISB = 0x00;

    uint16_t Encoder1 = 0;
    uint16_t Encoder2 = 0;
    /*
    bool A; */
    bool A_old;
   
    PORTB = PORTB | LED;
    motor();
    for(;;){
    
        //RC4 = At
        //RC5 = Bt
        //Bt-1 
    do{
  /*  if((Bt_1 & PORTCbits.RC4) | (~PORTCbits.RC4 & ~Bt_1))
        Encoder1++;
    
    Bt_1 = PORTCbits.RC5; 
            */
    if ((A_old != PORTCbits.RC4) & (PORTCbits.RC4 == 1)){
        Encoder1++;}
    A_old = PORTCbits.RC4;
              
    if(Encoder1 == 100)
         PORTB = PORTB & ~LED;
    
    if(Encoder1 == 1050)
        PORTB = PORTB | LED;
    
    if(Encoder1 == 1150)
        PORTB = PORTB & ~LED;
    
    }while(Encoder1 != 2100);
    PORTB = PORTB | LED;
    Encoder1 = 0;
    }
           
    return;
}
