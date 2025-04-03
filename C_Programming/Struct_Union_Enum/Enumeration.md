![Screenshot 2025-04-03 020623](https://github.com/user-attachments/assets/aac539d7-98e8-440e-b1c7-6dcfef447038)

```c
#include <stdio.h>

enum week { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

int main()
{
    enum week today;
    today = wednesday;
    printf("Day %d", today + 1);
    return 0;
}
```

### Size of the Enum:
In C, an `enum` type is typically the size of an `int`. On most modern systems, this means:

- **Size of enum week**: `4 bytes` (same as `sizeof(int)`)


- The enum constants (`sunday`, `monday`, etc.) are assigned integer values starting from `0` by default.
   - `sunday` = 0, `monday` = 1, ..., `wednesday` = 3, etc.
- In the code:
   - `today = wednesday` assigns the value `3` to `today`.
   - `today + 1` evaluates to `4`, so the output is `Day 4`.
- The size of the enum variable (`today`) is the size of an `int` because enums are essentially integers in C.

