#ifndef MCC_H
#define	MCC_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "device_config.h"
#include "pin_manager.h"
#include "interrupt_manager.h"
#include "tmr0.h"

void SYSTEM_Initialize(void);

void ADCON_Enable(void);

void ADCON_Disable(void);

#endif	/* MCC_H */
