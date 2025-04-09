```C
#include <stdio.h>
#include <conio.h>

void india();
void usa();

#pragma startup india 105
#pragma startup usa 
#pragma exit usa 
#pragma exit india 105

void main() {
    printf("\nI am in main");
    getch();
}

void india() {
    printf("\nI am in india");
    getch();
}

void usa() {
    printf("\nI am in usa");
    getch();
}


```
## For gcc and clang:
![Screenshot 2025-04-09 204254](https://github.com/user-attachments/assets/c40fc6cf-2de6-46c0-bf14-727c71ed82d0)
