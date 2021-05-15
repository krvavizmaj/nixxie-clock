/**
  Generated Pin Manager File

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.5
        Device            :  PIC16F877A
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB             :  MPLAB X 5.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
*/

#include <stdint.h>

#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)
{
    /**
     * TRISx registers
     */
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0xEF;
    TRISD = 0x00;
    TRISE = 0x07;
}

  