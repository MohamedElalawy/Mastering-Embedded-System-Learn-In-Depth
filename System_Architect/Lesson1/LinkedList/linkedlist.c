/*
 * linkedlist.c
 *
 *  Created on: May 14, 2025
 *      Author: Muhamad Elalawy
 */

#include "linkedlist.h"
struct Sstudent *gpListHead = NULL;



void LL_add_record(){
	struct Sstudent *pNewRecord  ;
	struct Sstudent *pLastRecord  ;
	char temp_text[50];
/*
* If the list is empty:
* 1-create new record
* 2-assign gpListHead to it
*/
	if (gpListHead == NULL){
		pNewRecord = (struct Sstudent *)malloc(sizeof(struct Sstudent ));
		gpListHead = pNewRecord;
	}


/*
* If the list contains record:
* 1-Navigate until reaching the last record
* 2-create new record
* 3-assign pNextRecord to it
*/

	else{

		pLastRecord = gpListHead;
		while(pLastRecord->pNextRecord){

			pLastRecord=pLastRecord->pNextRecord;

		}

		pNewRecord = (struct Sstudent *)malloc(sizeof(struct Sstudent ));
		pLastRecord->pNextRecord = pNewRecord;

	}


/*
* fill the record data
*/
	printf("\n Enter the ID: ");
	gets(temp_text);
	pNewRecord->student.ID=atoi(temp_text);

	printf("\n Enter the Full Name: ");
	gets(pNewRecord->student.name);


	printf("\n Enter the Height: ");
	gets(temp_text);
	pNewRecord->student.height=atof(temp_text);



/*
* set the next record to NULL
*/
	pNewRecord->pNextRecord = NULL;

}



//delete record by certain ID:
int LL_delete_record(){

/*
 * get selected record ID from the user
 */
	char temp_text[16];
	unsigned int selected_ID;
	printf("\n Enter the student ID to be Deleted: ");
	gets(temp_text);
	selected_ID = atoi(temp_text);


/*
 * Loop on all records
 * for each record:
 *     a. compare the record id with the selected id
 *     b. if it the selected record:
 *     		i.if the previous record exist, set the pNextRecord pf the previous record to point to the next record
 *     	   ii.if the previous record not exist, set the gpListHead to point to the next record.
 *     	  iii. last one is the one to be deleted
 *     c. delete the record
 */
	if (gpListHead){

		struct Sstudent *pSelectedRecord = gpListHead ;
		struct Sstudent *pPreviousRecord = NULL  ;


		while(pSelectedRecord){
			//a. compare the record id with the selected id
			if(pSelectedRecord->student.ID ==selected_ID ){
				if(pPreviousRecord){
					//the head is not the selected one
					pPreviousRecord->pNextRecord = pSelectedRecord->pNextRecord;

				}
				else{
					//head is the selected one
					gpListHead = pSelectedRecord->pNextRecord;
				}
				free (pSelectedRecord);
				return 1;

			}
			pPreviousRecord = pSelectedRecord;
			pSelectedRecord = pSelectedRecord->pNextRecord;

		}


	}

	printf("\n Can't find the student ID !");
	return 0;
}





//print all records:
void LL_print_all_records(){
	struct Sstudent *pCurrentRecord  = gpListHead;
	int count = 0;
	if(gpListHead == NULL){
		printf("\n The List is Empty !");
	}
	else{
		while(pCurrentRecord){

			printf("\n Record no %d ",count+1);
			printf("\n \t ID: %d ",pCurrentRecord->student.ID);
			printf("\n \t Name: %s ",pCurrentRecord->student.name);
			printf("\n \t Height: %f ",pCurrentRecord->student.height);

			pCurrentRecord = pCurrentRecord->pNextRecord;
			count++;
		}

	}

}



//Delete all records:
void LL_delete_all_records(){
	struct Sstudent *pCurrentRecord  = gpListHead;
	int count = 0;
	if(gpListHead == NULL){
		printf("\n The List is Empty !");
	}
	else{
		while(pCurrentRecord){
			struct Sstudent *pTempRecord  = pCurrentRecord;
			pCurrentRecord = pCurrentRecord->pNextRecord;
			free(pTempRecord);
		}
		gpListHead = NULL;
	}
}























