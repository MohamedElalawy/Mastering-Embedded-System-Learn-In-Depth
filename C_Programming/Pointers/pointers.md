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
