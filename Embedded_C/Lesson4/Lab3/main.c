/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Muhamad Elalawy
 * @brief          : Main program body
 ******************************************************************************
 * Tiva C -> TM4C123
 ******************************************************************************
 */

#include <stdint.h>


#define SYSCTL_RCGC2_R (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DIR_R (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R (*((volatile unsigned long*)0x4002551C))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long*)0x400253FC))
void delay() {
    for (volatile long i = 0; i < 50000; ++i);//volatile to avoid optimization so the the following loop isn't ignored
}

int main(){
	
	SYSCTL_RCGC2_R = 0x20;
	//delay to make sure the gpiof is up and running
	delay();
	
	GPIO_PORTF_DIR_R |= 1<<3;//pin configured as output
	GPIO_PORTF_DEN_R |= 1<<3;//pin enable
	
	while (1) {
        GPIO_PORTF_DATA_R &= ~(1<<3); // reset led
        delay();
        GPIO_PORTF_DATA_R |= 1<<3; // Set led
        delay();
    }
	return 0;
}