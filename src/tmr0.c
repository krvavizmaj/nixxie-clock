#include <xc.h>
#include <stdio.h>
#include "tmr0.h"
#include "pin_manager.h"
#include "clock_manager.h"
#include "state_manager.h"
#include "buttons_manager.h"

uint8_t timerOverflowsCounter = 0;
int i;

void TMR0_Initialize(void) {
    // Set TMR0 to the options selected in the User Interface

    // TMR0 Clock Source Select bit; Internal instruction cycle clock (CLKO)
    OPTION_REGbits.T0CS = 0;
    
    // Prescaler is assigned to the Timer0 module
    OPTION_REGbits.PSA = 0;
    
    // Prescaler 1:64
    OPTION_REGbits.PS = 0x05;
    
    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF = 0;

    // Enabling TMR0 interrupt.
    INTCONbits.TMR0IE = 1;
}

void TMR0_EnableTimer(void) {
    // Enable the Timer by writing to TMR0IE bit
    INTCONbits.TMR0IE = 1;
}

void TMR0_DisableTimer(void) {
    // Disable the Timer by writing to TMR0IE bit
    INTCONbits.TMR0IE = 0;
}

uint8_t TMR0_ReadTimer(void) {
    uint8_t readVal;

    // read Timer0
    readVal = TMR0;

    return readVal;
}

void TMR0_WriteTimer(uint8_t timerVal) {
    // Write to Timer0 registers
    TMR0 = timerVal;
}

/**
 * When TMR0 overflows, the value is set to 6.
 * That would make (256-6) = 250 cycles * 64 prescaler = 16000 cycles per overflow
 * After counting 64 overflows, 1 second should have passed (64 * 16000 = 1024000 * 4 (internal divider) = crystal frequency)
 */
void TMR0_ISR(void) {
    // timer tuner
    NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP();
    NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP();
    NOP(); NOP();
    
    TMR0_WriteTimer(7);
    // clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;
    
    // add your TMR0 interrupt custom code
    timerOverflowsCounter++;
    
    // update input buttons state
    BUTTONS_MANAGER_TimerOverflowHandler();
    
    if (timerOverflowsCounter == 32) {
        // Half Second Passed
        STATE_MANAGER_HandleHalfSecondMark();
    }
    
    if (timerOverflowsCounter == 64) {
        // One Second Passed
        timerOverflowsCounter = 0;
        CLOCK_MANAGER_IncreaseSeconds(1);
        STATE_MANAGER_HandleFullSecondMark();
    }
}
