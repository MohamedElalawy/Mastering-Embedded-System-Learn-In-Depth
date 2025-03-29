```C
/*
 * main.c
 *
 *  Created on: Mar 19, 2025
 *      Author: Muhamad Elalawy
 */
#include"stdio.h"

/*EX1:*/
int main(int argc, char **argv){
	printf("C Programming\n");

	return 0;
}
```
![Screenshot 2025-03-28 171838](https://github.com/user-attachments/assets/fe0ed9c3-462b-4a55-ab6c-3e539351d6a5)

```C
#include"stdio.h"

/*EX2:*/
int main(int argc, char **argv){
	int i;
	printf("Enter Integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%i",&i);
	printf("You Entered: %i",i);

	return 0;
}

```
![Screenshot 2025-03-28 173021](https://github.com/user-attachments/assets/f313a18f-8893-460d-becc-190433e73b5f)

```C
#include"stdio.h"

/*EX3:*/
int main(int argc, char **argv){
	int i,j;
	printf("Enter Two Integers: ");
	fflush(stdin);fflush(stdout);
	scanf("%i %i",&i,&j);
	printf("Sum: %i",i+j);

	return 0;
}
```
![Screenshot 2025-03-28 173707](https://github.com/user-attachments/assets/8378df4a-e87e-4b6e-9575-e1c1a9bdaabb)


```C
#include"stdio.h"

/*EX4:*/
int main(int argc, char **argv){
	float i,j;
	printf("Enter two numbers: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&i,&j);
	printf("Product: %f",i*j);

	return 0;
}
```
![Screenshot 2025-03-28 174316](https://github.com/user-attachments/assets/1dc19101-317f-4d34-bc49-22bae7fdbd41)


```C
#include"stdio.h"

/*EX5:*/
int main(int argc, char **argv){
	char c;
	printf("Enter a character: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);
	printf("ASCII value of %c = %i",c,c);

	return 0;
}
```
![Screenshot 2025-03-28 174646](https://github.com/user-attachments/assets/fe550e8a-13d3-4806-bc2e-ade40e6293bf)


```C
#include"stdio.h"

/*EX6 Swapping method1 with temp var:*/
int main(int argc, char **argv){
	int a,b,t;
	printf("Enter value of a and b : ");
	fflush(stdin);fflush(stdout);
	scanf("%i %i",&a,&b);
	t = a;
	a=b;
	b=t;

	printf("After swapping, value of a = %i\n",a);
	printf("After swapping, value of b = %i\n",b);

	return 0;
}
```
![Screenshot 2025-03-28 175504](https://github.com/user-attachments/assets/082542bc-d70e-4165-931e-75ede7ff087c)

```C
#include"stdio.h"

/*EX7 Swapping method2 without temp var:*/
int main(int argc, char **argv){
	int a,b;
	printf("Enter value of a and b : ");
	fflush(stdin);fflush(stdout);
	scanf("%i %i",&a,&b);
	a = a+b;
	b = a-b;
	a= a-b;
	printf("After swapping, value of a = %i\n",a);
	printf("After swapping, value of b = %i\n",b);

	return 0;
}
```
![Screenshot 2025-03-28 175904](https://github.com/user-attachments/assets/d04ab12d-ad6f-43ef-bdb2-615cb75e1164)


```C
#include"stdio.h"
/*EX7 Swapping method3 without temp var:*/
int main(int argc, char **argv){
	int a,b;
	printf("Enter value of a and b : ");
	fflush(stdin);fflush(stdout);
	scanf("%i %i",&a,&b);
	a = a^b;
	b = a^b;
	a= a^b;
	printf("After swapping, value of a = %i\n",a);
	printf("After swapping, value of b = %i\n",b);

	return 0;
}
```
![Screenshot 2025-03-28 180419](https://github.com/user-attachments/assets/37e7b7bc-1cc6-4501-bbfd-b18b52b5eeac)



