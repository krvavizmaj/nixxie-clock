#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "clock_manager.h"
#include "state_manager.h"

uint8_t HOURS = 0;
uint8_t MINUTES = 0;
uint8_t SECONDS = 0;

uint8_t SECONDS_VALUES[] = {
    0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90,
    0x01, 0x11, 0x21, 0x31, 0x41, 0x51, 0x61, 0x71, 0x81, 0x91,
    0x02, 0x12, 0x22, 0x32, 0x42, 0x52, 0x62, 0x72, 0x82, 0x92,
    0x03, 0x13, 0x23, 0x33, 0x43, 0x53, 0x63, 0x73, 0x83, 0x93,
    0x04, 0x14, 0x24, 0x34, 0x44, 0x54, 0x64, 0x74, 0x84, 0x94,
    0x05, 0x15, 0x25, 0x35, 0x45, 0x55, 0x65, 0x75, 0x85, 0x95
};
uint8_t HOUR_VALUES[] = {
    0x00, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24,
    0x01, 0x05, 0x09, 0x0D, 0x11, 0x15, 0x19, 0x1D, 0x21, 0x25,
    0x02, 0x06, 0x0A, 0x0E
};

uint8_t minutesToAdd = 0;        
uint8_t hoursToAdd = 0;        
        
void CLOCK_MANAGER_Initialize() {
    // reset the BDC ICs
    PORTA = 0x11;
    PORTB = 0x11;
    PORTD = 0x11;
    PORTA = 0x00;
    PORTB = 0x00;
    PORTD = 0x00;
}

void CLOCK_MANAGER_ResetSeconds(void) {
    SECONDS = 0;
}

void CLOCK_MANAGER_IncreaseSeconds(uint8_t amount) {
    SECONDS += amount;
    minutesToAdd = SECONDS / 60;
    
    if (SECONDS == 60) {
        SECONDS = 0; 
    }
    PORTD = SECONDS_VALUES[SECONDS];
    
    CLOCK_MANAGER_IncreaseMinutes(minutesToAdd);
    
//    printf("%02d:%02d:%02d\n", HOURS, MINUTES, SECONDS);
}

void CLOCK_MANAGER_IncreaseMinutes(uint8_t amount) {
    MINUTES += amount;
    hoursToAdd = MINUTES / 60;
    
    if (MINUTES == 60) {
        MINUTES = 0; 
    }
    PORTB = SECONDS_VALUES[MINUTES];
    
    CLOCK_MANAGER_IncreaseHours(hoursToAdd);
}

void CLOCK_MANAGER_IncreaseHours(uint8_t amount) {
    HOURS += amount;
    if (HOURS == 24) {
        HOURS = 0;
    }
    
    PORTA = HOUR_VALUES[HOURS];
}
