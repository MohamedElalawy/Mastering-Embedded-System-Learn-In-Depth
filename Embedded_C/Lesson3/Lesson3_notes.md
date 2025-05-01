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
Now debug info sections are added:
![image](https://github.com/user-attachments/assets/19042c12-18af-4478-bf73-f9d37a3c75df)


![image](https://github.com/user-attachments/assets/e80d488d-c7cf-47ae-b032-eea00d769c02)


## 1. Basic Debugging Levels (`-g`, `-g1`, `-g2`, `-g3`)

These control the **amount** of debug information generated.

| Option   | Description | Use Case |
|----------|-------------|----------|
| **`-g`** (same as `-g2`) | Standard debug info (line numbers, variables, functions). | Default for most debugging. |
| **`-g1`** | Minimal debug info (function declarations, external vars). No locals or line numbers. | Reducing binary size while keeping minimal debugging. |
| **`-g2`** | Same as `-g`. Full debug info (line numbers, locals, functions). | General debugging. |
| **`-g3`** | **Extra debug info** (includes macros, inline functions). | Debugging heavily macro-based code. |

## 2. DWARF Debugging Format (`-gdwarf`, `-gdwarf-N`)

DWARF is the standard debug info format used by GDB. Different versions offer varying features.

| Option          | DWARF Version | Key Features |
|-----------------|--------------|--------------|
| **`-gdwarf`**   | Default (varies by GCC) | Usually DWARF-2 or newer. |
| **`-gdwarf-2`** | DWARF-2 | Basic debugging (variables, line numbers). |
| **`-gdwarf-3`** | DWARF-3 | Adds macro support (requires `-g3`). |
| **`-gdwarf-4`** | DWARF-4 | Faster debug loading (split `.debug_info`). |
| **`-gdwarf-5`** | DWARF-5 | Best compression, improved line tables. |







