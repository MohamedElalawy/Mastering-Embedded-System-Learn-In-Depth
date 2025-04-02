```C
/*
 * main.c
 *
 *  Created on: Mar 23, 2025
 *      Author: Muhamad Elalawy
 */
#include "stdio.h"
struct SComplex {
    double m_R;
    double m_I;
};
struct SComplex ReadComplex(char name[]) {
    struct SComplex num;
    printf("Enter Real and Imaginary parts of %s: ", name);
    fflush(stdin);  fflush(stdout);
    scanf("%lf %lf", &num.m_R, &num.m_I);
    return num;
}
struct SComplex AddComplex(struct SComplex A, struct SComplex B) {
    struct SComplex result;
    result.m_R = A.m_R + B.m_R;
    result.m_I = A.m_I + B.m_I;
    return result;
}
void PrintComplex(char name[], struct SComplex C) {
    printf("%s = %.2lf + %.2lfi\n", name, C.m_R, C.m_I);
}
int main() {
    struct SComplex num1, num2, sum;
    num1 = ReadComplex("First Complex Number");
    num2 = ReadComplex("Second Complex Number");
    sum = AddComplex(num1, num2);
    PrintComplex("Sum", sum);

    return 0;
}
```
![Screenshot 2025-04-02 105736](https://github.com/user-attachments/assets/3e6447ac-6656-49c5-ae35-80bf437be82d)
