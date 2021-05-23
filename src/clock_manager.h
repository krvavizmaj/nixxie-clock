#ifndef CLOCK_MANAGER_H
#define	CLOCK_MANAGER_H

#include <xc.h>

#define HOURS_PORT      PORTA
#define MINUTES_PORT    PORTB
#define SECONDS_PORT    PORTD

void CLOCK_MANAGER_Initialize(void);

void CLOCK_MANAGER_ResetSeconds(void);

void CLOCK_MANAGER_IncreaseSeconds(uint8_t amount);

void CLOCK_MANAGER_IncreaseMinutes(uint8_t amount);

void CLOCK_MANAGER_IncreaseHours(uint8_t amount);

#endif	/* CLOCK_MANAGER_H */

