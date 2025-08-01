/*
 * stm32f103x6.h
 *
 *  Created on: Jun 14, 2025
 *      Author: Muhamad Elalawy
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//--------------------------------------------
//Includes
//--------------------------------------------

#include "stdlib.h"
#include "stdint.h"
//--------------------------------------------
//Base addresses for Memories
//--------------------------------------------

#define FLASH_MEMORY_BASE_ADDRESS							0x08000000ul
#define SYSTEM_MEMORY_BASE_ADDRESS							0x1FFFF000ul
#define SRAM_MEMORY_BASE_ADDRESS							0x20000000ul
#define PERIPHERALS_BASE_ADDRESS							0x40000000ul
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE_ADDRESS			0xE0000000ul

#define NVIC_BASE_ADDRESS									0xE000E100ul

#define NVIC_ISER0 											*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x0)
#define NVIC_ISER1 											*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x4)
#define NVIC_ISER2 											*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x8)
#define NVIC_ICER0 											*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x80)
#define NVIC_ICER1 											*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x84)
#define NVIC_ICER2 											*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x88)











//--------------------------------------------
//Base addresses for APB2 BUS Peripherals
//--------------------------------------------
//GPIO

//POERT A&B FULLY INCLUDED IN LQFP48 PACKAGE
#define GPIOA_BASE_ADDRESS									0x40010800ul
#define GPIOB_BASE_ADDRESS									0x40010C00ul

//POERT C&D PARTIALLY INCLUDED IN LQFP48 PACKAGE
#define GPIOC_BASE_ADDRESS									0x40011000ul
#define GPIOD_BASE_ADDRESS									0x40011400ul

//POERT E NOT INCLUDED IN LQFP48 PACKAGE
#define GPIOE_BASE_ADDRESS									0x40011800ul

//EXTI
#define EXTI_BASE_ADDRESS									0x40010400ul

//AFIO
#define AFIO_BASE_ADDRESS									0x40010000ul


//--------------------------------------------
//Base addresses for AHB BUS Peripherals
//--------------------------------------------

//RCC
#define RCC_BASE_ADDRESS									0x40021000ul




//********************************************
//Peripheral register:
//********************************************

//********************************************
//Peripheral registers: GPIO
//********************************************

typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;




//********************************************
//Peripheral registers: EXTI
//********************************************

typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;


//********************************************
//Peripheral registers: RCC
//********************************************

typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
}RCC_TypeDef;


//********************************************
//Peripheral registers: AFIO
//********************************************

typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
			 uint32_t RESERVED0;
	volatile uint32_t MAPR2;
}AFIO_TypeDef;




//********************************************
//Peripheral Instants:
//********************************************

#define GPIOA   					((GPIO_TypeDef*)GPIOA_BASE_ADDRESS)
#define GPIOB   					((GPIO_TypeDef*)GPIOB_BASE_ADDRESS)
#define GPIOC   					((GPIO_TypeDef*)GPIOC_BASE_ADDRESS)
#define GPIOD   					((GPIO_TypeDef*)GPIOD_BASE_ADDRESS)
#define GPIOE   					((GPIO_TypeDef*)GPIOE_BASE_ADDRESS)


#define RCC							((RCC_TypeDef*)RCC_BASE_ADDRESS)


#define EXTI						((EXTI_TypeDef*)EXTI_BASE_ADDRESS)


#define AFIO						((AFIO_TypeDef*)AFIO_BASE_ADDRESS)



//********************************************
//clock enable Macros:
//********************************************

#define RCC_GPIOA_CLK_EN()    		(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()    		(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()    		(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()    		(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()    		(RCC->APB2ENR |= 1<<6)

#define RCC_AFIO_CLK_EN()    		(RCC->APB2ENR |= 1<<0)



//********************************************
//EXTI Macros:
//********************************************
#define EXTI0_IRQ		6
#define EXTI1_IRQ		7
#define EXTI2_IRQ		8
#define EXTI3_IRQ		9
#define EXTI4_IRQ		10
#define EXTI5_IRQ		23
#define EXTI6_IRQ		23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40



//********************************************
//NVIC IRQ Enable, Disable Macros:
//********************************************

#define NVIC_IRQ6_EXTI0_ENABLE 			(NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_ENABLE 			(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_ENABLE  		(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_ENABLE  		(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_ENABLE  		(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_ENABLE 		(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_ENABLE 	(NVIC_ISER1 |= 1<<8)	// Note: 40-32 = bit 8 in ISER1/ICER1


#define NVIC_IRQ6_EXTI0_DISABLE           (NVIC_ICER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_DISABLE           (NVIC_ICER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_DISABLE           (NVIC_ICER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_DISABLE           (NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_DISABLE          (NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_DISABLE        (NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_DISABLE      (NVIC_ICER1 |= 1<<8) // Note: 40-32 = bit 8 in ISER1/ICER1


















//********************************************
//Generic Macros:
//********************************************


#endif /* INC_STM32F103X6_H_ */
