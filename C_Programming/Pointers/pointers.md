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

