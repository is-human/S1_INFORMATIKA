#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 10

typedef struct{
    int data[MAX];
    int front; //depan
    int rear;  //belakang
}Queue;

void init(Queue *queue){
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(Queue *queue){
    return queue->front == -1 && queue->rear == -1;
}

bool isFull(Queue *queue){
    return queue->rear == MAX - 1;
}

//menambahkan data baru ke queue
void enqueue(Queue *queue, int newValue){
    if(!isFull(queue)){
        if(isEmpty(queue)){
            queue->front++;
        }
        queue->data[++queue->rear] = newValue;
        return;
    }
    printf("Queue penuh!\n");
}

//menghapus data paling depan queue
void dequeue(Queue *queue){
    if(!isEmpty(queue)){
        if(queue->front == 0 && queue->rear == 0){
            queue->front--;
            queue->rear--;
            return;
        }
        for(int i = queue->front + 1; i < queue->rear +1; i++){
            queue->data[i-1] = queue->data[i];
        }
        queue->rear--;
        return;
    }
    printf("Queue kosong\n");
    
}

int size(Queue *queue){
    return queue->rear + 1;
}

//meilahat data paling depan
int front(Queue *queue){
    //operasi ternary
    return !isEmpty(queue) ? queue->data[queue->front] : -1;
}

//menampilkan queue
void printQueue(Queue *queue){
    if(!isEmpty(queue)){
        for(int i = 0; i <= queue->rear; i++){
            printf("%d ", queue->data[i]);
        }
        printf("\n");
        return;
    }
    printf("Queue kosong\n");
}

void main(){
    Queue queue;
    init(&queue);
    int option, temp;
    while(1){
        system("cls");
        printf("-----------------------------------\n");
        printf("Queue\t: ");
        printQueue(&queue);
        printf("Front\t: %d\n", front(&queue));
        printf("Size\t: %d\n", size(&queue));
        printf("-----------------------------------\n");
        printf("Options\t:");
        printf(" 1. Enqueue\n");
        printf("\t  2. Dequeue\n");
        printf("\t  3. Exit\n");
        printf("Masukkan opsi : ");
        scanf("%d", &option);
        if(option == 1){
            printf("Masukkan nilai baru: ");
            scanf("%d", &temp);
            enqueue(&queue, temp);
        }else if(option == 2){
            dequeue(&queue);
        }else if(option == 3){ break; }
        else{
            printf("Opsi tidak valid.\n");
            system("pause");
        }
    }
}