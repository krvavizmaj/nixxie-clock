#include <stdint.h>

#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)
{
    /**
     * Setup pin directions.
     */
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0xEF;
    TRISD = 0x00;
    TRISE = 0x07;
}

int SW1_BUTTON_GetValue(void) {
    return PORTCbits.RC5;
}

int SW2_BUTTON_GetValue(void) {
    return PORTCbits.RC6;
}

int SW3_BUTTON_GetValue(void) {
    return PORTCbits.RC7;
}
  