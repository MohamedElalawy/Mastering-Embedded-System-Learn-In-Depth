![Screenshot 2025-04-16 101510](https://github.com/user-attachments/assets/41a39ca3-aac5-4c4c-9ae1-3c2b8ce9f4c6)

![image](https://github.com/user-attachments/assets/ec510e77-4da8-4540-8943-1c85a7a82128)

![image](https://github.com/user-attachments/assets/43c38dbb-d7b9-4326-8e90-19a8dfc6d92a)

![image](https://github.com/user-attachments/assets/db3429bc-0dca-4043-8968-cce5c3d85a37)
![image](https://github.com/user-attachments/assets/eb7b6efd-6368-4691-b2e5-7561bbb616c7)
![image](https://github.com/user-attachments/assets/6412694d-c325-4d8d-9630-18631de3f70e)
![image](https://github.com/user-attachments/assets/fae45ad1-bf31-45a3-88ae-a85efceff7da)
![image](https://github.com/user-attachments/assets/4b7a3a2c-314f-4d09-a4a9-d11290ad5bbb)

| Expression | Action                  | Effect                                                                 |
|------------|-------------------------|------------------------------------------------------------------------|
| `*ptr++`   | **Post-increment pointer** | Returns the current value, then moves `ptr` to the next address.       |
| `++*ptr`   | **Pre-increment value**    | Increments the value at `ptr` and returns the new value.               |

![image](https://github.com/user-attachments/assets/558a56fa-3721-49f4-b306-2d0a8a0b71f3)
![image](https://github.com/user-attachments/assets/6d63a24a-b15d-4978-8fba-707cb16901c4)

![image](https://github.com/user-attachments/assets/2797037f-13fd-4522-8366-bd16391b0f4d)
![image](https://github.com/user-attachments/assets/5bf21ee1-0dec-4352-98c3-f73dd1702006)
![image](https://github.com/user-attachments/assets/2b9ba64c-d548-4996-ab47-714502521a02)
![image](https://github.com/user-attachments/assets/93cae2f2-107c-4a04-8693-d56951ea08fe)
![image](https://github.com/user-attachments/assets/d62c72f6-1aaf-49ca-8b00-48c43208b066)

![image](https://github.com/user-attachments/assets/34f52626-bbe2-42a2-975b-be5ca0d874b0)
![image](https://github.com/user-attachments/assets/a39b897d-a28a-4663-aa99-5722de3b84aa)


![image](https://github.com/user-attachments/assets/4e70ead9-02f6-4b9d-8f62-74366ed80590)

![image](https://github.com/user-attachments/assets/733e4325-e2c3-44c7-a0da-8e2e72bb5704)

![image](https://github.com/user-attachments/assets/1d91d194-c8a0-46ec-af59-4f617c8e9ba5)

![image](https://github.com/user-attachments/assets/cda004ee-c2cb-4a04-8465-5c035f52276e)
```
can't dereference void pointer
```
![image](https://github.com/user-attachments/assets/32c8e8ef-78be-4aa5-86cb-286cdd90588a)


![image](https://github.com/user-attachments/assets/654bb714-01fa-4d46-a6a8-af871bb26511)


![image](https://github.com/user-attachments/assets/74854bec-066d-4c1b-aff0-50370914d3ed)

![image](https://github.com/user-attachments/assets/f9626ad4-e4d7-4b8d-b004-74d1049ced1a)



![image](https://github.com/user-attachments/assets/6bf0d02e-e1ed-4ad2-bcff-a80e9561dc0b)
![image](https://github.com/user-attachments/assets/ca1a59c2-5ff1-4564-b301-ba64826d6ccf)


# Explanation of Code Snippets
![image](https://github.com/user-attachments/assets/2136dc40-7531-4fd2-853d-bff39625a63f)

## 1. String Literal vs. Character Array

### String Literal (Pointer):
```c
char *str = "mohamed";
str = str + 1;  // Now points to "ohamed"
```
- `str` is a pointer to a string literal in read-only memory
- You can modify the pointer (make it point elsewhere)
- You cannot modify the string content (undefined behavior if you try)

### Character Array:
```c
char arr[10] = "hello";
str = arr;  // Now str points to the array
str[0] = 'h';  // This is valid
```
- `arr` is a modifiable character array on the stack
- Contents can be changed
- Size is fixed at declaration (10 in this case)

## 2. Pointer Arithmetic
```c
str = str + 1;  // Moves pointer to next character
```
- This works for both string literals and arrays
- The pointer now points to the next memory location (next character)

## 3. String Literal Assignment
```c
char *str = "mohamed";
str = arr;  // Pointer reassignment
```
- The pointer can be reassigned to point to something else
- The original string literal remains unchanged in read-only memory

## 4. Array Assignment
```c
char arr[10] = "hello";
```
- Array size must accommodate the string plus null terminator
- Contents can be modified (unlike string literals)

## 5. Modification Differences
```c
str[0] = 'h';  // Valid for arrays, invalid for string literals
```
- Works when `str` points to an array
- Would cause undefined behavior if `str` pointed to a string literal

## Key Differences Summary:
1. **String Literals** are immutable (read-only), while **character arrays** are mutable
2. **Pointers** can be reassigned, while **array names** cannot (though their contents can change)
3. Both support pointer arithmetic
4. String literals have automatic null termination, while arrays need proper sizing

```

```

![Screenshot 2025-04-18 113209](https://github.com/user-attachments/assets/63d53d01-21d1-415f-aa48-b285623ba320)

![image](https://github.com/user-attachments/assets/50ddb312-4351-46cc-8572-0173f0d76a0c)

![image](https://github.com/user-attachments/assets/016102da-ee6d-4d00-8f4b-492c33651b17)

Exactly! You’re absolutely right 💡

### Clarification:
- In C, `(void *)0` is the standard **implementation-defined representation** of the **null pointer constant**.
- It’s often used in low-level code and libraries as the cleanest way to express a pointer to “nowhere.”
- The macro `NULL` is usually defined as `((void *)0)` in C (or just `0` in C++ for type compatibility).

### So in your code:
```c
char *p = (char *)0;
```
This is:
```c
char *p = (char *)NULL;
```
Which means `p` points to address `0`.

### Why casting matters:
Pointer arithmetic like `p + 1` works correctly because:
- Pointer arithmetic is based on the size of the type it points to.
- `p + 1` does not mean “add 1 to the address,” but “advance the pointer by 1 element,” which is `sizeof(type)` bytes.

So:
- `(char *)0 + 1` = address `0 + 1 byte`
- `(int *)0 + 1` = address `0 + 4 bytes`
- etc.




















