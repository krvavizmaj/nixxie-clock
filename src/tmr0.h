#ifndef TMR0_H
#define TMR0_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

void TMR0_Initialize(void);

void TMR0_EnableTimer(void);

void TMR0_DisableTimer(void);

uint8_t TMR0_ReadTimer(void);

void TMR0_WriteTimer(uint8_t timerVal);

void TMR0_ISR(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // TMR0_H
