/* Muhamad Elalawy Startup.c*/
#include <stdint.h>
extern int main();
extern unsigned int _stack_top;
void Reset_Handler();
void Default_Handler(){
	Reset_Handler();
}
void NMI_Handler() __attribute__((weak, alias ("Default_Handler")));
void H_Fault_Handler() __attribute__((weak, alias ("Default_Handler")));
void MM_Fault_Handler() __attribute__((weak, alias ("Default_Handler")));
void Bus_Fault() __attribute__((weak, alias ("Default_Handler")));
void Usage_Fault_Handler() __attribute__((weak, alias ("Default_Handler")));


uint32_t vectors[] __attribute__((section(".vectors"))) = {
    (uint32_t) &_stack_top,
    (uint32_t) &Reset_Handler,
    (uint32_t) &NMI_Handler,
    (uint32_t) &H_Fault_Handler,
    (uint32_t) &MM_Fault_Handler,
    (uint32_t) &Bus_Fault,
    (uint32_t) &Usage_Fault_Handler
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
