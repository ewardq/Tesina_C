
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

#endif	/* XC_HEADER_TEMPLATE_H */

