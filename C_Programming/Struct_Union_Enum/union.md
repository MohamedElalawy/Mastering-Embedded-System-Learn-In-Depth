
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



example to explain the benefits of using a union :

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
