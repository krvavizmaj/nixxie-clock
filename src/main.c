#include "mcc.h"

/**
 * For printing in UART console in simulator.
 */
void init_uart(void) {
    TXSTAbits.TXEN = 1;               // enable transmitter
    RCSTAbits.SPEN = 1;               // enable serial port
}

/**
 * Used for printing to UART outpu in debug.
 * @param data
 */
void putch(unsigned char data) {
    while( ! PIR1bits.TXIF)           // wait until the transmitter is ready
        continue;
    TXREG = data;                     // send one character
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    init_uart();
    
    while (1) {
        // Add your application code
//        D3_LED_Toggle();
    }
    
}
