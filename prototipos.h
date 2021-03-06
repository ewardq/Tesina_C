
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

//  >>>>>>>>>>>>>>>>>>>> Función de prueba <<<<<<<<<<<<<<<<<<<<<<<<<< 
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

//  >>>>>>>>>>>>>>>>>>>> Función de prueba <<<<<<<<<<<<<<<<<<<<<<<<<< 
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
// =======  Obtener distancia de sensor ultrasonico hc-sr04  ===========
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

// ____________________________________________________________________________
// =================  Contadores y procesamiento de Encoders  =================
// ============================================================================
 
    /*
    bool E1; 
    bool E1_old;
    bool E2; 
    bool E2_old;

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
// ============================================================================

// ____________________________________________________________________________
// =================  Comunicación UART   =================
// ============================================================================
//Configurando la transmisión EUSART
#define _TXEN  1   //Activa EUSART
#define _SYNC  0   //Comunicación asíncrona
#define _SPEN  1  // Configura TX como salida digital
#define _BRGH  0  //Activar sólo si se utiliza frecuencia de procesador de más de 4MHz
#define _BRG16 1  // Activar para enviar un dato de 16 bits, por default envía uno de 8bits


 //  SET_BAUDRATE(9600);
void SET_BAUDRATE(int br){
   uint16_t Set_BaudRate;
   Set_BaudRate = (_XTAL_FREQ / (16*br)) - 1;
   SPBRG = Set_BaudRate & (MASK(4) | MASK(3) | MASK(2) | MASK(1) | MASK(0));
   SPBRGH = Set_BaudRate & (MASK(9) | MASK(8) | MASK(7) | MASK(6) | MASK(5));
}
// ============================================================================

// ____________________________________________________________________________
// =================  Comunicación I2C   =================
// ============================================================================
void I2C_Master_Init(const unsigned long c){
  SSPCON = 0b00101000;
  SSPCON2 = 0;
  SSPADD = (_XTAL_FREQ/(4*c))-1;
  SSPSTAT = 0;
  TRISC3 = 1;        //Setting as input as given in datasheet
  TRISC4 = 1;        //Setting as input as given in datasheet
}

void I2C_Master_Wait(){
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Master_Start(){
  I2C_Master_Wait();
  SEN = 1;
}

void I2C_Master_RepeatedStart(){
  I2C_Master_Wait();
  RSEN = 1;
}

void I2C_Master_Stop(){
  I2C_Master_Wait();
  PEN = 1;
}

void I2C_Master_Write(unsigned d){
  I2C_Master_Wait();
  SSPBUF = d;
}

unsigned short I2C_Master_Read(unsigned short a){
  unsigned short temp;
  I2C_Master_Wait();
  RCEN = 1;
  I2C_Master_Wait();
  temp = SSPBUF;
  I2C_Master_Wait();
  ACKDT = (a)?0:1;
  ACKEN = 1;
  return temp;
}
// ============================================================================
#endif	/* XC_HEADER_TEMPLATE_H */
