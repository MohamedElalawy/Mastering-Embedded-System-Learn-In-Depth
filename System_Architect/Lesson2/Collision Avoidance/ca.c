/*
 * ca.c
 *
 *  Created on: May 16, 2025
 *      Author: Muhamad Elalawy
 */
#include "ca.h"

//variables
static int CA_speed = 0;
static int CA_distance =0;
static int CA_threshold=50;

//state pointer to function
void (*pCA_state)();



//APIs
void US_get_distance(int dist){


	CA_distance = dist;
	(CA_distance <= CA_threshold)? (pCA_state = STATE(CA_driving)) :(pCA_state = STATE(CA_waiting));
	printf("US module sending distance = %d to CA module\n",CA_distance);
}



STATE_define(CA_waiting){
	CA_state_id = CA_waiting;
	printf("CA_waiting state: distance = %d , Speed = %d \n",CA_distance,CA_speed);
	CA_speed = 0;
	DC_motor(CA_speed);
}
STATE_define(CA_driving){
	CA_state_id = CA_driving;
	printf("CA_driving state: distance = %d , Speed = %d \n",CA_distance , CA_speed);
	CA_speed = 25;
	DC_motor(CA_speed);
}


