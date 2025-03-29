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


