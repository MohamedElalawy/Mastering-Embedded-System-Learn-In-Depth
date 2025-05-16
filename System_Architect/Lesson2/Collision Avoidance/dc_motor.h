/*
 * dc_motor.h
 *
 *  Created on: May 16, 2025
 *      Author: Muhamad Elalawy
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"

enum {
	DC_idle,
	DC_busy

}DC_state_id;

//APIs
STATE_define(DC_idle);
STATE_define(DC_busy);
void DC_init();

//state pointer to function
extern void (*pDC_state)();





#endif /* DC_H_ */
