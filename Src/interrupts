#include "interrupts.h"
#include "stm32f4xx.h"
#include "delay.h"

volatile int button_led_state = 0;
volatile int buzzer_silenced = 0;

void EXTI2_IRQHandler(void) {
    if (EXTI->PR & EXTI_PR_PR2) {
        button_led_state ^= 1;
        if (button_led_state) GPIOC->BSRR = 0x0000FFFF;
        else                  GPIOC->BSRR = 0xFFFF0000;

        delay_ms(200);
        EXTI->PR = EXTI_PR_PR2;
    }
}

void EXTI3_IRQHandler(void) {
    if (EXTI->PR & EXTI_PR_PR3) {
        buzzer_silenced = 1;
        GPIOD->BSRR = (1 << (2 + 16));
        delay_ms(200);
        EXTI->PR = EXTI_PR_PR3;
    }
}
