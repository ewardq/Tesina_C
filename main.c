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

#define _XTAL_FREQ 4000000



void main(void) {
    //Configurando puertos
    TRISA = 0b00000100; 
    TRISB = 0b00000011;
    TRISC = 0x00;

    uint16_t Encoder1 = 0;
    uint16_t Encoder2 = 0;
    
    bool temp; 
    bool temp_old;

    for(;;){
        vehiculo_adelante();

    do{
        temp = PORTBbits.RB1;
        if ((temp_old != temp) & (temp == 1)){
            Encoder1++;}
        temp_old = temp;
        
        temp = PORTBbits.RB0;
        if ((temp_old != temp) & (temp == 1)){
            Encoder2++;}
        temp_old = temp;
    }while(Encoder1 != 2100);

    
    vehiculo_detener();
    __delay_ms(500);
    Encoder1 = 0;
    Encoder2 = 0;
    }
           
    return;
}
