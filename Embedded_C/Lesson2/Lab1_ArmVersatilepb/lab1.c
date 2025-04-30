#include "stdio.h"
#include "uart.h"


unsigned char string_message[20] = "Muhamad Elalawy";
void main(void){
	
	
	
	uart_send_string(string_message);
	
}