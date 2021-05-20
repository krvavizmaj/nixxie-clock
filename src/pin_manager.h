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
#define D3_LED_TRIS                     TRISCbits.TRISC4
#define D3_LED_PORT                     PORTCbits.RC4
#define D3_LED_SetHigh()                do { PORTCbits.RC4 = 1; } while(0)
#define D3_LED_SetLow()                 do { PORTCbits.RC4 = 0; } while(0)
#define D3_LED_Toggle()                 do { PORTCbits.RC4 = ~PORTCbits.RC4; } while(0)
#define D3_LED_GetValue()               PORTCbits.RC4
#define D3_LED_SetDigitalInput()        do { TRISCbits.TRISC4 = 1; } while(0)

// SW1_BUTTON aliases
#define SW1_BUTTON_TRIS                 TRISCbits.TRISC5
#define SW1_BUTTON_PORT                 PORTCbits.RC5
#define SW1_BUTTON_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)

// SW2_BUTTON aliases
#define SW2_BUTTON_TRIS                 TRISCbits.TRISC6
#define SW2_BUTTON_PORT                 PORTCbits.RC6
#define SW2_BUTTON_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)

// SW3_BUTTON aliases
#define SW3_BUTTON_TRIS                 TRISCbits.TRISC7
#define SW3_BUTTON_PORT                 PORTCbits.RC7
#define SW3_BUTTON_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)

void PIN_MANAGER_Initialize (void);

int SW1_BUTTON_GetValue(void);
int SW2_BUTTON_GetValue(void);
int SW3_BUTTON_GetValue(void);

#endif // PIN_MANAGER_H
