#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    char name[MAX];
    int priority;
}Patient;

typedef struct {
    Patient pasien[MAX];
    int front;
    int rear;
}Queue;

void init(Queue *queue){
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue){
    return queue->front == -1 && queue->rear == -1;
}

int isFull(Queue *queue){
    return queue->rear == MAX - 1;
}

void enqueue(Queue *queue, char n[], int p){
    if(!isFull(queue)){
        if(isEmpty(queue)){
            queue->front++;
        }
        strcpy(queue->pasien[++queue->rear].name, n);
        queue->pasien[queue->rear].priority = p;
        return;
    }
    printf("Queue is full.\n");
}

void printPriority(Queue *queue){
    for(int i = 0; i <= queue->rear; i++){
        if(queue->pasien[i].priority < 5) {
            printf("- %s ditangani dokter umum.\n", queue->pasien[i].name);
            continue;
        } printf("- %s ditangani dokter spesialis.\n", queue->pasien[i].name);
    }
}

void main(){
    Queue pasien;
    init(&pasien);
    int temp_i, count;
    char temp_s[20];
    system("cls");
    printf("Jumlah Pasien\t\t: ");
    scanf("%d", &count);
    printf("\n");
    for(int i = 0; i < count; i++){
        printf("Nama Pasien ke-%d\t: ", i+1);
        scanf("%s", temp_s);
        printf("Prioritas Pasien ke-%i\t: ", i+1);
        scanf("%d", &temp_i);
        enqueue(&pasien, temp_s, temp_i);
    }
    printf("\n");
    printPriority(&pasien);
}