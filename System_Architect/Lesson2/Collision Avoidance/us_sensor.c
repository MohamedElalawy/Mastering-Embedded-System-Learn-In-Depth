/*
 * US.c
 *
 *  Created on: May 16, 2025
 *      Author: Muhamad Elalawy
 */
#include "us_sensor.h"

//variables
static int US_distance =0;

//state pointer to function
void (*pUS_state)();



//APIs
int US_get_distance_rand(int min , int max , int count){
	int i;
	for(i = 0; i<count ; i++){
		int rand_num=(rand()%(max-min+1))+min;
		return rand_num;
	}
}

void US_init(){
	printf("US_init.. \n");

}

STATE_define(US_busy){
	US_state_id = US_busy;
	US_distance = US_get_distance_rand(40,60,1);
	printf("US_waiting state: distance = %d \n",US_distance);
	US_get_distance(US_distance);
	pUS_state= STATE(US_busy);
}




