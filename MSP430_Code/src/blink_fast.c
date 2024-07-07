#include <msp430.h>

// Declaration of the blink_fast function
void blink_fast(void);

void main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    P1DIR |= 0x01; // Set P1.0 to output direction

    // Create a condition to call blink_fast function
    if (P1IN & 0x04) { // If P1.2 is high
        blink_fast();
    } else {
        while (1) {
            P1OUT ^= 0x01; // Toggle P1.0 using exclusive-OR
            __delay_cycles(100000);
        }
    }
}
