#include <stdio.h>

int main(){
    int x = 10;
    int *ptr1 = &x;
    int **ptr2 = &ptr1;

    printf("x = %d", x);
    printf("\n&x = %d", &x);

    printf("\n\nptr1 = %d", ptr1);
    printf("\n&ptr1 = %d", &ptr1);
    printf("\n*ptr1 = %d", *ptr1);
    
    printf("\n\nptr2 = %d", ptr2);
    printf("\n&ptr2 = %d", &ptr2);
    printf("\n*ptr2 = %d", *ptr2);
    printf("\n**ptr2 = %d", **ptr2);
}