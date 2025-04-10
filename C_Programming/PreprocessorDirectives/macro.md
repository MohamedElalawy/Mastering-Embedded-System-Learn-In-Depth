![Screenshot 2025-04-07 063620](https://github.com/user-attachments/assets/55da3349-9132-44e6-9584-2443bbb7df17)



![Screenshot 2025-04-07 065859](https://github.com/user-attachments/assets/9cdbef91-bc27-4e5b-ab39-72a2c0b95f55)
```C
#include <stdio.h>

#define PR(value, maxValue) (100.0 * value/(double)maxValue)

int main(int argc, char**argv){
    printf("Enter subject degree followed by the maximum degree:\n\n");
    printf("Arabic:");
    printf("Arabic degree is %lf\n", PR(40,50));
    printf("Math:");
    printf("Math degree is %lf\n", PR(30,50));
    printf("Physics:");
    printf("Physics degree is %lf\n", PR(20,50));
    printf("English:");
    printf("English degree is %lf\n", PR(50,50));
	return 0;
}
```

![Screenshot 2025-04-07 072050](https://github.com/user-attachments/assets/98f5f6bf-1b5d-4311-8bc8-8fa89ac6996d)


```
```
# Variable argument macros 


## Two Forms of Variadic Macros

1. **With named parameters plus variable arguments**:
   ```c
   #define identifier(parameters, ...) replacement-list
   ```
   - This form takes some named parameters followed by `...` for variable arguments
   - Access variable arguments with `__VA_ARGS__` in the replacement list

2. **Variable arguments only**:
   ```c
   #define identifier(...) replacement-list
   ```
   - This form takes only variable arguments (no named parameters)
   - Still access with `__VA_ARGS__`

## Key Points

- `__VA_ARGS__` expands to all the variable arguments passed to the macro
- The `##` operator can be used for token concatenation with `__VA_ARGS__`
- This is commonly used for printf-style debugging macros or flexible macros

## Example Usage

```c
// Form 3 example
#define LOG(msg, ...) printf(msg, __VA_ARGS__)

// Form 4 example
#define DEBUG(...) printf(__VA_ARGS__)

// With token concatenation
#define ERROR(fmt, ...) fprintf(stderr, "Error: " fmt, ##__VA_ARGS__)
```

The `##` operator before `__VA_ARGS__` is a GNU extension that removes the preceding comma if no variable arguments are supplied.

![Screenshot 2025-04-08 192323](https://github.com/user-attachments/assets/36e9806b-3189-4b74-9ca4-c1df5c189e2d)


![Screenshot 2025-04-08 193449](https://github.com/user-attachments/assets/c83fafd6-23b0-4c3e-9b85-4530bccf60ba)

## advanced macro techniques
```C
#include <stdio.h>

#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define DEC(x) PRIMITIVE_CAT(DEC_, x)
#define DEC_0 0
#define DEC_1 0
#define DEC_2 1
#define DEC_3 2
#define DEC_4 3
#define DEC_5 4
#define DEC_6 5
#define DEC_7 6
#define DEC_8 7
#define DEC_9 8

#define Dprintf(...) printf(__VA_ARGS__)

int main(int argc, char** argv) {
    Dprintf("DEC(7)=%d\n", DEC(7));
    return 0;
}
```
![Screenshot 2025-04-08 194106](https://github.com/user-attachments/assets/a01505ca-0f61-47e9-ba38-90c8fb8dcdc9)

## Interview question:
How to solve the following problems in single modification to pass the compilation?
```C
#include <stdio.h> 
#define Dprintf(...) printf(__VA_ARGS__)  

int main(int argc, char** argv) {
    // ❌ ERROR: 'DEC' is implicitly declared (undefined macro/function)
    Dprintf("DEC(7)-%d", DEC(7));  

    // ❌ ERROR: 'Dprintf()' expands to 'printf()' → too few arguments
    Dprintf();  
}
```
![Screenshot 2025-04-08 195800](https://github.com/user-attachments/assets/c999c013-03d3-4ec0-a62a-faff650ed12a)

Solution:
```C
#include <stdio.h>  

#define Dprintf(...) printf(#__VA_ARGS__)  

int main(int argc, char** argv) {
    Dprintf("DEC(7)-%d", DEC(7));  
    Dprintf();  
}
```
![Screenshot 2025-04-08 195921](https://github.com/user-attachments/assets/835e69e3-ce4f-4e7c-894e-6f87fd674083)

## #undef:
![Screenshot 2025-04-09 054114](https://github.com/user-attachments/assets/c7c70a2b-5f2a-4808-8329-4f9acce50941)

## Trick:
```C
#include <stdio.h>

#define FUNCTION(name, a) int fun_##name(int x) { return (a)*x; }

FUNCTION(quadruple, 4)
FUNCTION(double, 2)

#undef FUNCTION
#define FUNCTION 34
#define OUTPUT(a) printf(#a)

int main(int argc, char** argv) {
    printf("quadruple(13): %d\n", fun_quadruple(13));
    printf("double(21): %d\n", fun_double(21));
    printf("%d\n", FUNCTION);
    OUTPUT(Keroles);    
    
    return 0;
}
```
![Screenshot 2025-04-09 055942](https://github.com/user-attachments/assets/9e4fae14-5b03-4da7-9286-88583e5de5cd)


![Screenshot 2025-04-09 060623](https://github.com/user-attachments/assets/e412d381-a329-4e65-ac59-7f043761b155)


## Predefined macros

| **Macro**             | **Description**                                                                                                                                               |
|-----------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `__STDC__`            | Expands to the integer constant `1`. Indicates a conforming implementation.                                                                                   |
| `__STDC_VERSION__`    | Expands to an integer constant of type `long` for the C standard version:<br>- `199409L` (C95)<br>- `199901L` (C99)<br>- `201112L` (C11)                      |
| `__STDC_HOSTED__`     | Expands to `1` if hosted (runs under OS), or `0` if freestanding (runs without OS).                                                                           |
| `__FILE__`            | Expands to the name of the current file as a string literal. Can be changed using `#line` directive.                                                          |
| `__LINE__`            | Expands to the line number in the source file as an integer. Can be changed using `#line` directive.                                                          |
| `__DATE__`            | Expands to the date of translation as `"Mmm dd yyyy"`. Uses `asctime` style, and a space precedes single-digit days.                                          |
| `__TIME__`            | Expands to the time of translation as `"hh:mm:ss"`, in `asctime` format.                                                                                      |

``
![Screenshot 2025-04-09 061937](https://github.com/user-attachments/assets/20c245c7-e5e7-43c2-ba20-7e8dbb9dfa69)


## Quiz: Think how to write a code can be Removed or added to the Embedded C Program and Responsible on print Debug with Details
```C
#include <stdio.h>

#define DPRINTF(debug_level, ...) \
    if (debug_level > 1) { \
        printf("@ Func: %s, File: %s, Line: %d ", __func__, __FILE__, __LINE__); \
        printf(">> \t"); \
        printf(__VA_ARGS__); \
    }

void CAN_Send()
{
    DPRINTF(3, "Sending CAN message\n");
}

void can_init()
{
    DPRINTF(3, "Initializing CAN module\n");
}

int main()
{
    DPRINTF(3, "Program started\n");
    can_init();
    CAN_Send();
    DPRINTF(3, "Program completed\n");

    return 0;
}
```
![Screenshot 2025-04-09 071555](https://github.com/user-attachments/assets/e024e02a-0b18-41d0-9bcc-1f470baab15b)


## Shell script that recursively searches through all C/C++ source files in a folder (.c, .cpp, .h, .hpp), detects function definitions, and inserts a debug print using your DPRINTF macro :
```bash
#!/bin/bash

DEBUG_LEVEL=3

find . -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) | while read -r file; do
    echo "Processing $file..."

    awk -v debug_level="$DEBUG_LEVEL" '
    BEGIN {
        inside_func = 0
        brace_depth = 0
        funcname = ""
    }

    function trim(s) {
        sub(/^[ \t]+/, "", s)
        sub(/[ \t]+$/, "", s)
        return s
    }

    # Detect function definition and opening brace
    /^[a-zA-Z_][a-zA-Z0-9_ \t\*]*\([^\)]*\)[ \t]*\{/ {
        funcname = gensub(/^.*\b([a-zA-Z_][a-zA-Z0-9_]*)[ \t]*\(.*/, "\\1", "g", $0)
        inside_func = 1
        brace_depth = 1
        print
        next
    }

    inside_func == 1 {
        open_count = gsub(/\{/, "{", $0)
        close_count = gsub(/\}/, "}", $0)
        brace_depth += open_count - close_count

        if (brace_depth == 0 && trim($0) == "}") {
            printf("    DPRINTF(%d, \"Exiting %s\\n\");\n", debug_level, funcname)
            print $0
            inside_func = 0
            next
        }
        print
        next
    }

    { print }
    ' "$file" > "$file.tmp" && mv "$file.tmp" "$file"
done

echo "DPRINTF inserted at the end of functions."
```
![Screenshot 2025-04-09 190642](https://github.com/user-attachments/assets/43b89904-e341-4580-9ced-c74ff7143bf9)

![Screenshot 2025-04-09 190707](https://github.com/user-attachments/assets/b83b31bd-09b6-4fd4-ad38-779d86ba430c)


## macro VS function
Here's the table based on the image you provided:

| No | Macro | Function |
|----|-------|----------|
| 1 | Macro is Preprocessed | Function is Compiled |
| 2 | No Type Checking | Type Checking is Done |
| 3 | Code Length Increases | Code Length remains Same |
| 4 | Speed of Execution is Faster | Speed of Execution is Slower |
| 5 | Before Compilation macro name is replaced by macro value | During function call, Transfer of Control takes place |
| 6 | Useful where small code appears many times | Useful where large code appears many times |
| 7 | Generally Macros do not extend beyond one line | Function can be of any number of lines |

