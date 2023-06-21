#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}Node;

Node *createNode(){
    Node *newNode = NULL;
    newNode = (Node*) malloc(sizeof(Node));
    printf("Masukkan bilangan : ");
    scanf("%d", &(newNode->data));
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *insertNode(Node *node){
    Node *newNode = createNode();
    if(node == NULL){
        node = newNode;
    }else{
        Node *temp = node;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return node;
}

void showList(Node *node){
    if(node == NULL){
        printf("\nKok tidak ada?");
    }else{
        printf("Data bilangan yang telah diinputkan secara FIFO : \n");
        while(node->next != NULL){
            printf("%d\t", node->data);
            node = node->next;
        }
        printf("%d\t", node->data);
        printf("\nData bilangan yang telah diinputkan secara LIFO : \n");
        while(node->prev != NULL){
            printf("%d\t", node->data);
            node = node->prev;
            free(node->next);
        }
        printf("%d\t", node->data);
        free(node);
        //sudah selesai hore
    }
}

void main(){
    Node *head = NULL;
    char pilihan;
    printf("------------- PROGRAM DLL FIFO & LIFO -------------\n");
    do{
        head = insertNode(head);
        printf("Ada data lagi(y/t): ");
        scanf(" %c", &pilihan);
    }while(pilihan == 'y');
    showList(head);
}
