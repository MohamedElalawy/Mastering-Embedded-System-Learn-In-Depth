#Lab1-> Makefile
#By Muhamad Elalawy
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

#AS=$(wildcard *.s)
#ASOBJ=$(AS:.s=.o)

Projectname=lab2

all: $(Projectname).bin
	@echo "Build is done!"
	
#startup.o: startup.s
#	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
#$(Projectname).elf: $(OBJ) $(ASOBJ)
#	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map

$(Projectname).elf: $(OBJ) 
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -o $@ -Map=Map_file.map
	

$(Projectname).bin: $(Projectname).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.bin *.elf
	
	
clean_all:
	rm *.o *.bin *.elf
	
	
	
	
#lab1.bin: startup.s uart.c lab1.c
#	arm-none-eabi-as.exe -mcpu=arm926ej-s -g startup.s -o startup.o
#	arm-none-eabi-gcc.exe -c -I . -g -mcpu=arm926ej-s lab1.c -o lab1.o
#	arm-none-eabi-gcc.exe -c -I . -g -mcpu=arm926ej-s uart.c -o uart.o
#	arm-none-eabi-ld.exe -T linker_script.ld startup.o lab1.o uart.o -o lab1.elf -Map=Map_file.map
#	arm-none-eabi-objcopy.exe -O binary lab1.elf lab1.bin
