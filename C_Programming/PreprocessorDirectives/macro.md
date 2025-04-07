![Screenshot 2025-04-07 063620](https://github.com/user-attachments/assets/55da3349-9132-44e6-9584-2443bbb7df17)



![Screenshot 2025-04-07 065859](https://github.com/user-attachments/assets/9cdbef91-bc27-4e5b-ab39-72a2c0b95f55)
```C
#include <stdio.h>

#define PR(value, maxValue) (100.0 * value/(double)maxValue)

int main(int argc, char**argv){
    printf("Enter subject degree followed by the maximum degree:\n\n");
    printf("Arabic:");
    printf("Arabic degree is %lf\n", PR(40,50));
    printf("Math:");
    printf("Math degree is %lf\n", PR(30,50));
    printf("Physics:");
    printf("Physics degree is %lf\n", PR(20,50));
    printf("English:");
    printf("English degree is %lf\n", PR(50,50));
	return 0;
}
```
![Screenshot 2025-04-07 072050](https://github.com/user-attachments/assets/98f5f6bf-1b5d-4311-8bc8-8fa89ac6996d)
