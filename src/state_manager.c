#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include "state_manager.h"
#include "clock_manager.h"

uint8_t STATE;

int *PORTS_TO_DIGIT[5];
uint8_t DIGIT_PORT_MASK[] = {0x03, 0x3C, 0x0F, 0xF0, 0xFF};
uint8_t SETTING_DIGIT_MOD[] = {0x03, 0xA0, 0x06, 0xA0};

/**
 * Sets which digit is being set on the clock
 * 0 = First hour digit
 * 1 = Second hour digit
 * 2 = First minute digit
 * 3 = Second minute digit
 * 4 = Both seconds digits
 */
uint8_t SETTING_DIGIT = 0;

void STATE_MANAGER_Initialize() {
    STATE = SHOWING_TIME;
    
    PORTS_TO_DIGIT[0] = &TRISA;
    PORTS_TO_DIGIT[1] = &TRISA;
    PORTS_TO_DIGIT[2] = &TRISB; 
    PORTS_TO_DIGIT[3] = &TRISB;
    PORTS_TO_DIGIT[4] = &TRISD;
}

void STATE_MANAGER_HandleHalfSecondMark(void) {
    if (STATE == SETTING_TIME) {
        // turn off digit that is being set, set TRIS bits to 1
        *PORTS_TO_DIGIT[SETTING_DIGIT] = *PORTS_TO_DIGIT[SETTING_DIGIT] ^ DIGIT_PORT_MASK[SETTING_DIGIT]; 
    }
}

void STATE_MANAGER_HandleFullSecondMark(void) {
    if (STATE == SETTING_TIME) {
        // turn on settings digit
        *PORTS_TO_DIGIT[SETTING_DIGIT] = *PORTS_TO_DIGIT[SETTING_DIGIT] ^ DIGIT_PORT_MASK[SETTING_DIGIT];
    }
}

void STATE_MANAGER_HandleButton1Press(void) {
    if (STATE == SHOWING_TIME) {
        STATE = SETTING_TIME;
    } else {
        // Enable previous digit
        TRISA = 0x00;
        TRISB = 0x00;
        TRISD = 0x00;
        
        SETTING_DIGIT++;
        SETTING_DIGIT %= 5;
        if (SETTING_DIGIT == 0) {
            STATE = SHOWING_TIME;
        }
    }
}

void STATE_MANAGER_HandleButton2Press(void) {
    if (STATE == SETTING_TIME) {
        // increase digit SETTING_DIGIT and set to PORTx register
        switch (SETTING_DIGIT) {
            case 0:
                CLOCK_MANAGER_IncreaseHours(10);
                break;
            case 1:
                CLOCK_MANAGER_IncreaseHours(1);
                break;
            case 2:
                CLOCK_MANAGER_IncreaseMinutes(10);
                break;
            case 3:
                CLOCK_MANAGER_IncreaseMinutes(1);
                break;
            case 4:
                CLOCK_MANAGER_ResetSeconds();
                break;
            default:
                break;
        }
    }
}
