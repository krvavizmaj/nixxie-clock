#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include "state_manager.h"

uint8_t STATE = SHOWING_TIME;

/**
 * Sets which digit is being set on the clock
 * 0 = First hour digit
 * 1 = Second hour digit
 * 2 = First minute digit
 * 3 = Second minute digit
 * 4 = Both seconds digits
 */
uint8_t SETTING_DIGIT = 0;

void STATE_MANAGER_HandleHalfSecondMark(void) {
    if (STATE == SETTING_TIME) {
        // turn off settings digit
    }
}

void STATE_MANAGER_HandleFullSecondMark(void) {
    if (STATE == SETTING_TIME) {
        // turn on settings digit
    }
}

void STATE_MANAGER_HandleButton1Press(void) {
    if (STATE == SHOWING_TIME) {
        STATE = SETTING_TIME;
    } else {
        SETTING_DIGIT++;
        SETTING_DIGIT %= 5;
        if (SETTING_DIGIT == 0) {
            STATE = SHOWING_TIME;
        }
    }
}

void STATE_MANAGER_HandleButton1Press(void) {
    if (STATE == SETTING_TIME) {
        // increase SETTING_DIGIT
    }
}
