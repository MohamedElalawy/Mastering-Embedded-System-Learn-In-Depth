/*
 * fifo.h
 *
 *  Created on: May 13, 2025
 *      Author: mm
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

//User Configuration:
//Select the element type[uint8_t, uint16_t, ...]
#define element_type uint8_t

//Create buff
#define width1 5
element_type uart_buffer[width1];

//fifo datatypes:

typedef struct {
	uint32_t length;
	uint32_t count;
	element_type* base;
	element_type* head;
	element_type* tail;


}FIFO_BUF_t;

typedef enum{
	FIFO_NO_ERRO,
	FIFO_FULL,
	FIFO_EMPTY,//there is no data yet
	FIFO_NULL,//this fifo doesn't exist.

}FIFO_status;


//=====      APIs     =====//
FIFO_status FIFO_init(FIFO_BUF_t * FIFO_buffer, element_type *buf, uint32_t length);

FIFO_status FIFO_enqueue(FIFO_BUF_t * FIFO_buffer , element_type item);

FIFO_status FIFO_dequeue(FIFO_BUF_t * FIFO_buffer , element_type *item);

FIFO_status FIFO_is_full(FIFO_BUF_t * FIFO_buffer );

void FIFO_print(FIFO_BUF_t * FIFO_buffer );


#endif /* FIFO_H_ */
