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

  