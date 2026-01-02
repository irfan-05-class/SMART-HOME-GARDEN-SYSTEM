#include "stm32f4xx_hal.h"

//extern : variable created in main file
extern int alertState;

//this function is in led_control file
extern void my_LED_Toggle(void);

//interrupt
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	//check if interrupt come from PC13 (blue button)
	if (GPIO_Pin == GPIO_PIN_13){
		//call subroutine
		my_LED_Toggle();
		
		//flip state flag
		if (alertState == 0){
			alertState = 1;
		}
		else{
			alertState = 0;
		}
	}
}