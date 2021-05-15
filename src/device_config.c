/**
  @Generated PIC10 / PIC12 / PIC16 / PIC18 MCUs Source File

  @Summary:
    This is the device_config.c file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.5
        Device            :  PIC16F877A
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above or later
        MPLAB             :  MPLAB X 5.40
*/

// CONFIG
#pragma config FOSC     = HS    // Oscillator Selection bits (HS oscillator)
#pragma config WDTE     = OFF   // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE    = OFF   // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN    = ON    // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP      = ON    // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD      = OFF   // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT      = OFF   // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP       = OFF   // Flash Program Memory Code Protection bit (Code protection off)
