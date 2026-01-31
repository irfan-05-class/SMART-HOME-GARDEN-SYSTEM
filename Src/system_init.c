#include "system_init.h"
#include "stm32f4xx.h"

void System_Init(void) {
    // Clock enable
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN |
                    RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIODEN;
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN | RCC_APB2ENR_SYSCFGEN;

    // GPIO and ADC setup (same as your code)
}
