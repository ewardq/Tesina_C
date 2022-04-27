#include <xc.h>
#include <stdbool.h>
#include "prototipos.h"
#include "setup.h"
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

//Macros
#define MASK(x) ((unsigned char)(1<<x))

// Frecuencia del cristal interno = 4MHz
#define _XTAL_FREQ  4000000

//Configurando la transmisión EUSART
#define _TXEN  1   //Activa EUSART
#define _SYNC  0   //Comunicación asíncrona
#define _SPEN  1  // Configura TX como salida digital
#define _BRGH  0  //Activar sólo si se utiliza frecuencia de procesador de más de 4MHz
#define _BRG16 1  // Activar para enviar un dato de 16 bits, por default envía uno de 8bits

void main(void) {
    SET_BAUDRATE(9600);
    
    return;
}




void SET_BAUDRATE(int br){
   uint16_t Set_BaudRate;
   Set_BaudRate = (_XTAL_FREQ / (16*br)) - 1;
   SPBRG = Set_BaudRate & (MASK(4) | MASK(3) | MASK(2) | MASK(1) | MASK(0));
   SPBRGH = Set_BaudRate & (MASK(9) | MASK(8) | MASK(7) | MASK(6) | MASK(5));
}