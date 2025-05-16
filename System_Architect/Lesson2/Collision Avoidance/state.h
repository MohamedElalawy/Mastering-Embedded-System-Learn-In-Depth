/*
 * state.h
 *
 *  Created on: May 16, 2025
 *      Author: mm
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"


//Automatic state function generated


#define STATE_define(_statFun_) void ST_##_statFun_()
#define STATE(_statFun_) ST_##_statFun_

//states connection
void US_get_distance(int dist);
void DC_motor_set_speed(int speed);



#endif /* STATE_H_ */
