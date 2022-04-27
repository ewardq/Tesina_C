
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// Salidas y entradas

void setup(void);

void vehiculo_adelante(void) {
    PORTBbits.RB7 = 1;        // Rueda Derecha avanza
    PORTCbits.RC1 = 0;
    
    PORTBbits.RB6 = 1;        // Rueda Izquierda avanza
    PORTCbits.RC2 = 0;
}

void vehiculo_derecha(void) {
    PORTBbits.RB7  = 1;        // Rueda Derecha avanza
    PORTCbits.RC1  = 0;
    
    PORTBbits.RB6 = 0;        // Rueda Izquierda se detiene
    PORTCbits.RC2 = 0;
}

void vehiculo_izquierda(void) {
    PORTBbits.RB7  = 0;        // Rueda Derecha se detiene
    PORTCbits.RC1  = 0;
    
    PORTBbits.RB6  = 1;        // Rueda Izquierda avanza
    PORTCbits.RC2 = 0;
}

void vehiculo_atras(void) {
    PORTBbits.RB7  = 0;        // Rueda Derecha atras
    PORTCbits.RC1  = 1;
    
    PORTBbits.RB6  = 0;        // Rueda Izquierda atras
    PORTCbits.RC2 = 1;
}

void vehiculo_detener(void) {
    PORTBbits.RB7  = 0;        // Rueda Derecha atras
    PORTCbits.RC1  = 0;
    
    PORTBbits.RB6  = 0;        // Rueda Izquierda atras
    PORTCbits.RC2 = 0;
}

#endif	/* XC_HEADER_TEMPLATE_H */

