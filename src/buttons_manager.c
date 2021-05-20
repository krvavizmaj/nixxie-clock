#include <xc.h>
#include "buttons_manager.h"
#include "pin_manager.h"

int BUTTON_STATE[3];
int (*BUTTON_VALUES[3]) ();

void BUTTONS_MANAGER_Initialize(void) {
    BUTTON_STATE[BUTTON1] = BUTTON_RELEASED;
    BUTTON_STATE[BUTTON2] = BUTTON_RELEASED;
    BUTTON_STATE[BUTTON3] = BUTTON_RELEASED;

    BUTTON_VALUES[BUTTON1] = SW1_BUTTON_GetValue;
    BUTTON_VALUES[BUTTON2] = SW2_BUTTON_GetValue;
    BUTTON_VALUES[BUTTON3] = SW3_BUTTON_GetValue;
}

void BUTTONS_MANAGER_UpdateButtonsState(int buttonNumber) {
    
    switch (BUTTON_STATE[buttonNumber]) {
        case BUTTON_RELEASED:
            if ((*BUTTON_VALUES[buttonNumber]) () == 0) {
                BUTTON_STATE[buttonNumber] = BUTTON_PRESSED;
            }
            break;
        case BUTTON_PRESSED:
            // wait for timer timeout
            break;
        case BUTTON_DEBOUNCED:
            // wait for event from caller
            break; 
        case BUTTON_HANDLED:
            if ((*BUTTON_VALUES[buttonNumber]) ()  == 1) {
                BUTTON_STATE[buttonNumber] = BUTTON_RELEASED;
            }
            break;    
        default:
            break;
    }
}

void BUTTONS_MANAGER_TimerOverflowHandler(void) {
    for (int i = 0; i < 3; i++) {
        if (BUTTON_STATE[i] == BUTTON_PRESSED) {
            if ((*BUTTON_VALUES[i]) ()  == 0) {
                BUTTON_STATE[i] = BUTTON_DEBOUNCED;
            } else {
                BUTTON_STATE[i] = BUTTON_RELEASED;
            }
        }
    }
}

void BUTTONS_MANAGER_ButtonPressHandled(int buttonNumber) {
    if (BUTTON_STATE[buttonNumber] == BUTTON_DEBOUNCED) {
        BUTTON_STATE[buttonNumber] = BUTTON_HANDLED;
    }
}

int BUTTONS_MANAGER_GetButtonState(int buttonNumber) {
    return BUTTON_STATE[buttonNumber];
}
