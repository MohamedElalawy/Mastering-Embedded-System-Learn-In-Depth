
ENTRY(reset)
MEMORY
{
	Mem (rwx) : ORIGIN = 0x00000000, LENGTH = 128M

}
SECTIONS
{
	. = 0x00000000;

	.startup . :
	{
		startup.o(.text)
	
	}> Mem
	.text :
	{
		*(.text)
	
	}> Mem
	.data :
	{
		*(.data)
	
	}> Mem
	.bss :
	{
		*(.bss)
	}> Mem
	. = . + 0x1000;  /*4KB of stack Memory*/
	stack_top = . ;


}