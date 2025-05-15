/*
 * linkedlist.h
 *
 *  Created on: May 14, 2025
 *      Author: mm
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"


//effective data "pay load"

struct Sdata{

	int ID;
	char name[40];
	float height;
};

//Linked List Node

struct Sstudent{
	struct Sdata student;
	struct Sstudent* pNextRecord;
};
//APIs

//Create new record:
void LL_add_record();


//delete record by certain ID:
int LL_delete_record();


//print all records:
void LL_print_all_records();


//Delete all records:
void LL_delete_all_records();




#endif /* LINKEDLIST_H_ */
