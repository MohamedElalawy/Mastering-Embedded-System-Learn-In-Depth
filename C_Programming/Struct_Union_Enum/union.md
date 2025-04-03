
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

