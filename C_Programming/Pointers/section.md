![Screenshot 2025-04-16 101510](https://github.com/user-attachments/assets/41a39ca3-aac5-4c4c-9ae1-3c2b8ce9f4c6)

![image](https://github.com/user-attachments/assets/ec510e77-4da8-4540-8943-1c85a7a82128)

![image](https://github.com/user-attachments/assets/43c38dbb-d7b9-4326-8e90-19a8dfc6d92a)

![image](https://github.com/user-attachments/assets/db3429bc-0dca-4043-8968-cce5c3d85a37)
![image](https://github.com/user-attachments/assets/eb7b6efd-6368-4691-b2e5-7561bbb616c7)
![image](https://github.com/user-attachments/assets/6412694d-c325-4d8d-9630-18631de3f70e)
![image](https://github.com/user-attachments/assets/fae45ad1-bf31-45a3-88ae-a85efceff7da)
![image](https://github.com/user-attachments/assets/4b7a3a2c-314f-4d09-a4a9-d11290ad5bbb)

```
### **Question 9: Are the expressions `*ptr++` and `++*ptr` the same?**

#### **Answer:**
- **False** (`*ptr++` and `++*ptr` are **not** the same).  

#### **Explanation:**
1. **`*ptr++`**  
   - This is **post-increment** on the pointer `ptr`.  
   - **Behavior**:  
     - First, it **dereferences** `ptr` (gets the value it points to).  
     - Then, it **increments the pointer** (`ptr++`), making it point to the next memory location.  
   - **Example**:
     ```c
     int arr[] = {10, 20};
     int *ptr = arr;
     printf("%d\n", *ptr++); // Output: 10 (then ptr moves to &arr[1])
     ```

2. **`++*ptr`**  
   - This is **pre-increment** on the **value** pointed to by `ptr`.  
   - **Behavior**:  
     - First, it **dereferences** `ptr` (gets the value it points to).  
     - Then, it **increments the value** (`++(*ptr)`).  
   - **Example**:
     ```c
     int arr[] = {10, 20};
     int *ptr = arr;
     printf("%d\n", ++*ptr); // Output: 11 (value at arr[0] becomes 11)
     ```

#### **Key Difference:**
| Expression | Action | Effect |
|------------|--------|--------|
| `*ptr++` | **Post-increment pointer** | Returns the current value, then moves `ptr` to the next address. |
| `++*ptr` | **Pre-increment value** | Increments the value at `ptr` and returns the new value. |

**Conclusion:**  
✅ **False** (They are **not** the same).  

---

### **Question 10: What will be the output of the program?**  
*(Since no program is provided, I'll assume a common example related to `*ptr++` and `++*ptr`.)*  

#### **Example Program:**
```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30};
    int *ptr = arr;

    printf("%d\n", *ptr++);  // Output: 10 (ptr now points to arr[1])
    printf("%d\n", ++*ptr);  // Output: 21 (value at arr[1] becomes 21)
    printf("%d\n", arr[1]);  // Output: 21 (modified by ++*ptr)

    return 0;
}
```

#### **Output:**
```
10  
21  
21
```

#### **Explanation:**
1. `*ptr++` → Returns `10`, then `ptr` moves to `arr[1]`.  
2. `++*ptr` → Increments `arr[1]` (from `20` to `21`).  
3. `arr[1]` now holds `21`.  

---

### **Final Answers:**
- **Question 9:** `[✓] False`  
- **Question 10:** *(Assuming the example above)* Output:  
  ```
  10  
  21  
  21
  ```  
| Expression | Action | Effect |
|------------|--------|--------|
| `*ptr++` | **Post-increment pointer** | Returns the current value, then moves `ptr` to the next address. |
| `++*ptr` | **Pre-increment value** | Increments the value at `ptr` and returns the new value. |

```
