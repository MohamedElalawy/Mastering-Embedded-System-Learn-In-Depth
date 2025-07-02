/*
 * stm32f103c6_EXTI_Driver.c
 *
 *  Created on: Jun 14, 2025
 *      Author: Muhamad Elalawy
 */

#include "stm32f103c6_EXTI_Driver.h"
#include "stm32f103c6_GPIO_Driver.h"



//--------------------------------------------
//Generic Var :
//--------------------------------------------
void (* GP_IRQ_CALLBACK[15])(void);

//--------------------------------------------
//Generic Macros :
//--------------------------------------------

#define AFIO_GPIO_EXTI_Mapping(x) 	   ((x==GPIOA)?0:\
										(x==GPIOB)?1:\
										(x==GPIOC)?2:\
										(x==GPIOD)?3:0 )

//--------------------------------------------
//Generic Functions :
//--------------------------------------------
void Enable_NVIC (uint16_t IRQ){

	switch (IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_ENABLE;
		break;

	case 1:
		NVIC_IRQ7_EXTI1_ENABLE;
		break;

	case 2:
		NVIC_IRQ8_EXTI2_ENABLE;
		break;

	case 3:
		NVIC_IRQ9_EXTI3_ENABLE;
		break;

	case 4:
		NVIC_IRQ10_EXTI4_ENABLE;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_ENABLE;
		break;

	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_ENABLE;
		break;

	}



}


void Disable_NVIC (uint16_t IRQ){
	switch (IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_DISABLE;
		break;

	case 1:
		NVIC_IRQ7_EXTI1_DISABLE;
		break;

	case 2:
		NVIC_IRQ8_EXTI2_DISABLE;
		break;

	case 3:
		NVIC_IRQ9_EXTI3_DISABLE;
		break;

	case 4:
		NVIC_IRQ10_EXTI4_DISABLE;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_DISABLE;
		break;

	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_DISABLE;
		break;

	}




}





void MCAL_EXTI_GPIO_INIT(EXTI_PinConfig_t * EXTI_Config){

	//config GPIO to be AF-> floating input
	GPIO_Pin_Config_t PinConfig;

	PinConfig.GPIO_Pin_Number = EXTI_Config->EXTI_PIN.GPIO_PIN ;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &PinConfig);

	//update AFIO to route between EXTI line with PORT A,B,C,d
	uint8_t AFIO_EXTICR_index = (EXTI_Config->EXTI_PIN.ETI_InputLineNumber / 4);
	uint8_t AFIO_EXTICR_Position = (EXTI_Config->EXTI_PIN.ETI_InputLineNumber % 4) * 4;

	//clear the 4 bits first
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port)&0xF )<<AFIO_EXTICR_Position );

	//Update the rising or falling edge
	EXTI->RTSR &= ~(1<<EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	EXTI->FTSR &= ~(1<<EXTI_Config->EXTI_PIN.ETI_InputLineNumber);

	if(EXTI_Config->Trigger_case == EXTI_Trigger_Rising){
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	}
	else if(EXTI_Config->Trigger_case == EXTI_Trigger_Falling){
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	}
	else if(EXTI_Config->Trigger_case == EXTI_Trigger_RisingAndFalling){

		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	}


	//update the IRQ handling callback
	GP_IRQ_CALLBACK[EXTI_Config->EXTI_PIN.ETI_InputLineNumber] = EXTI_Config->P_IRQ_CALLBACK;

	//enable or disable the IRQ and NVIC
	if(EXTI_Config->IRQ_EN == EXTI_IRQ_ENABLE ){

		EXTI->IMR |= (1<<EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
		Enable_NVIC (EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	}
	else
	{

		EXTI->IMR &= ~(1<<EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
		Disable_NVIC (EXTI_Config->EXTI_PIN.ETI_InputLineNumber);

	}

}


void MCAL_EXTI_GPIO_DEINIT(void){

	EXTI->IMR = 0x00000000;
	EXTI->EMR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR = 0xFFFFFFFF;//cleared by writing 1


	//Disable EXTI IRQ from NVIC
	NVIC_IRQ6_EXTI0_DISABLE;
	NVIC_IRQ7_EXTI1_DISABLE;
	NVIC_IRQ8_EXTI2_DISABLE;
	NVIC_IRQ9_EXTI3_DISABLE;
	NVIC_IRQ10_EXTI4_DISABLE;
	NVIC_IRQ23_EXTI5_9_DISABLE;
	NVIC_IRQ40_EXTI10_15_DISABLE;


}



void MCAL_EXTI_GPIO_UPDATE(EXTI_PinConfig_t * EXTI_Config){
	MCAL_EXTI_GPIO_INIT(EXTI_Config);

}




//--------------------------------------------
//ISR Functions :
//--------------------------------------------
void EXTI0_IRQHandler(void){
	//clear EXTI->PR by writing 1 on it
	EXTI->PR |= (1<<0);
	//call corresponding GP_IRQ_CALLBACK
	GP_IRQ_CALLBACK[0]();
}

void EXTI1_IRQHandler(void){
	//clear EXTI->PR by writing 1 on it
	EXTI->PR |= (1<<1);
	//call corresponding GP_IRQ_CALLBACK
	GP_IRQ_CALLBACK[1]();
}

void EXTI2_IRQHandler(void){
	//clear EXTI->PR by writing 1 on it
	EXTI->PR |= (1<<2);
	//call corresponding GP_IRQ_CALLBACK
	GP_IRQ_CALLBACK[2]();
}

void EXTI3_IRQHandler(void){
	//clear EXTI->PR by writing 1 on it
	EXTI->PR |= (1<<3);
	//call corresponding GP_IRQ_CALLBACK
	GP_IRQ_CALLBACK[3]();
}


void EXTI4_IRQHandler(void){
	//clear EXTI->PR by writing 1 on it
	EXTI->PR |= (1<<4);
	//call corresponding GP_IRQ_CALLBACK
	GP_IRQ_CALLBACK[4]();
}


void EXTI9_5_IRQHandler(void){


	if(EXTI->PR & 1<<5){EXTI->PR |= (1<<5) ; GP_IRQ_CALLBACK[5]();}
	if(EXTI->PR & 1<<6){EXTI->PR |= (1<<6) ; GP_IRQ_CALLBACK[6]();}
	if(EXTI->PR & 1<<7){EXTI->PR |= (1<<7) ; GP_IRQ_CALLBACK[7]();}
	if(EXTI->PR & 1<<8){EXTI->PR |= (1<<8) ; GP_IRQ_CALLBACK[8]();}
	if(EXTI->PR & 1<<9){EXTI->PR |= (1<<9) ; GP_IRQ_CALLBACK[9]();}


}


void EXTI15_10_IRQHandler(void){


	if(EXTI->PR & 1<<10){EXTI->PR |= (1<<10) ; GP_IRQ_CALLBACK[10]();}
	if(EXTI->PR & 1<<11){EXTI->PR |= (1<<11) ; GP_IRQ_CALLBACK[11]();}
	if(EXTI->PR & 1<<12){EXTI->PR |= (1<<12) ; GP_IRQ_CALLBACK[12]();}
	if(EXTI->PR & 1<<13){EXTI->PR |= (1<<13) ; GP_IRQ_CALLBACK[13]();}
	if(EXTI->PR & 1<<14){EXTI->PR |= (1<<14) ; GP_IRQ_CALLBACK[14]();}
	if(EXTI->PR & 1<<15){EXTI->PR |= (1<<15) ; GP_IRQ_CALLBACK[15]();}


}





