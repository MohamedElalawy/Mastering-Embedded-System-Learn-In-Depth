![image](https://github.com/user-attachments/assets/460fd07c-7d1a-48f3-98fc-b19c05cac256)

*   `gcc.exe -c CANDriver.c -o CANDriver.o`: Compiles `CANDriver.c` into an object file `CANDriver.o` without linking.
*   `ar rcs CANLib.a CANDriver.o`: Creates a static library named `CANLib.a` from the object file `CANDriver.o`.
*   `gcc.exe main.c -o main.exe`: Attempts to compile `main.c` and link it into an executable `main.exe`, failing because the `Can_send` function definition is missing (linker error: undefined reference).
*   `gcc.exe main.c CANLib.a -o main.exe`: Compiles `main.c` and links it with the static library `CANLib.a` (which contains the definition for `Can_send`) to successfully create the executable `main.exe`.
*   `./main.exe`: Explicitly tells the shell to execute the `main.exe` program located in the current directory (`./`).
