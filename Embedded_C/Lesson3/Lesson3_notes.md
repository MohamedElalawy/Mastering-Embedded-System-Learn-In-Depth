# GDB Cheat Sheet

GDB (GNU Debugger) offers a comprehensive list of commands, but these are the most frequently used ones:

## Breakpoint Commands
- **b main** - Set breakpoint at the beginning of the program  
- **b** - Set breakpoint at the current line  
- **b N** - Set breakpoint at line N  
- **b +N** - Set breakpoint N lines down from the current line  
- **b fn** - Set breakpoint at the beginning of function "fn"  
- **d N** - Delete breakpoint number N  
- **info break** - List all breakpoints  

## Program Execution
- **r** - Run the program until a breakpoint or error  
- **c** - Continue running until the next breakpoint or error  
- **f** - Run until the current function finishes  
- **s** - Execute the next line of the program (steps into functions)  
- **s N** - Execute the next N lines of the program  
- **n** - Execute the next line (doesn't step into functions)  
- **u N** - Run until you get N lines ahead of the current line  

## Variable Inspection
- **p var** - Print the current value of variable "var"  

## Stack Navigation
- **bt** - Print a stack trace  
- **u** - Move up one level in the stack  
- **d** - Move down one level in the stack  

## Miscellaneous
- **q** - Quit GDB  

---
# -g option to generate debug info which is a must to use gdb:
```bash
$ arm-none-eabi-as.exe -mcpu=arm926ej-s startup.s -o startup.o
$ arm-none-eabi-gcc.exe -c -I . -g -mcpu=arm926ej-s lab1.c -o lab1.o
$ arm-none-eabi-gcc.exe -c -I . -g -mcpu=arm926ej-s uart.c -o uart.o
$ arm-none-eabi-ld.exe -T linker_script.ld startup.o lab1.o uart.o -o lab1.elf -Map=Map_file.map
$ arm-none-eabi-objcopy.exe -O binary lab1.elf lab1.bin

```



