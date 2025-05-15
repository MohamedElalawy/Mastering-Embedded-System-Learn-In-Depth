/*
 * main.c
 *
 *  Created on: May 14, 2025
 *      Author: Muhamad Elalawy
 */


#include "linkedlist.h"

// Macro to flush input/output and wrap printf
#define DPRINTF(...)\
   {    fflush(stdout);\
		fflush(stdin);\
        printf(__VA_ARGS__);\
    	fflush(stdout);\
		fflush(stdin);\
    }



int main() {
    DPRINTF("Student management system [Linked List Project]!\n");

    while (1) {
        DPRINTF("\nChoose from the following options:\n");
        DPRINTF("1: Add Student\n");
        DPRINTF("2: Delete Student\n");
        DPRINTF("3: Print All Students\n");
        DPRINTF("4: Delete All Students\n");
        DPRINTF("5: Reverse the List\n");
        DPRINTF("6: Get Nth Student\n");
        DPRINTF("0: Exit\n");
        DPRINTF("Make your Choice: ");
        char choice[20];
        gets(choice);
        switch(atoi(choice)){
            case 1:
            	LL_add_record();
                break;
            case 2:
            	LL_delete_record();
                break;
            case 3:
            	LL_print_all_records();
                break;
            case 4:
                LL_delete_all_records();
                break;
            case 0:
                DPRINTF("Exiting program. Goodbye!\n");
                return 0;
            default:
                DPRINTF("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}



