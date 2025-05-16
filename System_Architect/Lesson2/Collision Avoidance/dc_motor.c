/*
 * DC.c
 *
 *  Created on: May 16, 2025
 *      Author: Muhamad Elalawy
 */
#include "dc_motor.h"

//variables
static int DC_speed = 0;


//state pointer to function
void (*pDC_state)();



//APIs

void DC_init(){

	printf("DC_init.. \n");
}

void DC_motor(int s){
	DC_speed = s;
	pDC_state = STATE(DC_busy);
	printf("CA module sending speed = %d to DC module\n",DC_speed);

}

STATE_define(DC_idle){
	DC_state_id = DC_idle;
	printf("DC_idle state: speed = %d \n" , DC_speed);

}
STATE_define(DC_busy){
	DC_state_id = DC_busy;
	printf("DC_busy state: speed = %d \n" , DC_speed);
	pDC_state = STATE(DC_idle);
}

