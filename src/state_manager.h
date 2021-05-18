#ifndef STATE_MANAGER_H
#define	STATE_MANAGER_H

#include <xc.h> // include processor files - each processor file is guarded.  

// states of the clock
#define SHOWING_TIME    0x00
#define SETTING_TIME    0x01

void STATE_MANAGER_Init(void);

void STATE_MANAGER_HandleHalfSecondMark(void);

void STATE_MANAGER_HandleFullSecondMark(void);

void STATE_MANAGER_HandleButton1Press(void);

void STATE_MANAGER_HandleButton2Press(void);

#endif	/* STATE_MANAGER_H */