#include "adc.h"
#include "stm32f4xx.h"

uint32_t Read_ADC(uint32_t channel) {
    ADC1->SQR3 = channel;
    ADC1->CR2 |= ADC_CR2_SWSTART;
    while(!(ADC1->SR & ADC_SR_EOC));
    return ADC1->DR;
}
