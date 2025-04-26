# Build Tools

| Tool  | Description |
|-------|-------------|
| **gcc**  | Compiling C/C++ (and other languages) code into object files. Also, it calls a linker internally to link object files into an executable. |
| **ld**   | Links object files into an executable (called internally by gcc). |
| **make** | Reads the **Makefile** to manage the building process. |
| **ar**   | Archives multiple object files into a static library. |

# Binary Utilities

| Utility    | Description |
|------------|-------------|
| **readelf**  | Reads the **contents** of an ELF file (object file or executable). |
| **objdump**  | Reads the internals of an ELF file including **assembly code**. |
| **nm**       | Reads the **symbols** inside an object file or an executable. |
| **strings**  | Reads **text strings** inside a binary file. |
| **strip**    | **Strips** the binary file from some optional sections. |
| **addr2line**| Converts an **address** in the binary to a source file name and line number. |
| **size**     | Displays the **ELF file section sizes** and total size. |

# Debugger

| Tool  | Description |
|-------|-------------|
| **gdb** | Debugger |
