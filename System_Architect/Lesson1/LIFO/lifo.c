/*
 * lifo.c
 *
 *  Created on: May 11, 2025
 *      Author: Muhamad Elalawy
 */
#include "lifo.h"

//=====      APIs     =====//
LIFO_status LIFO_init(LIFO_BUF_t * LIFO_buffer, unsigned int *buf, unsigned int length)
{
	if(buf==NULL){
		return LIFO_NULL;
	}
	LIFO_buffer->base = buf;
	LIFO_buffer->head = buf;
	LIFO_buffer->length = length;
	LIFO_buffer->count = 0;

	return LIFO_NO_ERRO;

}

LIFO_status LIFO_add_item(LIFO_BUF_t * LIFO_buffer , unsigned int item)
{
	if (!LIFO_buffer->base || !LIFO_buffer->head ){

		return LIFO_NULL;
	}

	if (LIFO_buffer->count ==  LIFO_buffer->length ){

		return LIFO_FULL;
	}

	*(LIFO_buffer->head) = item;

	LIFO_buffer->head ++;
	LIFO_buffer->count++;

	return LIFO_NO_ERRO;
}

LIFO_status LIFO_get_item(LIFO_BUF_t * LIFO_buffer , unsigned int *item)
{
	if (!LIFO_buffer->base || !LIFO_buffer->head ){

		return LIFO_NULL;
	}

	if (LIFO_buffer->count ==  0 ){

		return LIFO_EMPTY;
	}

	LIFO_buffer->head --;

	*item= *(LIFO_buffer->head);

	LIFO_buffer->count--;



	return LIFO_NO_ERRO;

}

