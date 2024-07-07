#include <msp430.h>

void blink_fast(void) {
    P1DIR |= 0x02; // Set P1.1 to output direction

    while (1) {
        P1OUT ^= 0x02; // Toggle P1.1 using exclusive-OR
        __delay_cycles(50000)
    }
}
