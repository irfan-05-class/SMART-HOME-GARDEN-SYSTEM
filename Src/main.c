#include "stm32f4xx.h"
#include "system_init.h"
#include "interrupts.h"
#include "logic.h"

int main(void) {
    System_Init();
    Init_Interrupts();

    while (1) {
        Handle_Soil_Logic();
        Handle_LDR_Logic();
    }
}
