
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// Salidas y entradas

void setup(void);

void vehiculo_adelante(void) {
    PORTAbits.RA7 = 1;        // Rueda Derecha avanza
    PORTCbits.RC1 = 0;
    
    PORTAbits.RA6 = 1;        // Rueda Izquierda avanza
    PORTCbits.RC2 = 0;
}

void vehiculo_derecha(void) {
    PORTAbits.RA7  = 1;        // Rueda Derecha avanza
    PORTCbits.RC1  = 0;
    
    PORTAbits.RA6 = 0;        // Rueda Izquierda se detiene
    PORTCbits.RC2 = 0;
}

void vehiculo_izquierda(void) {
    PORTAbits.RA7  = 0;        // Rueda Derecha se detiene
    PORTCbits.RC1  = 0;
    
    PORTAbits.RA6  = 1;        // Rueda Izquierda avanza
    PORTCbits.RC2 = 0;
}

void vehiculo_atras(void) {
    PORTAbits.RA7  = 0;        // Rueda Derecha atras
    PORTCbits.RC1  = 1;
    
    PORTAbits.RA6  = 0;        // Rueda Izquierda atras
    PORTCbits.RC2 = 1;
}

void vehiculo_detener(void) {
    PORTAbits.RA7  = 0;        // Rueda Derecha atras
    PORTCbits.RC1  = 0;
    
    PORTAbits.RA6  = 0;        // Rueda Izquierda atras
    PORTCbits.RC2 = 0;
}

void direccional(unsigned op){
    if (op == 1){
        PORTAbits.RA0 = 1;
        PORTAbits.RA1 = 0;
    }
    else{
        PORTAbits.RA0 = 0;
        PORTAbits.RA1 = 1;
    }
}

void direccional_apagar(void){
     PORTAbits.RA0 = 0;
     PORTAbits.RA1 = 0;
}

// ============================================================================
// =======  Generación de PWM para servo (50Hz / 5-10% Duty Cycle)  ===========
// ============================================================================

const unsigned _0 = 0;
const unsigned _90 = 90;
const unsigned _180 = 180;

void posicionar_servo(unsigned degrees){
    for(int i = 0; i < 6; i++){
     PORTCbits.RC0 = 1;
        __delay_us(1000);
        switch(degrees){    
            case 0:                       //Total de 1ms
             break;   
            case 90:  __delay_us(500);    //Total de 1.5ms
             break;
            case 180: __delay_us(1000);   //Total de 2ms
             break;
            default:  __delay_us(500);   
        }    
     PORTCbits.RC0 = 0;
        switch(degrees){    
            case 0:    __delay_us(1000);
             break;
            case 90:   __delay_us(500);    
             break;
            case 180:
             break;      
            default:   __delay_us(500);    //Posición neutral (90°)
        }
        __delay_us(18000);
     }
}
// ============================================================================

#endif	/* XC_HEADER_TEMPLATE_H */

