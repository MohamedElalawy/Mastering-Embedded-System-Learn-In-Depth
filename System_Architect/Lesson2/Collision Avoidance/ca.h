/*
 * ca.h
 *
 *  Created on: May 16, 2025
 *      Author: Muhamad Elalawy
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

enum {
	CA_waiting,
	CA_driving

}CA_state_id;

//APIs
STATE_define(CA_waiting);
STATE_define(CA_driving);
int US_get_distance_rand(int min , int max , int count);


//state pointer to function
extern void (*pCA_state)();





#endif /* CA_H_ */
