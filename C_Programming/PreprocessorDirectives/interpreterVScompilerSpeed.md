**Bash** and **C** that does the same task — for example, summing numbers from 1 to 1,000,000 — and then measure the time it takes for each:

---

###  **Sum numbers from 1 to 1,000,000**

---

### **C Code**

```c
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();

    long long sum = 0;
    for (int i = 1; i <= 1000000; ++i) {
        sum += i;
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("C Code: Sum = %lld\n", sum);
    printf("C Code: Time taken = %f seconds\n", time_taken);

    return 0;
}
```
![Screenshot 2025-04-06 073817](https://github.com/user-attachments/assets/9b5270db-d257-41cc-a8ae-5b4a1cac0b10)


### **Bash Script**

```bash
#!/bin/bash

start=$(date +%s.%N)

sum=0
for ((i=1; i<=1000000; i++)); do
    sum=$((sum + i))
done

end=$(date +%s.%N)

# Print directly with `awk` for better float precision
echo "Bash Script: Sum = $sum"
echo | awk -v s="$start" -v e="$end" '{ printf("Bash Script: Time taken = %.6f seconds\n", e - s) }'
```
![Screenshot 2025-04-06 074301](https://github.com/user-attachments/assets/a15fa3cc-9aa2-4a7b-9c6e-c6cfd9bf18c5)

### 📊 **Expected Result**
You’ll likely see the C code is **much faster** due to being compiled and lower-level, while Bash will be **significantly slower** due to interpreted execution and shell arithmetic.
