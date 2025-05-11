/*
 * lifo.h
 *
 *  Created on: May 11, 2025
 *      Author: Muhamad Elalawy
 */

#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"
#include "stdlib.h"
//=====Type Definitions=====//
typedef struct{
	unsigned int length;
	unsigned int count;
	unsigned int * base;
	unsigned int * head;

}LIFO_BUF_t;

typedef enum{
	LIFO_NO_ERRO,
	LIFO_FULL,
	LIFO_EMPTY,//there is no data yet
	LIFO_NULL,//this lifo doesn't exist.

}LIFO_status;


//=====      APIs     =====//
LIFO_status LIFO_init(LIFO_BUF_t * LIFO_buffer, unsigned int *buf, unsigned int length);

LIFO_status LIFO_add_item(LIFO_BUF_t * LIFO_buffer , unsigned int item);

LIFO_status LIFO_get_item(LIFO_BUF_t * LIFO_buffer , unsigned int *item);



#endif /* LIFO_H_ */
