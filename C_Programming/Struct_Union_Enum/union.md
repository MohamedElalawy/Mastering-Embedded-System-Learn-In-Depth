
```c
#include <stdio.h>

// Union definition
union UNUMValue {
    int intValue;
    float floatValue;
    double doubleValue;
};

int main() {
    union UNUMValue u;

    // Initialize double (occupies full 8 bytes)
    u.doubleValue = 3.14159;
    printf("Initial doubleValue: %lf\n", u.doubleValue);

    // Overwrite part of the union with int (4 bytes)
    u.intValue = 42;
    printf("After intValue = 42:\n");
    printf("intValue: %d\n", u.intValue);
    printf("doubleValue (corrupted): %lf\n", u.doubleValue);

    return 0;
}
```


- **Memory Overlap**: All members (`intValue`, `floatValue`, `doubleValue`) share the same memory space (size = 8 bytes, the largest member).
- **Overwrite Behavior**: Writing to `intValue` corrupts `doubleValue` because they overlap.


![Screenshot 2025-04-06 055135](https://github.com/user-attachments/assets/ebc4bfeb-9095-4ed5-b8ea-df3b101a0e91)

![Screenshot 2025-04-06 055703](https://github.com/user-attachments/assets/0fbf91de-1ebf-4da8-b928-5d364e18d02e)
![Screenshot 2025-04-06 060705](https://github.com/user-attachments/assets/f8b72095-ac29-44e2-b777-33b1f58af639)



example to explain the benefits of using a union :
This code demonstrates how to use a union and an enum to handle arithmetic operations on different numeric types (int, float, double) with a single function.
Using a union allows storing different types in the same memory space, saving memory when only one type is used at a time.
```c
#include <stdio.h>

// Enum to specify the type of number being used
enum NUMType { INT, FLOAT, DOUBLE };

// Union that can hold different numeric types
union UNUMValue {
    int u_intValue;
    float u_floatValue;
    double u_doubleValue;
};

// Function to add two UNUMValue based on their type
union UNUMValue Add(union UNUMValue value1, union UNUMValue value2, enum NUMType type) {
    union UNUMValue result;
    switch(type) {
        case INT: 
            result.u_intValue = value1.u_intValue + value2.u_intValue; 
            break;
        case FLOAT: 
            result.u_floatValue = value1.u_floatValue + value2.u_floatValue; 
            break;
        case DOUBLE: 
            result.u_doubleValue = value1.u_doubleValue + value2.u_doubleValue; 
            break;
    }
    return result;
}

int main() {
    union UNUMValue V1, V2, R;
    
    printf("The size of UNUMValue is %zu bytes\n\n", sizeof(union UNUMValue));
    
    // Integer addition
    V1.u_intValue = 9898;
    V2.u_intValue = 8776;
    R = Add(V1, V2, INT);
    printf("int: %d + %d = %d\n", V1.u_intValue, V2.u_intValue, R.u_intValue);
    
    // Float addition
    V1.u_floatValue = 86.82;
    V2.u_floatValue = 83.11;
    R = Add(V1, V2, FLOAT);
    printf("float: %f + %f = %f\n", V1.u_floatValue, V2.u_floatValue, R.u_floatValue);
    
    // Double addition
    V1.u_doubleValue = 821.8;
    V2.u_doubleValue = 988.2;
    R = Add(V1, V2, DOUBLE);
    printf("double: %lf + %lf = %lf\n", V1.u_doubleValue, V2.u_doubleValue, R.u_doubleValue);

    return 0;
}
```

![Screenshot 2025-04-06 055441](https://github.com/user-attachments/assets/a14c1ac2-6a30-43a9-a461-970271e12df8)

## The key difference between unions and structures
```c
#include <stdio.h>

union unionJob {
    //defining a union
    char name[32];
    float salary;
    int workerNo;
} uJob;

struct structJob {
    char name[32];
    float salary;
    int workerNo;
} sJob;

int main() {
    printf("size of union = %d", sizeof(uJob));
    printf("\nsize of structure = %d", sizeof(sJob));
    return 0;
}
```
![Screenshot 2025-04-06 062509](https://github.com/user-attachments/assets/31ea91c5-1c2d-43bf-b138-f2a6f251046e)

