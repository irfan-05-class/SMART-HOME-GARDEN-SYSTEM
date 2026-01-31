#include "logic.h"
#include "adc.h"
#include "stm32f4xx.h"
#include "interrupts.h"

void Handle_Soil_Logic(void) {
    uint32_t soilValue = Read_ADC(0);

    if (soilValue > 3000 && buzzer_silenced == 0) {
        GPIOD->BSRR = (1 << 2);
    } else {
        GPIOD->BSRR = (1 << (2 + 16));
        if (soilValue < 1500) buzzer_silenced = 0;
    }
}

void Handle_LDR_Logic(void) {
    uint32_t lightValue = Read_ADC(1);
    uint32_t ledMask = (0xF << 12);

    if (lightValue < 2000)
        GPIOB->BSRR = (ledMask << 16);
    else
        GPIOB->BSRR = ledMask;
}
