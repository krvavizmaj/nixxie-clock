/**
  @Generated PIC10 / PIC12 / PIC16 / PIC18 MCUs Source File

  @Summary:
    This is the mcc.c file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

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

#include "mcc.h"
#include "clock_manager.h"

void SYSTEM_Initialize(void) {
    PIN_MANAGER_Initialize();
    ADCON_Disable();            
    TMR0_Initialize();
    CLOCK_MANAGER_Initialize();
}

void ADCON_Enable(void) {
    ADCON0bits.ADON = 1;
}

void ADCON_Disable(void) {
    ADCON0bits.ADON = 0;
    ADCON1bits.PCFG = 0x06;
}