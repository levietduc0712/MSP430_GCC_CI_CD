#include <gpio.h>
#include <clock_init.h>

#define INTERVAL 500

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    clock_init();                           // Initialize clock to 16MHz
    timerA_init();

    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P9, GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P9, GPIO_PIN2);

    unsigned long previousMillis = 0;

    while(1)
    {

        unsigned long currentMillis = millis();

        if ((currentMillis - previousMillis) >= INTERVAL) {
            GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
            GPIO_toggleOutputOnPin(GPIO_PORT_P9, GPIO_PIN7);
            GPIO_toggleOutputOnPin(GPIO_PORT_P9, GPIO_PIN2);
            previousMillis = currentMillis;  // Update the last time toggling happened
        }

    }

}
