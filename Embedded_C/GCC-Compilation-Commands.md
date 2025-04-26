# Components – GCC

- **To perform complete compilation process of the `main.c` source**
  - ```bash
    gcc main.c
    ```
  - This command will generate the `a.out` executable (assuming the program is composed of a single file).

- **To change the name of the generated executable**
  - ```bash
    gcc main.c -o test
    ```
  - This command will generate an executable with the name `test`.

- **To specify the Include path (path for header files)**
  - ```bash
    gcc main.c -I/usr/share/include -I. -I./inc/ -I ./ ./inc
    ```

- **To enable all warnings during compilation process**
  - ```bash
    gcc -Wall main.c -o test
    ```

- **To convert warnings into errors**
  - ```bash
    gcc -Wall -Werror main.c -o test
    ```

- **To pass options to gcc in a file (instead of in the command)**
  - ```bash
    gcc main.c @options-file
    ```
  - Where `options-file` is a text file that will contain the required options.

---
