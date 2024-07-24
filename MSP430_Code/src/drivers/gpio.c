// Code was written by: Viet Duc
// This code is the driver for the GPIO module of the MSP430FR5994. 
// It allows the user to initialize the GPIO port.

#include <gpio.h>

/**
 * @brief The gpio_init function initializes the GPIO port, pin, direction, and output.
 * 
 * @param port Port number
 * @param pin Pin number
 * @param dir Input or Output
 * @param out High or Low
 */
void gpio_init(unsigned int port, unsigned int pin, unsigned int dir, unsigned int out)
{
    switch(port)
    {
        case GPIO_PORT_P1:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P1DIR |= pin;
            }
            else
            {
                P1DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P1OUT |= pin;
            }
            else
            {
                P1OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P2:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P2DIR |= pin;
            }
            else
            {
                P2DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P2OUT |= pin;
            }
            else
            {
                P2OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P3:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P3DIR |= pin;
            }
            else
            {
                P3DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P3OUT |= pin;
            }
            else
            {
                P3OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P4:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P4DIR |= pin;
            }
            else
            {
                P4DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P4OUT |= pin;
            }
            else
            {
                P4OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P5:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P5DIR |= pin;
            }
            else
            {
                P5DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P5OUT |= pin;
            }
            else
            {
                P5OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P6:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P6DIR |= pin;
            }
            else
            {
                P6DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P6OUT |= pin;
            }
            else
            {
                P6OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P7:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P7DIR |= pin;
            }
            else
            {
                P7DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P7OUT |= pin;
            }
            else
            {
                P7OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P8:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P8DIR |= pin;
            }
            else
            {
                P8DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P8OUT |= pin;
            }
            else
            {
                P8OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P9:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P9DIR |= pin;
            }
            else
            {
                P9DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P9OUT |= pin;
            }
            else
            {
                P9OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P10:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P10DIR |= pin;
            }
            else
            {
                P10DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P10OUT |= pin;
            }
            else
            {
                P10OUT &= ~pin;
            }
            break;
    }
}

/**
 * @brief The gpio_set function sets the GPIO port and pin to high or low.
 * 
 * @param port Port number
 * @param pin Pin number
 * @param out High or Low
 */
void gpio_set(unsigned int port, unsigned int pin, unsigned int out) {
    switch(port)
    {
        case GPIO_PORT_P1:
            if (out == GPIO_OUT_HIGH)
            {
                P1OUT |= pin;
            }
            else
            {
                P1OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P2:
            if (out == GPIO_OUT_HIGH)
            {
                P2OUT |= pin;
            }
            else
            {
                P2OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P3:
            if (out == GPIO_OUT_HIGH)
            {
                P3OUT |= pin;
            }
            else
            {
                P3OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P4:
            if (out == GPIO_OUT_HIGH)
            {
                P4OUT |= pin;
            }
            else
            {
                P4OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P5:
            if (out == GPIO_OUT_HIGH)
            {
                P5OUT |= pin;
            }
            else
            {
                P5OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P6:
            if (out == GPIO_OUT_HIGH)
            {
                P6OUT |= pin;
            }
            else
            {
                P6OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P7:
            if (out == GPIO_OUT_HIGH)
            {
                P7OUT |= pin;
            }
            else
            {
                P7OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P8:
            if (out == GPIO_OUT_HIGH)
            {
                P8OUT |= pin;
            }
            else
            {
                P8OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P9:
            if (out == GPIO_OUT_HIGH)
            {
                P9OUT |= pin;
            }
            else
            {
                P9OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P10:
            if (out == GPIO_OUT_HIGH)
            {
                P10OUT |= pin;
            }
            else
            {
                P10OUT &= ~pin;
            }
            break;
    }
}

/**
 * @brief The gpio_toggle function toggles the GPIO port and pin.
 * 
 * @param port Port number
 * @param pin Pin number
 */
void gpio_toggle(unsigned int port, unsigned int pin) {
    switch(port)
    {
        case GPIO_PORT_P1:
            P1OUT ^= pin;
            break;
        case GPIO_PORT_P2:
            P2OUT ^= pin;
            break;
        case GPIO_PORT_P3:
            P3OUT ^= pin;
            break;
        case GPIO_PORT_P4:
            P4OUT ^= pin;
            break;
        case GPIO_PORT_P5:
            P5OUT ^= pin;
            break;
        case GPIO_PORT_P6:
            P6OUT ^= pin;
            break;
        case GPIO_PORT_P7:
            P7OUT ^= pin;
            break;
        case GPIO_PORT_P8:
            P8OUT ^= pin;
            break;
        case GPIO_PORT_P9:
            P9OUT ^= pin;
            break;
        case GPIO_PORT_P10:
            P10OUT ^= pin;
            break;
    }
}