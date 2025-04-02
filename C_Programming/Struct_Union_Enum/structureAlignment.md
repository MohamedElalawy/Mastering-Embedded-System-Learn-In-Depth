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

