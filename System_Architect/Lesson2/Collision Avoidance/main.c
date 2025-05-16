/*
 * main.c
 *
 *  Created on: May 16, 2025
 *      Author: Muhamad Elalawy
 */

#include "ca.h"
#include "dc_motor.h"
#include "us_sensor.h"


void setup(){

	//init all drivers
	//init IRQ
	//init HAL
	//init Block
	//set state pointers for each block
	US_init();
	DC_init();
	pCA_state = STATE(CA_waiting);
	pDC_state = STATE(DC_idle);
	pUS_state = STATE(US_busy);
}
void main(){
	int i;
	setup();
	while (1){

		pUS_state();
		pCA_state();
		pDC_state();
		for(i = 0 ; i < 50000 ; i ++);

	}




}



