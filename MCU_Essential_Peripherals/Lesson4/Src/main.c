/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f103c6_GPIO_Driver.h"
#include "stm32f103c6_EXTI_Driver.h"
#include "stm32f103x6.h"
#include "keypad.h"
#include "lcd.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void clock_init(){
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();

}

void gpio_init(){
	GPIO_Pin_Config_t gpio_Pin_Config;

	gpio_Pin_Config.GPIO_Pin_Number = GPIO_PIN_1;
	gpio_Pin_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &gpio_Pin_Config);


	gpio_Pin_Config.GPIO_Pin_Number = GPIO_PIN_13;
	gpio_Pin_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &gpio_Pin_Config);


	gpio_Pin_Config.GPIO_Pin_Number = GPIO_PIN_1;
	gpio_Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	gpio_Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &gpio_Pin_Config);


	gpio_Pin_Config.GPIO_Pin_Number = GPIO_PIN_13;
	gpio_Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	gpio_Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &gpio_Pin_Config);

}





void delay(int time) {
    for (int i = 0; i < time; i++) {
        for (int j = 0; j < 255; j++);
    }
}
int main(void)
{
	/*
	EXTI_PinConfig_t EXTI_CFG ;

	EXTI_CFG.EXTI_PIN = EXTI9PA9 ;

*/




	while(1){




	}





/*
 *
 *
 *
 *
 *
 *
	clock_init();
	gpio_init();


	 for(;;){

		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0){

			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0); //SINGLE PRESSING

		}
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13)==1){

			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
			while(MCAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1)==1); //Multi PRESSING

		}

		delay(1000);

	}
*/

}
