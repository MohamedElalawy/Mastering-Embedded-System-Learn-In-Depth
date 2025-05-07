/* Muhamad Elalawy Startup.c*/
#include <stdint.h>
extern int main();
void Reset_Handler();
void Default_Handler(){
	Reset_Handler();
}
void NMI_Handler() __attribute__((weak, alias ("Default_Handler")));
void H_Fault_Handler() __attribute__((weak, alias ("Default_Handler")));

//booking 1024B located by .bss through an uninitialized array of int 256 elements (256*4=1024)
static unsigned long stack_top[256];




void (*const  g_p_fn_vectors[]) () __attribute__((section(".vectors")))=
{
	
	(void (*)()) ((unsigned long )stack_top+sizeof(stack_top)),
     &Reset_Handler,
    &NMI_Handler,
    &H_Fault_Handler,	

};


extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;



void Reset_Handler()
{
	
	unsigned int data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	
	unsigned char * P_src = (unsigned char*)&_E_text;
	unsigned char * P_dst = (unsigned char*)&_S_data;
	//copy data section from flash to ram
	for(int i = 0;i < data_size ; i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
		
	}
	
	//init .bss section in sram by zeros
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char * )&_S_bss;
	for(int i = 0;i < bss_size ; i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0;
		
	}	
	
	
	//jump to main
	main();
    
}
