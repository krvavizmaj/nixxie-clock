#ifndef CLOCK_MANAGER_H
#define	CLOCK_MANAGER_H

#include <xc.h>

#define HOURS_PORT      PORTA
#define MINUTES_PORT    PORTB
#define SECONDS_PORT    PORTD

void CLOCK_MANAGER_Initialize(void);

void CLOCK_MANAGER_IncreaseSeconds(void);

void CLOCK_MANAGER_IncreaseMinutes(void);

void CLOCK_MANAGER_IncreaseHours(void);

#endif	/* CLOCK_MANAGER_H */

