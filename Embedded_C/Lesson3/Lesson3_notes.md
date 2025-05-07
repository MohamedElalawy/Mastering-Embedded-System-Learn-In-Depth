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

## 2. DWARF Debugging Format (`-gdwarf`, `-gdwarf-N`) "Proteus uses this type"

DWARF is the standard debug info format used by GDB. Different versions offer varying features.

| Option          | DWARF Version | Key Features |
|-----------------|--------------|--------------|
| **`-gdwarf`**   | Default (varies by GCC) | Usually DWARF-2 or newer. |
| **`-gdwarf-2`** | DWARF-2 | Basic debugging (variables, line numbers). |
| **`-gdwarf-3`** | DWARF-3 | Adds macro support (requires `-g3`). |
| **`-gdwarf-4`** | DWARF-4 | Faster debug loading (split `.debug_info`). |
| **`-gdwarf-5`** | DWARF-5 | Best compression, improved line tables. |

---

Example for gdb setup paths:
![image](https://github.com/user-attachments/assets/804f5b29-bd06-437b-b1dd-6dfd7d37f8de)


![Screenshot 2025-05-02 201613](https://github.com/user-attachments/assets/ef5e145b-6339-4b17-9a10-8d28b094ec81)


![Screenshot 2025-05-02 235036](https://github.com/user-attachments/assets/7afbdd44-1433-43f2-9d4c-88ebf6eece26)


![Screenshot 2025-05-03 001919](https://github.com/user-attachments/assets/ffa0fce5-b648-49bb-9959-c35c5d9867e5)



![Screenshot 2025-05-03 001933](https://github.com/user-attachments/assets/3d0f37cf-c7e3-4921-9a0a-717d50d50202)

![Screenshot 2025-05-03 002945](https://github.com/user-attachments/assets/00b4be58-4b89-47cf-88b3-9d8837e70d69)


![Screenshot 2025-05-03 200517](https://github.com/user-attachments/assets/481c2fa9-5781-4276-987c-8a0cf863afe8)

![Screenshot 2025-05-03 201012](https://github.com/user-attachments/assets/43adb6e1-f3ad-42d9-af9f-1dbaa119583d)



![Screenshot 2025-05-03 203204](https://github.com/user-attachments/assets/f4b84e53-0d8d-4463-b9c0-4dcd8aa1df38)


![Screenshot 2025-05-04 192041](https://github.com/user-attachments/assets/971c0bfc-91a4-4b44-bdb2-41ef2d13568d)



![Screenshot 2025-05-04 193630](https://github.com/user-attachments/assets/4c1d0fce-e4bb-404b-99bd-c3b2ceb08598)



![Screenshot 2025-05-04 200636](https://github.com/user-attachments/assets/fb25c393-f77b-4112-a1e3-260930494566)


![Screenshot 2025-05-04 200645](https://github.com/user-attachments/assets/0b0c6823-a017-445f-9316-4bb9bda6aa58)


![Screenshot 2025-05-04 200726](https://github.com/user-attachments/assets/1b1ca542-91b0-4ad6-80cc-2c8de9ad51b8)

![Screenshot 2025-05-04 201755](https://github.com/user-attachments/assets/6086ba71-c8d7-4812-96cd-e4301c26ac9a)


![Screenshot 2025-05-04 203000](https://github.com/user-attachments/assets/fce3f2eb-b04b-463e-8fcd-4f5960b058f3)


![Screenshot 2025-05-04 204317](https://github.com/user-attachments/assets/6a5d3701-5701-42b3-8e22-fc203d90bc43)

![Screenshot 2025-05-04 210751](https://github.com/user-attachments/assets/fee12d4d-2292-4e07-86fa-bf78d4469503)

![Screenshot 2025-05-05 213951](https://github.com/user-attachments/assets/75c36631-ead1-4d31-9865-20f8f976bf4d)

![Screenshot 2025-05-05 214126](https://github.com/user-attachments/assets/2c9d821a-44dc-4e8b-afb6-52228621a40b)

![Screenshot 2025-05-05 222457](https://github.com/user-attachments/assets/2f0d6738-32bd-4665-8834-1160b59c36ba)

![Screenshot 2025-05-05 222906](https://github.com/user-attachments/assets/e05ad1be-f9d7-4be9-9dbe-f9e2da1a0810)

![Screenshot 2025-05-05 225512](https://github.com/user-attachments/assets/7199986a-36ac-4920-94da-4dce15cf26e9)
![Screenshot 2025-05-06 222753](https://github.com/user-attachments/assets/a91af874-24f2-42ed-9885-c25592b4f4f7)
![Screenshot 2025-05-06 222753](https://github.com/user-attachments/assets/28a3d5d7-6bb2-4233-b904-8d359afc8944)
![Screenshot 2025-05-06 223059](https://github.com/user-attachments/assets/e86b1b19-4441-42a3-967d-207555d62d5d)

