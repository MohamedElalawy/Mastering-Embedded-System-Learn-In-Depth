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

