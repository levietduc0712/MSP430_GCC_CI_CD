#ifndef __MSP430FR6989_CLOCK_INIT_H__
#define __MSP430FR6989_CLOCK_INIT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <msp430.h>

void clock_init(void);
void delay_ms(unsigned int ms);
void timerA_init(void);
unsigned long millis();

#ifdef __cplusplus
}
#endif

#endif // __MSP430FR6989_CLOCK_INIT_H__
