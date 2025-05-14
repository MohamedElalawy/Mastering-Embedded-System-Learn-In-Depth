/*
 * main.c
 *
 *  Created on: May 13, 2025
 *      Author: Muhamad Elalawy
 */

#include "fifo.h"


int main()
{
	FIFO_BUF_t UART_FIFO;

	if(FIFO_init(&UART_FIFO , uart_buffer , 5 ) == FIFO_NO_ERRO){
		printf("FIFO_init is Done! \n");

	}
	element_type i , temp = 0;

	for (i = 0; i< 7 ; i++)
	{


		printf("FIFO_enqueue : (%x) \n",i);
		if(FIFO_enqueue(&UART_FIFO , i)==FIFO_NO_ERRO){
			printf("\t FIFO_enqueue Done \n");
		}
		else{
			printf("\t FIFO_enqueue Failed \n");
		}
	}


	FIFO_print(&UART_FIFO);

	if(FIFO_dequeue(&UART_FIFO , &temp)==FIFO_NO_ERRO){
		printf("\t FIFO_dequeue : (%x) Done \n",temp);
	}


	if(FIFO_dequeue(&UART_FIFO , &temp)==FIFO_NO_ERRO){
		printf("\t FIFO_dequeue : (%x) Done \n",temp);
	}


	FIFO_print(&UART_FIFO);


	return 0;
}
