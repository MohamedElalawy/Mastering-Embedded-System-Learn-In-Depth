```C
/*
 * main.c
 *
 *  Created on: Mar 22, 2025
 *      Author: Muhamad Elalawy
 */
#include"stdio.h"
/*EX1 Even or Odd:*/
int main(int argc, char **argv){
	int a;
	printf("Enter an integer u want to check: ");
	fflush(stdin);fflush(stdout);
	scanf("%i",&a);
	if(a%2)
		printf("%i is Odd\n",a);
	else
		printf("%i is Even\n",a);


	return 0;
}
```
![Screenshot 2025-03-29 222736](https://github.com/user-attachments/assets/77f41c10-5cca-4597-80e4-5695e7a2df06)


```C
#include"stdio.h"
/*EX2 check vowel(a,e,o,i,u) or consonant:*/
int main(int argc, char **argv){
	char a;
	printf("Enter an alphabet: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&a);
	if(a=='a'||a=='e'||a=='o'||a=='i'||a=='u')
		printf("%c is Vowel\n",a);
	else
		printf("%i is Even\n",a);


	return 0;
}
```
![Screenshot 2025-03-29 223453](https://github.com/user-attachments/assets/03854931-fd80-4100-8fff-47a8fc1c4b50)

```C
#include"stdio.h"
/*EX3: Find largest among three numbers*/
int main(int argc, char **argv){
	float a,b, c;
	printf("Enter 3 Numbers: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f %f",&a,&b,&c);
	printf("Largest Number = ");
    if (a>=b &&a >=c) {
        printf("%0.2f\n", a);
    }
    else if (b>= a&& b >= c) {
        printf("%0.2f\n", b);
    }
    else {
        printf("%0.2f\n", c);
    }

	return 0;
}
```
![Screenshot 2025-03-29 224536](https://github.com/user-attachments/assets/c026c156-a8ac-42f2-aa95-1a0bf88b82eb)


```C
#include"stdio.h"
/*EX4: positive or negative or zero:*/
int main(int argc, char **argv){
	float a;
	printf("Enter a Number: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&a);
	printf("%0.2f ",a);
    if (a>0) {
        printf("is Positive\n");
    }
    else if (a<0) {
        printf("is Negative\n");
    }
    else {
        printf("is zero\n");
    }

	return 0;
}
```
![Screenshot 2025-03-29 225340](https://github.com/user-attachments/assets/b780ca18-2785-41fa-a6fd-654c6ed44756)


```C
#include"stdio.h"
/*EX5: Alphabet or not:*/
int main(int argc, char **argv){
		char a;
		printf("Enter a character: ");
		fflush(stdin);fflush(stdout);
		scanf("%c",&a);
		printf("%c ",a);
		if ((a>=65 && a<=90)||(a>=97 && a<=122) ) {
			printf("is an alphabet\n");
		}
		else {
			printf("is not alphabet\n");
		}

	return 0;
}
```
![Screenshot 2025-03-29 235316](https://github.com/user-attachments/assets/dc017412-881f-4f6e-b56c-705ae6d140d0)

```C
#include"stdio.h"
/*EX6: sum of natural numbers:*/
int main(int argc, char **argv){
		int a;
		printf("Enter an integer: ");
		fflush(stdin);fflush(stdout);
		scanf("%i",&a);
		int i=a;
		while (i){
			i--;
			a+=i;
		}
		printf("sum = %i ",a);


	return 0;
}
```
![Screenshot 2025-03-29 235929](https://github.com/user-attachments/assets/03214c67-a7a9-47f5-8d20-57aa5aa69887)

```C
#include"stdio.h"
/*EX7: sum of natural numbers:*/
int main(int argc, char **argv){
		int a,f=1;
		printf("Enter an integer: ");
		fflush(stdin);fflush(stdout);
		scanf("%i",&a);
		if(a==0){
			printf("Factorial = %i \n",1);
		}
		else if(a<0){
			printf("Error!!!! Factorial for negative number doesn't exist.\n");

		}
		else{
			while (a){

				f*=a;
				a--;
			}
			printf("Factorial = %i ",f);
		}
	return 0;
}
```
![Screenshot 2025-03-30 001016](https://github.com/user-attachments/assets/ce71dc87-256e-45cf-af8d-314827de3ff6)

```C
#include"stdio.h"
/*EX8: Calculator:*/
int main(int argc, char **argv) {
	char op;
	float a, b;
	printf("Enter operator either + or - or * or / : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &op);
	printf("Enter two operands: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f", &a, &b);
	switch (op) {
		case '+':
			printf("%.2f + %.2f = %.2f\n", a, b, a + b);
			break;
		case '-':
			printf("%.2f - %.2f = %.2f\n", a, b, a - b);
			break;
		case '*':
			printf("%.2f * %.2f = %.2f\n", a, b, a * b);
			break;
		case '/':
			if (b != 0)
				printf("%.2f / %.2f = %.2f\n", a, b, a / b);
			else
				printf("Error! Division by zero.\n");
			break;
		default:
			printf("Invalid operator.\n");
	}

	return 0;
}
```
![Screenshot 2025-03-30 002503](https://github.com/user-attachments/assets/f4a7fea2-dccd-4116-925e-683d5679c5e5)

