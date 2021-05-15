#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#include <xc.h>
#include <stdint.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set D3_LED aliases
#define D3_LED_TRIS                 TRISCbits.TRISC4
#define D3_LED_PORT                 PORTCbits.RC4
#define D3_LED_SetHigh()            do { PORTCbits.RC4 = 1; } while(0)
#define D3_LED_SetLow()             do { PORTCbits.RC4 = 0; } while(0)
#define D3_LED_Toggle()             do { PORTCbits.RC4 = ~PORTCbits.RC4; } while(0)
#define D3_LED_GetValue()           PORTCbits.RC4
#define D3_LED_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)

void PIN_MANAGER_Initialize (void);

#endif // PIN_MANAGER_H
