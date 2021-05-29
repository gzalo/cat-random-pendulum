#include <xc.h>
#include <stdlib.h>

#pragma config WDTE=OFF, PWRTE=OFF, BOREN=OFF, MCLRE=OFF, CP=OFF, CPD=OFF, FOSC=INTRCIO
#define _XTAL_FREQ 4000000

#define MOTOR_STOP 0x00
#define MOTOR_FORWARDS 0x01
#define MOTOR_BACKWARDS 0x03

void delay_ms(int ms) {
   while(ms-- > 0) __delay_ms(1);
}

void main(void) {
    __delay_ms(1000);
    
    TRISIO = 0b11111100;
    GPIO = MOTOR_STOP;
    
    while(1) {
        if (rand()%2 == 0) {
            GPIO = MOTOR_FORWARDS;
        } else {
            GPIO = MOTOR_BACKWARDS;
        }
        delay_ms(rand()%150+50);
        
        GPIO = MOTOR_STOP;
        delay_ms(rand()%1000+500);
    }
}
