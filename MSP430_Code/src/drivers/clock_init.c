#include <clock_init.h>

#define MICROSECONDS_PER_TIMER0_OVERFLOW 1000               // 1 ms overflow
#define MILLIS_INC (MICROSECONDS_PER_TIMER0_OVERFLOW / 1000)
#define FRACT_INC ((MICROSECONDS_PER_TIMER0_OVERFLOW % 1000) >> 3)
#define FRACT_MAX (1000 >> 3)

volatile unsigned long timer0_overflow_count = 0;
volatile unsigned long timer0_millis = 0;

/**
 * @brief Function to initialize the clock to 16 MHz.
 * 
 */
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

/**
 * @brief Function to delay for a specified number of milliseconds.
 * 
 * @param ms Number of milliseconds to delay
 */
void delay_ms(unsigned int ms) {
    while (ms--) {
        TA1CCTL0 = CCIE;                                    // TACCR0 interrupt enabled
        TA1CCR0 = 16000 - 1;                                // Set delay for 1 ms (assuming 16 MHz clock)
        TA1CTL = TASSEL__SMCLK | MC__UP;

        __bis_SR_register(LPM0_bits + GIE);                 // Enter low-power mode 0 with interrupts enabled
        __no_operation();                                   // For debugger
    }

    TA1CTL = MC__STOP;                                      // Stop Timer A1 after delay
    TA1CCTL0 &= ~CCIE;                                      // Disable CCR0 interrupt
}

/**
 * @brief Function to initialize Timer A0.
 * 
 */
void timerA_init(void) {
    TA0CCR0 = 16000 - 1;                                    // 1 ms at 16 MHz
    TA0CTL = TASSEL_2 + MC_1 + TACLR;                       // SMCLK, up mode, clear TAR
    TA0CCTL0 = CCIE;                                        // Enable CCR0 interrupt
}

/**
 * @brief Function to return the number of milliseconds since the program started.
 * 
 * @return unsigned long Number of milliseconds
 */
unsigned long millis() {
    unsigned long m;
    __disable_interrupt();                                  // Disable interrupts
    m = timer0_millis;
    __enable_interrupt();                                   // Enable interrupts
    return m;
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
    static unsigned char timer0_fract = 0;
    unsigned long m = timer0_millis;
    unsigned char f = timer0_fract;

    m += MILLIS_INC;
    f += FRACT_INC;
    if (f >= FRACT_MAX) {
        f -= FRACT_MAX;
        m += 1;
    }

    timer0_fract = f;
    timer0_millis = m;
    timer0_overflow_count++;

}

// Timer1_A0 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = TIMER1_A0_VECTOR
__interrupt void Timer1_A0_ISR (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER1_A0_VECTOR))) Timer1_A0_ISR (void)
#else
#error Compiler not supported!
#endif
{
    TA1CTL = 0;                                               // Clear the timer
    TA1CCTL0 &= ~CCIE;                                        // Disable the interrupt
    __bic_SR_register_on_exit(LPM0_bits);                     // Exit LPM0

}
