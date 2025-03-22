/*
 * main.c
 *
 *  Created on: Mar 19, 2025
 *      Author: Muhamad Elalawy
 */
#include"stdio.h"


int main(int argc, char **argv){
	float s_degrees[10];
	int i;
	for(i = 0; i < 10 ; i++){

		printf("Enter student %d degree: ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%f",&s_degrees[i]);
		printf("\n");
	}
	for(i = 0; i < 10 ; i++){
		printf("Degree of student %d is: %0.2f\n\n",i+1,s_degrees[i]);

	}
	return 0;
}

