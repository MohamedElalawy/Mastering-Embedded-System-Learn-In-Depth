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


