#include <clock_init.h>

void clock_init(void) {
    // Disable the GPIO power-on default high-impedance mode to activate
    // previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;

    // Configure one FRAM waitstate as required by the device datasheet for MCLK
    // operation beyond 8MHz _before_ configuring the clock system.
    FRCTL0 = FRCTLPW | NWAITS_1;

    // Clock System Setup
    CSCTL0_H = CSKEY >> 8;                                  // Unlock CS registers
    CSCTL1 = DCOFSEL_4 | DCORSEL;                           // Set DCO to 16MHz
    CSCTL2 = SELA__VLOCLK | SELS__DCOCLK | SELM__DCOCLK;    // Set SMCLK = MCLK = DCO,
                                                            // ACLK = VLOCLK
    CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1;                   // Set all dividers
    CSCTL0_H = 0;                                           // Lock CS registers
}