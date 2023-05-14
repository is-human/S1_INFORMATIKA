#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef struct Stack{
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

//membuat Stack kosong
void createEmptyStack(Stack * stack){
    stack->top = -1;
}

//Mengecek apakah Stack kosong atau tidak
int isEmpty(Stack *stack){
    return stack->top == -1;
}

//Mengecek apakah stack penuh atau tidak
int isFull(Stack *stack){
    return stack->top == MAX_STACK_SIZE - 1;
}

//Mengecek element top(teratas/terbaru) dalam Stack tanpa menghapus element tersebut dari stack
int peek(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack kosong.\n");
        return -1;
    }
    return stack->data[stack->top];
}

//Memasukkan element ke dalam Stack
void push(Stack *stack, int nilai){
    if(isFull(stack)){
        printf("Stack penuh.\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = nilai;
    //alt(2 baris di atas): stack->data[stack->top++] = nilai;
}

//Menarik atau menghapus element paling atas/baru (top)
int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack kosong.\n");
        return -1;
    }
    int nilai = stack->data[stack->top];
    stack->top--;
    return nilai;
}

//Menampilkan element dalam Stack
void printStack(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack kosong.\n");
        return;
    }
    printf("\nStack: ");
    for(int i = stack->top; i >= 0; i--){
        printf("%d ", stack->data[i]);
    }
}

//Fungsi main untuk menguji Stack
int main(){
    Stack punyaku;
    createEmptyStack(&punyaku);
    int pilihan, nilai;
    while (1){
        system("cls");
        printStack(&punyaku);
        printf("\nAction Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. End\n");
        printf("Pilihan anda: ");
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:
                printf("Masukkan elemen baru: ");
                scanf("%d", &nilai);
                push(&punyaku, nilai);
                break;
            case 2:
                nilai = pop(&punyaku);
                if(nilai != -1){
                    printf("Menghapus elemen paling baru.\n");
                    printf("Elemen [%d] berhasil dihapus.\n", nilai);
                }
                system("pause");
                break;
            case 3:
                nilai = peek(&punyaku); 
                if(nilai != -1){
                    printf("Elemen paling baru/atas adalah [%d]\n", nilai);
                }
                system("pause");
                break;
            case 4:
                printf("Terimakasih.\n");
                return 0;
            default:
                printf("Error: Pilihan tidak valid.\n");
                system("pause");
                break;
        }
    }
}