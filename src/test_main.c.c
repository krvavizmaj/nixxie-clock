/*
 * File:   main.c
 * Author: krvav
 *
 * Created on May 4, 2021, 9:28 PM
 */
//
//
//#include <xc.h>
//#include <stdint.h>
//
//// CONFIG
//#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
//#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
//#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
//#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
//#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
//#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
//#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
//#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
//
//#define _XTAL_FREQ 40960000     // oscilator frequency, used by __delay() functions
//
//uint8_t     sPORTC = 0;         // value for writing to PORTC 
//
//void maintest(void) {
//    
//    TRISC = 0b11101111;         // set pin 4 of PORTC as output
//    
//    // setting bits on IO port
//    PORTC = 0b00010000;
//    PORTCbits.RC4 = 1;
//    PORTCbits.RC4 = 0;
//    sPORTC ^= 0b00010000;       // flip a bit
//    PORTC = sPORTC;
//    
//    for (;;) {
//        // main program loop
//        sPORTC ^= 0b00010000;
//        PORTC = sPORTC;
//        __delay_ms(500);        // sleep x ms
//    }
//}
