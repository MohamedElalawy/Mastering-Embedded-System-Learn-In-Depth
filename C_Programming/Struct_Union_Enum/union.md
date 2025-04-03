
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
- **Output**:  
   ```
   Initial doubleValue: 3.141590  
   After intValue = 42:  
   intValue: 42  
   doubleValue (corrupted): garbage value  
   ```




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

### Benefits of Using a Union in This Code:

1. **Memory Efficiency**:
   - The union only allocates enough memory for the largest member (8 bytes for `double`), rather than allocating separate memory for each type.
   - This is more memory-efficient than using a struct, which would allocate space for all members (4 + 4 + 8 = 16 bytes).

2. **Flexible Data Representation**:
   - The same memory space can be used to store different types of data (`int`, `float`, or `double`) at different times.
   - This is useful when a variable might need to hold different types of data during program execution.

3. **Type-Safe Operations**:
   - The `enum NUMType` ensures that operations are performed on the correct type, preventing misuse of the union.
   - The `Add` function uses the enum to determine which type of addition to perform.

4. **Cleaner Code**:
   - The union provides a single variable (`UNUMValue`) that can handle multiple data types, making the code more organized and easier to maintain.

### Output Example:
```
The size of UNUMValue is 8 bytes

int: 9898 + 8776 = 18674
float: 86.820000 + 83.110001 = 169.930000
double: 821.800000 + 988.200000 = 1810.000000
```

This approach is particularly useful in scenarios where you need to handle different data types in a memory-efficient way, such as in embedded systems or when working with variant data.
