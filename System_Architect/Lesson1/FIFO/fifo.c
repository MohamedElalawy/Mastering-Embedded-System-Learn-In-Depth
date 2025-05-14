/*
 * fifo.c
 *
 *  Created on: May 13, 2025
 *      Author: Muhamad Elalawy
 */


#include "fifo.h"


//=====      APIs     =====//
FIFO_status FIFO_init(FIFO_BUF_t * FIFO_buffer, element_type *buf, uint32_t length){

	if(buf==NULL){
		return FIFO_NULL;
	}
	FIFO_buffer->base = buf;
	FIFO_buffer->head = buf;
	FIFO_buffer->tail = buf;
	FIFO_buffer->length = length;
	FIFO_buffer->count = 0;

	return FIFO_NO_ERRO;


}

FIFO_status FIFO_enqueue(FIFO_BUF_t * FIFO_buffer , element_type item){

	if (!FIFO_buffer->base || !FIFO_buffer->head || !FIFO_buffer->tail){

		return FIFO_NULL;
	}
	if (FIFO_is_full(FIFO_buffer)==FIFO_FULL){
		return FIFO_FULL;
	}

	*(FIFO_buffer->head) = item;
	FIFO_buffer->count++;
	//circular
	if(FIFO_buffer->head == (FIFO_buffer->base + (FIFO_buffer->length *sizeof(element_type)))){

		FIFO_buffer->head = FIFO_buffer->base;
	}
	else {
		FIFO_buffer->head ++;
	}
	return FIFO_NO_ERRO;

}

FIFO_status FIFO_dequeue(FIFO_BUF_t * FIFO_buffer , element_type *item){
	if (!FIFO_buffer->base || !FIFO_buffer->head || !FIFO_buffer->tail){

		return FIFO_NULL;
	}
	if (FIFO_buffer->count ==0){
		return FIFO_EMPTY;
	}

	*item = *(FIFO_buffer->tail);
	FIFO_buffer->count --;

	//circular
	if(FIFO_buffer->tail == (FIFO_buffer->base + (FIFO_buffer->length *sizeof(element_type)))){

		FIFO_buffer->tail = FIFO_buffer->base;
	}
	else {
		FIFO_buffer->tail ++;
	}

	return FIFO_NO_ERRO;
}

FIFO_status FIFO_is_full(FIFO_BUF_t * FIFO_buffer ){
	if (!FIFO_buffer->base || !FIFO_buffer->head || !FIFO_buffer->tail){

		return FIFO_NULL;
	}
	if (FIFO_buffer->count == FIFO_buffer->length){
		return FIFO_FULL;
	}

	return FIFO_NO_ERRO;
}

void FIFO_print(FIFO_BUF_t * FIFO_buffer ){

	element_type * temp;
	int i;
	if (FIFO_buffer->count ==0){
		printf(" FIFO_EMPTY \n");
	}
	else{
		temp = FIFO_buffer->tail;
		printf("\n:::::fifo print:::::\n");

		for(i=0; i< FIFO_buffer->count ; i++){
			printf("\t %X \n",*temp);
			temp++;
		}
		printf("\n::::::::::::::::::::\n");
	}














}
