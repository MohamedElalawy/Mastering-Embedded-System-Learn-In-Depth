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
Here’s the corrected and annotated version of the code from the image, along with a clear explanation of why enums are used in C (especially for flags):

---

### **Code Example: Enums for Bitmask Flags**
```c
#include <stdio.h>

// Define enum constants as bit flags (powers of 2)
enum designFlags {
    BOLD = 1,      // Binary: 00000001
    ITALICS = 2,   // Binary: 00000010
    UNDERLINE = 4  // Binary: 00000100
};

int main() {
    // Combine flags using bitwise OR (|)
    int myDesign = BOLD | UNDERLINE; // 00000101 (decimal 5)
    printf("%d", myDesign); // Output: 5
    return 0;
}
```

### **Output**
```
5
```
### **Quiz: Enums and Bitmasking**
**Question 1:** What is the value of `ITALICS | UNDERLINE`?  
**Answer:** `6` (binary `00000110`).  

**Question 2:** How would you check if `myDesign` has `BOLD` enabled?  
**Answer:**  
```c
if (myDesign & BOLD) { 
    printf("Bold is ON!"); 
}
```

**Question 3:** What does `printf("%d", BOLD | ITALICS | UNDERLINE);` output?  
**Answer:** `7` (binary `00000111`).  

---

### **When to Use Enums?**
- **Flags/Options:** Combining multiple options (e.g., file permissions, UI styles).  
- **Fixed Categories:** Days, states, error codes.  
- **Replace Macros:** Cleaner than `#define BOLD 1`.  

Enums make your code **intent-revealing** while maintaining efficiency. 

### **C Enum Quiz (with Answers)**  
Test your understanding of enums in C with these questions. Assume all code is compiled and run in a standard C environment.

---

#### **Quiz 1: Basic Enum Assignment**
**Code:**
```c
#include <stdio.h>

enum colors {
    RED,
    GREEN,
    BLUE
};

int main() {
    printf("%d, %d, %d", RED, GREEN, BLUE);
    return 0;
}
```
**Question:** What is the output?  
**Answer:** `0, 1, 2`  
**Explanation:** By default, enum values start at `0` and increment by 1.

---

#### **Quiz 2: Custom Enum Values**
**Code:**
```c
#include <stdio.h>

enum fruits {
    APPLE = 10,
    BANANA,
    MANGO = 20,
    ORANGE
};

int main() {
    printf("%d, %d, %d, %d", APPLE, BANANA, MANGO, ORANGE);
    return 0;
}
```
**Question:** What is the output?  
**Answer:** `10, 11, 20, 21`  
**Explanation:**  
- `APPLE` is explicitly set to `10`.  
- `BANANA` increments to `11`.  
- `MANGO` is set to `20`, and `ORANGE` increments to `21`.

---

#### **Quiz 3: Mixed Explicit/Implicit Assignment**
**Code:**
```c
#include <stdio.h>

enum days {
    MON = 5,
    TUE,
    WED = 10,
    THU,
    FRI,
    SAT = -1,
    SUN
};

int main() {
    printf("%d, %d, %d, %d, %d, %d, %d", 
           MON, TUE, WED, THU, FRI, SAT, SUN);
    return 0;
}
```
**Question:** What is the output?  
**Answer:** `5, 6, 10, 11, 12, -1, 0`  
**Explanation:**  
- `TUE` increments to `6` after `MON = 5`.  
- `THU` and `FRI` increment from `WED = 10`.  
- `SUN` resets to `0` after `SAT = -1` (next value is `-1 + 1`).

---

#### **Quiz 4: Enum Size and Storage**
**Code:**
```c
#include <stdio.h>

enum flags {
    FLAG_A = 0xFFFFFFFF,
    FLAG_B
};

int main() {
    printf("Size: %d bytes, FLAG_B = %d", sizeof(enum flags), FLAG_B);
    return 0;
}
```
**Question:** What is the output?  
**Answer (Compiler-Dependent):**  
- Typical output: `Size: 4 bytes, FLAG_B = 0`  
**Explanation:**  
- Enums are usually `int`-sized (4 bytes).  
- `FLAG_B` overflows `0xFFFFFFFF` (max 32-bit unsigned) and wraps to `0`.

---

#### **Quiz 5: Enums in Switch Statements**
**Code:**
```c
#include <stdio.h>

enum state { IDLE, RUNNING, STOPPED };

int main() {
    enum state s = RUNNING;
    switch (s) {
        case IDLE:    printf("IDLE"); break;
        case RUNNING: printf("RUNNING"); break;
        case STOPPED: printf("STOPPED"); break;
    }
    return 0;
}
```
**Question:** What is the output?  
**Answer:** `RUNNING`  
**Explanation:** The switch matches `RUNNING` (value `1`) and executes its case.

---

#### **Quiz 6: Enums with Duplicate Values**
**Code:**
```c
#include <stdio.h>

enum response { NO = 0, FALSE = 0, YES = 1, TRUE = 1 };

int main() {
    printf("%d, %d, %d, %d", NO, FALSE, YES, TRUE);
    return 0;
}
```
**Question:** What is the output?  
**Answer:** `0, 0, 1, 1`  
**Explanation:** Multiple enum members can share the same value.

---

### **Bonus: Tricky Enum Question**
**Code:**
```c
#include <stdio.h>

enum { A, B = 5, C, D = 2, E };

int main() {
    printf("%d, %d, %d, %d, %d", A, B, C, D, E);
    return 0;
}
```
**Question:** What is the output?  
**Answer:** `0, 5, 6, 2, 3`  
**Explanation:**  
- `A` starts at `0`.  
- `B` is set to `5`, so `C` increments to `6`.  
- `D` resets to `2`, and `E` increments to `3`.

---

### **Key Takeaways**
1. Default enum values start at `0` and increment by 1.  
2. Explicit assignments override defaults; subsequent values increment from there.  
3. Enums can share values and even overflow/wrap around.  
4. Size of an enum is compiler-dependent but typically matches `int` (4 bytes).  
