#include <stdio.h>

#define MAX_LEN 5

typedef struct Kata{
    int top;
    char data[MAX_LEN];
}kata;

void balik(kata *stack){
    printf("Output  : ");
    for(int i = stack->top; i >= 0; i--){
        printf("%c", stack->data[i]);
    }
}

int main(){
    kata teks;
    teks.top = MAX_LEN-1;
    printf("Input   : ");
    fflush(stdin); gets(teks.data);
    balik(&teks);
    return 0;
}