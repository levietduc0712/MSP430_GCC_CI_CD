#include <gpio.h>
#include <clock_init.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    clock_init();
    
    gpio_init(GPIO_PORT_P1, GPIO_PIN0, GPIO_DIR_OUTPUT, GPIO_OUT_LOW);
    gpio_init(GPIO_PORT_P9, GPIO_PIN7, GPIO_DIR_OUTPUT, GPIO_OUT_LOW);

    while(1)
    {
        gpio_set(GPIO_PORT_P1, GPIO_PIN0, GPIO_OUT_HIGH);
        gpio_set(GPIO_PORT_P9, GPIO_PIN7, GPIO_OUT_HIGH);
        __delay_cycles(16000000);
        gpio_set(GPIO_PORT_P1, GPIO_PIN0, GPIO_OUT_LOW);
        gpio_set(GPIO_PORT_P9, GPIO_PIN7, GPIO_OUT_LOW);
        __delay_cycles(16000000);
    }
    
}
