#include "mcc.h"
#include "clock_manager.h"
#include "state_manager.h"
#include "buttons_manager.h"


void SYSTEM_Initialize(void) {
    PIN_MANAGER_Initialize();
    ADCON_Disable();            
    CLOCK_MANAGER_Initialize();
    STATE_MANAGER_Initialize();
    BUTTONS_MANAGER_Initialize();
    TMR0_Initialize();
}

void ADCON_Enable(void) {
    ADCON0bits.ADON = 1;
}

void ADCON_Disable(void) {
    // A/D converter module is shut-off and consumes no operating current 
    ADCON0bits.ADON = 0;
    
    // A/D Port Configuration Control bits, all PORTA pins digital IO
    ADCON1bits.PCFG = 0x06;
}