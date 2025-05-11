/*
 * main.c
 *
 *  Created on: May 11, 2025
 *      Author: Muhamad Elalawy
 */
#include "lifo.h"



unsigned int buffer1[5];//5*4=20bytes


int main()
{

	LIFO_BUF_t uart_lifo , i2c_lifo;
	//Static allocation
	LIFO_init(&uart_lifo , buffer1,5);
	//Dynamic Allocation
	unsigned int* buffer2 = (unsigned int*) malloc(5*sizeof(unsigned int));
	LIFO_init(&i2c_lifo , buffer2, 5);
	unsigned int i , temp = 0;
	for (i = 0; i< 5 ; i++)
	{

		LIFO_add_item(&uart_lifo , i);
		printf("uart_lifo add: %d \n",i);
	}

	for (i = 0; i< 5 ; i++)
	{

		if(LIFO_get_item(&uart_lifo , &temp)==LIFO_NO_ERRO){
			printf("uart_lifo get: %d \n",temp);

		}
	}








	return 0;
}
