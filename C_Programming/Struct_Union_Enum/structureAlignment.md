![Screenshot 2025-04-02 221152](https://github.com/user-attachments/assets/af0ba245-e455-4b80-ac62-413cc36700d9)

The reason why `sizeof(struct SData)` is **8** instead of **5** is due to **struct padding and alignment**.

### **Explanation:**
Your struct is defined as:
```c
struct SData {
    unsigned char data1; // 1 byte
    unsigned int data2;  // 4 bytes
};
```
#### **Expected Size Without Padding:**
- `unsigned char data1`: **1 byte**
- `unsigned int data2`: **4 bytes**
- **Total expected size: 1 + 4 = 5 bytes**

#### **Why Does It Become 8?**
The `unsigned int` (4 bytes) **must be aligned** to a memory address that is a multiple of 4 (since it's a 4-byte type). Here’s how the memory layout works:

| **Byte Offset** | **Data** |
|---------------|--------|
| 0            | `data1` (1 byte) |
| 1 - 3        | **Padding (3 bytes added by compiler)** |
| 4 - 7        | `data2` (4 bytes, aligned to 4-byte boundary) |

- The compiler **adds 3 padding bytes** after `data1` to ensure `data2` starts at a memory address that is a multiple of 4.
- This makes the total size **8 bytes instead of 5**.

### **Solution (Avoid Padding)**
You can optimize the structure by reordering the fields:
```c
struct SData {
    unsigned int data2;  // 4 bytes
    unsigned char data1; // 1 byte
};
```
Now, the memory layout will be:

| **Byte Offset** | **Data** |
|---------------|--------|
| 0 - 3        | `data2` (4 bytes) |
| 4            | `data1` (1 byte) |
| 5 - 7        | **Padding (3 bytes)** |

The struct size now becomes **8 bytes**, but the memory usage is more efficient.

### **Packing to Force 5 Bytes**
If you **must** have a 5-byte struct (removing padding), use `#pragma pack(1)`:
```c
#pragma pack(1)
struct SData {
    unsigned char data1;
    unsigned int data2;
};
#pragma pack()
```
Now, `sizeof(struct SData)` should return **5**.

⚠️ **Note:** Disabling padding may impact performance due to unaligned memory access.


![Screenshot 2025-04-02 223007](https://github.com/user-attachments/assets/c0ca2899-3944-4ea5-81cd-3baec098acf8)



Example2:
```C
/*
 * main.c
 *
 *  Created on: Mar 24, 2025
 *      Author: Muhamad Elalawy
 */
#include <stdio.h>

struct Sdata {
    unsigned char data1;
    unsigned int data2;
    unsigned char data3;
    unsigned short data4;
};

struct Sdata gdata;

void dump_memory(char* ptr, int size);

void main() {
    gdata.data1 = 0xAA;
    gdata.data2 = 0xFFFFFFF;
    gdata.data3 = 0x55;
    gdata.data4 = 0xA5A5;
    int total_size = sizeof(struct Sdata);
    printf("Size of struct Sdata (non packing) = %d \n", sizeof(struct Sdata));
    dump_memory((char*)&gdata, total_size);
}

void dump_memory(char* ptr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%p %x \n", ptr, (unsigned char)*ptr);
        ptr++;
    }
}
```
![Screenshot 2025-04-02 235155](https://github.com/user-attachments/assets/0ba3678e-6bef-4839-bf72-70ecfbbeb964)
Your struct likely has padding due to alignment rules. Here’s an analysis in Markdown format:

```markdown
# **Why Does `sizeof(struct Sdata)` Include Padding?**

## **Given Struct:**
```c
struct Sdata {
    unsigned char data1;  // 1 byte
    unsigned int data2;   // 4 bytes
    unsigned char data3;  // 1 byte
    unsigned short data4; // 2 bytes
};
```

## **Expected vs. Actual Memory Layout:**
### **Expected (Without Padding)**
| Variable | Type            | Size  |
|----------|---------------|-------|
| `data1`  | `unsigned char`  | 1 byte |
| `data2`  | `unsigned int`  | 4 bytes |
| `data3`  | `unsigned char`  | 1 byte |
| `data4`  | `unsigned short` | 2 bytes |
| **Total** | - | **1 + 4 + 1 + 2 = 8 bytes** |

### **Actual (With Padding)**
| Offset | Variable | Size | Notes |
|--------|----------|------|-------|
| 0      | `data1`  | 1 byte | Stored at offset 0 |
| 1 - 3  | **Padding** | 3 bytes | To align `data2` on a 4-byte boundary |
| 4 - 7  | `data2`  | 4 bytes | Starts at offset 4 |
| 8      | `data3`  | 1 byte | Stored at offset 8 |
| 9      | `data4`  | 2 bytes | Stored at offset 9 |
| 10 - 11 | **Padding** | 2 bytes | To align struct to the largest type (4 bytes) |
| **Total** | - | **12 bytes** |

### **Why Padding Occurs?**
1. `data2` (4 bytes) must start at an address multiple of 4 → **Padding added after `data1`**.
2. `data4` (2 bytes) is placed at offset **9**, but for memory efficiency, struct size is rounded to a multiple of the largest type (4 bytes) → **Padding added at the end**.

## **How to Reduce Padding?**
Rearrange the struct:
```c
struct Sdata {
    unsigned int data2;   // 4 bytes
    unsigned short data4; // 2 bytes
    unsigned char data1;  // 1 byte
    unsigned char data3;  // 1 byte
};
```
Now, `sizeof(struct Sdata)` will be **8 bytes** instead of **12**.

## **Packing (Force No Padding)**
If you want to **disable padding**, use:
```c
#pragma pack(1)
struct Sdata {
    unsigned char data1;
    unsigned int data2;
    unsigned char data3;
    unsigned short data4;
};
#pragma pack()
```
⚠️ **Note:** Removing padding may cause **performance issues** on some architectures.
```

This will help you understand why the size is larger than expected and how to optimize it.
```
![Screenshot 2025-04-02 235557](https://github.com/user-attachments/assets/cf7d457f-ad9b-40d8-ae85-2bff5af5ff02)

