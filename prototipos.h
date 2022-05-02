
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define DETENER   0b00001

#define APAGAR    0b00001
#define DERECHA   0b00010  
#define IZQUIERDA 0b00100
#define ADELANTE  0b01000
#define ATRAS     0b10000

// ____________________________________________________________________________
// =====================  Control de motores ON-OFF  ==========================
// ============================================================================
void vehiculo(unsigned op){
    if (op & DETENER){
        PORTAbits.RA7  = 0;        // Rueda Derecha atras
        PORTCbits.RC1  = 0;
    
        PORTAbits.RA6  = 0;        // Rueda Izquierda atras
        PORTCbits.RC2 = 0;
    }
    if (op & DERECHA){
        PORTAbits.RA7  = 1;        // Rueda Derecha avanza
        PORTCbits.RC1  = 0;
    
        PORTAbits.RA6 = 0;        // Rueda Izquierda se detiene
        PORTCbits.RC2 = 0;
    }
    if (op & IZQUIERDA){
        PORTAbits.RA7  = 0;        // Rueda Derecha se detiene
        PORTCbits.RC1  = 0;
    
        PORTAbits.RA6  = 1;        // Rueda Izquierda avanza
        PORTCbits.RC2 = 0;
    }
    if (op & ADELANTE){
        PORTAbits.RA7 = 1;        // Rueda Derecha avanza
        PORTCbits.RC1 = 0;
    
        PORTAbits.RA6 = 1;        // Rueda Izquierda avanza
        PORTCbits.RC2 = 0;
    }
    if (op & ATRAS){
        PORTAbits.RA7  = 0;        // Rueda Derecha atras
        PORTCbits.RC1  = 1;
    
        PORTAbits.RA6  = 0;        // Rueda Izquierda atras
        PORTCbits.RC2 = 1;
    }
}

void direccional(unsigned op){
    if (op & DERECHA){
        PORTAbits.RA0 = 1;
        PORTAbits.RA1 = 0;
    }
    if (op & IZQUIERDA){
        PORTAbits.RA0 = 0;
        PORTAbits.RA1 = 1;
    }
    if (op & APAGAR){
        PORTAbits.RA0 = 0;
        PORTAbits.RA1 = 0; 
    }
}

//  >>>>>>>>>>>>>>>>>>>> Funci�n de prueba <<<<<<<<<<<<<<<<<<<<<<<<<< 
//                      <<    Motores    >>
void probar_motores_mov(){
    //Probar los modos de movimiento
    vehiculo(ATRAS);
    __delay_ms(1000);
    
    vehiculo(DERECHA);
    direccional(DERECHA);
    __delay_ms(1000);
    
    vehiculo(IZQUIERDA);
    direccional(IZQUIERDA);
    __delay_ms(1000);
    
    vehiculo(DETENER);
    direccional(APAGAR);
    __delay_ms(1000);
}
// ============================================================================

// ____________________________________________________________________________
// =======  Generaci�n de PWM para servo (50Hz / 5-10% Duty Cycle)  ===========
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
            default:   __delay_us(500);    //Posici�n neutral (90�)
        }
        __delay_us(18000);
     }
}

//  >>>>>>>>>>>>>>>>>>>> Funci�n de prueba <<<<<<<<<<<<<<<<<<<<<<<<<< 
//                     <<   Servomotor   >>
void probar_servomotor(){
    __delay_ms(1000);
     posicionar_servo(_0);
     
     __delay_ms(1000);
     posicionar_servo(_90);
     
     __delay_ms(1000);
     posicionar_servo(_180);
     
    __delay_ms(1000);
     posicionar_servo(_90);
}
// ============================================================================

// ____________________________________________________________________________
// =======  Generaci�n de PWM para servo (50Hz / 5-10% Duty Cycle)  ===========
// ============================================================================
unsigned int get_distancia_ultrasonico(){
    unsigned temp;
    TMR1H = 0;                //Sets the Initial Value of Timer
    TMR1L = 0;                //Sets the Initial Value of Timer

    RA3 = 1;                  //TRIGGER HIGH
    __delay_us(10);           //10uS Delay 
    RA3 = 0;                  //TRIGGER LOW

    while(!RA2);              //Waiting for Echo
    TMR1ON = 1;               //Timer Starts
    while(RA2);               //Waiting for Echo goes LOW
    TMR1ON = 0;               //Timer Stops

    temp = (TMR1L | (TMR1H<<8)); //Reads Timer Value
    temp = temp/29.41;              //Converts Time to Distance
    temp = temp + 1;                //Distance Calibration
    if(temp>=2 && temp<=400) {//Check whether the result is valid or not
        return temp;
     }       
    else return 0;
}

// ============================================================================
#endif	/* XC_HEADER_TEMPLATE_H */

