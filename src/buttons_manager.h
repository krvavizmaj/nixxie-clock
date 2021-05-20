#ifndef BUTTONS_MANAGER_H
#define	BUTTONS_MANAGER_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define BUTTON1             0x00
#define BUTTON2             0x01
#define BUTTON3             0x02

#define BUTTON_RELEASED     0x00
#define BUTTON_PRESSED      0x01
#define BUTTON_DEBOUNCED    0x02
#define BUTTON_HANDLED      0x04

void BUTTONS_MANAGER_Initialize(void);

void BUTTONS_MANAGER_UpdateButtonsState(int buttonNumber);

void BUTTONS_MANAGER_TimerOverflowHandler(void);

void BUTTONS_MANAGER_ButtonPressHandled(int buttonNumber);

int BUTTONS_MANAGER_GetButtonState(int buttonNumber);

#endif	/* BUTTONS_MANAGER_H */

