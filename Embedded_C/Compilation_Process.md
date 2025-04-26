
**Compilation Process Stages:**

The image outlines a typical compilation process, focusing on the steps after the initial source code (`App.c`) is ready.

1.  **Pre-processing Stage:**
    * **Input:** `App.c` (your C source code) and potentially other files like `Startup.s`.
    * **Process:** The preprocessor takes the source code and handles directives that start with a `#` (like `#include`, `#define`, `#ifdef`, etc.).
        * `#include`: Replaces the directive with the content of the specified header file.
        * `#define`: Performs macro substitutions (replacing defined names with their values).
        * `#ifdef`, `#ifndef`, `#else`, `#endif`: Conditionally includes or excludes sections of code based on defined macros.
    * **Output:** `App.i` - A modified source code file where pre-processing directives have been resolved. This file essentially contains the expanded source code ready for the next stage.

2.  **Code Generation Stage (Compilation):**
    * **Input:** `App.i` (the pre-processed source code).
    * **Process:** The compiler takes the pre-processed C code and translates it into the assembly language specific to the target processor architecture. This stage involves lexical analysis, parsing, semantic analysis, and generating low-level instructions.
    * **Output:** `App.s` - An assembly language file. This file contains human-readable instructions that correspond to the operations the processor can perform.

3.  **Assembler Stage:**
    * **Input:** `App.s` (the assembly language file).
    * **Process:** The assembler takes the assembly language code and converts it into machine code. Each assembly instruction is translated into a sequence of binary instructions that the processor can directly execute.
    * **Output:** `App.o` - An object file. This file contains the machine code along with metadata, such as information about the data and code segments, and importantly, **relocation information**.

**Relocatable Code:**

* **What it is:** The machine code in the object file (`App.o`) is often referred to as **relocatable code**. This means that the addresses of code and data within the object file are not yet fixed to specific locations in the final executable's memory. Instead, they are expressed as offsets relative to the start of their respective sections (like the text section for code or the data section for variables).
* **Why it's necessary:** When you compile multiple source files that depend on each other, each will be converted into a separate object file. These object files need to be combined into a single executable. At the time each object file is created, the compiler doesn't know where in the final memory layout its code and data will reside, nor does it know the locations of symbols (functions, variables) defined in other object files. Therefore, it generates relocatable code with placeholders for these addresses.

**Role of the Linker Script File to Convert to Locatable Code:**

* **Linker:** The **linker** is the tool responsible for taking one or more object files and combining them into a single executable file or a library.
* **Linker Script (`linker_script.ld`):** The linker uses a **linker script** (often with the `.ld` extension) to determine how the different sections from the input object files should be arranged in the final memory layout. The linker script provides crucial information, including:
    * **Memory Regions:** It defines the available memory regions in the target system (e.g., RAM, ROM) and their starting addresses and sizes.
    * **Section Placement:** It specifies which sections from the object files (like `.text`, `.data`, `.bss`) should be placed in which memory regions and at what specific addresses.
    * **Symbol Resolution:** It resolves references between different object files. For example, if a function in `App.c` calls a function defined in another file, the linker resolves the symbolic name of the called function to its actual address.
    * **Relocation:** Based on the memory layout defined in the linker script, the linker performs **relocation**. This involves:
        * Assigning absolute memory addresses to the sections from each object file.
        * Adjusting the addresses within the machine code where references were made to symbols or memory locations. The relocation information in the object files tells the linker where these adjustments need to be made.

* **Output of Linking:** After processing the object files and the linker script, the linker produces the final **locatable** executable file (or a library). In this executable, all code and data have been assigned specific, fixed memory addresses, making it ready to be loaded and executed by the target system.

In essence, the compilation process transforms human-readable source code into machine-understandable instructions. The assembler produces relocatable code because it doesn't have the full picture of the final memory layout. The linker, guided by the linker script, provides this global view and performs the crucial task of relocation to create a final executable with fixed memory addresses (locatable code).
