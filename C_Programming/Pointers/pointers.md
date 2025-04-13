![Screenshot 2025-04-10 124529](https://github.com/user-attachments/assets/dbbbc790-22ca-44d4-b78f-a85094b51945)


![Screenshot 2025-04-10 130507](https://github.com/user-attachments/assets/fdd931e9-c05f-4f86-856c-d13678cd76bc)


![Screenshot 2025-04-10 140808](https://github.com/user-attachments/assets/4cdacac5-7c14-47fd-bd47-202dbf95eeeb)


## LAB 1:
```C
#include <stdio.h>
void main()
{
    int X[5];
    int sum = 0;
    int i;  
    int* pX = X;

    for(i = 0; i < sizeof(X)/sizeof(int); i++)
        scanf("%d", pX + i);

    for(i = 0; i < sizeof(X)/sizeof(int); i++)
        printf("%d\n", *pX++);
	
    pX = X;
    for(i = 0; i < sizeof(X)/sizeof(int); i++, pX++)
        sum += *pX;

    printf("sum = %d\n", sum);
}



```
![Screenshot 2025-04-10 143113](https://github.com/user-attachments/assets/e6a2cfc4-7d90-40fa-a923-1ecfdd0e5605)

## ptr to struct:
```C
#include "stdio.h"

struct SDataSet
{
    unsigned char data1;
    unsigned int data2;
    unsigned char data3;
    unsigned short data4;
};

struct SDataSet data1;

void print_memory_range(char* base, int size)
{
    int i;
    for (i = 0; i < size; i++) {  
        printf("%p \t %x \n", base, (unsigned char)*base);
        base++;
    }
}

int main()
{
    data1.data1 = 0x11;
    data1.data2 = 0xFFFFEEEE;  
    data1.data3 = 0x22;
    data1.data4 = 0xABCD;
    print_memory_range((char*)&data1, sizeof(data1));

    char* p = (char*)&data1;
    printf("p+8 = %x \n", (unsigned char)*(p+8));
    
    struct SDataSet *PStruct = &data1;  
    printf("p+8 = %x \n", (unsigned char)PStruct->data3);

    return 0;
}
```
![Screenshot 2025-04-10 145825](https://github.com/user-attachments/assets/7f0904f6-e402-4855-b3fa-51a68fed49ed)

## ptr to struct, array of structs, increment ptr by the size of struct:
```C

#include <stdio.h>
struct SPerson {
    char m_Name[18];
    int m_ID;
    char m_Age;
    short m_Salary;
    double m_Weight;
};
int main(int argc, char** argv) {
    struct SPerson manager = {"Mohamed Hady", 163, 39, 3000, 79.5};
    struct SPerson employees[] = {
        {"Mostafa Saidi", 163, 30, 1500, 81.0},
        {"Ahmed Salah", 164, 25, 1200, 91.0},
        {"Safa Fayez", 165, 28, 1400, 65.0}
    };

    int i;
    struct SPerson* p;
    p = &manager;
    printf("manager: %s, %d, %d, %d, %lf\n\n",
        p->m_Name, p->m_ID, (int)p->m_Age,
        (int)p->m_Salary, p->m_Weight);

    p->m_Salary = 4000;
    printf("manager: %s, %d, %d, %d, %lf\n\n",
        manager.m_Name, manager.m_ID,
        (int)manager.m_Age, (int)manager.m_Salary,
        manager.m_Weight);

    p = employees;
    for (i = 0; i < sizeof(employees) / sizeof(struct SPerson); i++, p++) {
        printf("employee %d: %s, %d, %d, %d, %lf\n\n",
            i, p->m_Name, p->m_ID,
            (int)p->m_Age, (int)p->m_Salary,
            p->m_Weight);
    }
    return 0;
}
```
![Screenshot 2025-04-10 180802](https://github.com/user-attachments/assets/44111d90-529c-447d-8c16-d4eb97b0a78d)

## bubble sort algorithm:
```C
void Sort(int* values /*input/output*/, int nValues /*input*/)
{
    int i, j, temp;
    for(i = 0; i < nValues - 1; i++)
        for(j = i; j < nValues; j++)
            if(values[i] > values[j])
            {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
}
```


![Screenshot 2025-04-10 183443](https://github.com/user-attachments/assets/dda3163f-115d-482b-977b-a12b0e9452a6)


## unkown / generic ptr (void pointer):
```C
#include <stdio.h>

int main() {
    int x = 5;
    double y = 10.3;
    void* p;

    p = &x;
    *(int*)p = 8;
    printf("x = %d\n", x);

    p = &y;
    *(double*)p = 3.3;
    printf("y = %lf\n", y);

    return 0;
}
```
![Screenshot 2025-04-10 183954](https://github.com/user-attachments/assets/90d64a8f-3d51-4fcf-8fcf-ee6a00c8887f)

## Universal compare function using void pointers:
```C
#include <stdio.h>
int Compare(void* value1, void* value2, int type) 
{
    int r;
    switch(type)
    {
        case 1: // Integer comparison
            if(*(int*)value1 == *(int*)value2) r = 0;
            else if(*(int*)value1 > *(int*)value2) r = 1;
            else r = -1;
            break;
            
        case 2: // Double comparison
            if(*(double*)value1 == *(double*)value2) r = 0;
            else if(*(double*)value1 > *(double*)value2) r = 1;
            else r = -1;
            break;
            
        default:
            printf("Error: Unknown type\n");
            r = 0; // Default return for unknown types
    }
    return r;
}
int main() 
{
    // Test with integers
    int a = 5, b = 10;
    int result = Compare(&a, &b, 1);
    printf("\nInteger comparison (5 vs 10): %d\n", result);
    // Test with doubles
    double x = 3.14, y = 3.14;
    result = Compare(&x, &y, 2);
    printf("\nDouble comparison (3.14 vs 3.14): %d\n\n", result); 
    return 0;
}

```
![Screenshot 2025-04-10 214035](https://github.com/user-attachments/assets/6cc97713-842b-4301-8ff1-e228112d2c01)
## pointer-to-pointer example:
```C
#include <stdio.h>

int main() {
    int x = 5, y = 9;
    int* px = &x;      // Pointer to int
    int** ppx = &px;   // Pointer to pointer to int
    
    printf("x = %d, y = %d\n", x, y);  // Initial values

    **ppx = 7;        // Modifies x through ppx -> px -> x
    printf("x = %d, y = %d\n", x, y);  // x is now 7

    *ppx = &y;        // Makes px point to y instead of x
    *px = 11;         // Modifies y through px (which now points to y)
    printf("x = %d, y = %d\n", x, y);  // y is now 11

    return 0;
}
```


![Screenshot 2025-04-10 221306](https://github.com/user-attachments/assets/bc1fb8e3-18a5-4360-b3ee-a3d6472afbcd)

## Pointer to function:

![Screenshot 2025-04-13 191104](https://github.com/user-attachments/assets/c1cc1b91-12b8-4330-94bd-56fc340da6f3)



















