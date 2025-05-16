/*
 * US.h
 *
 *  Created on: May 16, 2025
 *      Author: Muhamad Elalawy
 */

#ifndef US_H_
#define US_H_

#include "state.h"

enum {
	US_busy,


}US_state_id;

//APIs
STATE_define(US_busy);
void US_init();

//state pointer to function
extern void (*pUS_state)();





#endif /* US_H_ */
