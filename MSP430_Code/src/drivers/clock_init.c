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

void delay_ms(unsigned int ms) {
    while (ms --)
    {
        __delay_cycles(16000);                              // 1ms at 16MHz
    }
}

void delay_ms2(unsigned int ms) {
    while (ms --)
    {
        TA0CCTL0 = CCIE;                                    // TACCR0 interrupt enabled
        TA0CCR0 = 16000 - 1;                                // 1ms at 16MHz
        TA0CTL = TASSEL__SMCLK | MC__UP;                    // Set clock source is SMCLK, UP mode

        __bis_SR_register(LPM0_bits + GIE);                 // Enter LPM0 w/ interrupt
        __no_operation();                                   // For debugger
    }
}

// Timer0_A0 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer0_A0_ISR (void)
#else
#error Compiler not supported!
#endif
{
  TA0CTL = 0;                                                // Clear the timer
  TA0CCTL0 &= ~CCIE;                                        // Disable the interrupt
  __bic_SR_register_on_exit(LPM0_bits);                     // Exit LPM0
}