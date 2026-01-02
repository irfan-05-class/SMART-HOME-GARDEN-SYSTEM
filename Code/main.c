#include "stm32f4xx_hal.h"

//GLOBAL VARIABLE DEFINITION
int alertState = 0;

//function prototypes
void my_LED_Toggle(void);
void SystemClock_Config(void);
void MX_GPIO_Init(void);

int main(void){
	//initialize hardware abstraction layer
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	
	while(1){
		//main loop stays empty; logic is in the interrupt
	}
}

void SystemClock_Config(void){
}
void MX_GPIO_Init(void){
}
