// PIC16F886 Configuration Bit Settings
    
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
#define _XTAL_FREQ 4000000


#include <xc.h>
#include <stdbool.h>
#include "prototipos.h"




void main(void) {
    //Configurando puertos
    TRISA = 0b00000100; 
    TRISB = 0b00000011;
    ANSEL = 0x00;
    TRISC = 0x00;
        
    direccional_apagar();
    vehiculo_detener();
    while(1){
 
     __delay_ms(1000);
     posicionar_servo(_90);
     
     __delay_ms(1000);
     posicionar_servo(_0);
     
     __delay_ms(1000);
     posicionar_servo(_180);

    }
    /*
    uint16_t Encoder1 = 0;
    uint16_t Encoder2 = 0;
    
    T1CON = 0x10;               //Initialize Timer Module
    int a;
    
    bool E1; 
    bool E1_old;
    bool E2; 
    bool E2_old;
   //Probar los modos de movimiento
          PORTBbits.RB7 = 0;
        vehiculo_atras();
        __delay_ms(1000);
        vehiculo_derecha();
                direccional(1);
        __delay_ms(1000);
        vehiculo_izquierda();
                direccional(0);
        __delay_ms(1000);
        vehiculo_detener();
       __delay_ms(1000);
        vehiculo_adelante();
        direccional_apagar();

    while(1){
    vehiculo_adelante();
    TMR1H = 0;                //Sets the Initial Value of Timer
    TMR1L = 0;                //Sets the Initial Value of Timer

    RA3 = 1;                  //TRIGGER HIGH
    __delay_us(10);           //10uS Delay 
    RA3 = 0;                  //TRIGGER LOW

    while(!RA2);              //Waiting for Echo
    TMR1ON = 1;               //Timer Starts
    while(RA2);               //Waiting for Echo goes LOW
    TMR1ON = 0;               //Timer Stops

    a = (TMR1L | (TMR1H<<8)); //Reads Timer Value
    a = a/29.41;              //Converts Time to Distance
    a = a + 1;                //Distance Calibration
    if(a>=2 && a<=400) {//Check whether the result is valid or not
         if(a < 10){
              vehiculo_detener();
              __delay_ms(500);
              vehiculo_atras();
              __delay_ms(2000);
              vehiculo_derecha();
              direccional(1);
              __delay_ms(200);
              direccional_apagar();
              __delay_ms(1000);
              vehiculo_adelante();
         }
    }       
    }
           */
        /*
    do{
        E1 = PORTBbits.RB1;
        if ((E1_old != E1) & (E1 == 1)){
            Encoder1++;}
        E1_old = E1;
        
        if (Encoder1 == 1050)
            PORTBbits.RB7 = 1;
        
        E2 = PORTBbits.RB0;
        if ((E2_old != E2) & (E2 == 1)){
            Encoder2++;}
        E2_old = E2;
        
        if (Encoder2 == 1050)
            PORTBbits.RB7 = 1;
        
    }while(Encoder1 != 2100);
    PORTBbits.RB7 = 0;
    vehiculo_detener();
    __delay_ms(1000);
    Encoder1 = 0;
    Encoder2 = 0;
    }
           
*/
    return;
}
