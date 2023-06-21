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
    printf("Masukkan Nilai: ");
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
        temp->prev = newNode;
        newNode->next = temp;
        node = newNode;
    }
    return node;
}

Node *moveNodes(Node *nodeA, Node *nodeB){
    Node *tempA = NULL;
    Node *tempB = NULL;
    while(nodeA->next != NULL){
        if(nodeB == NULL){
            nodeB = nodeA;
            nodeA = nodeA->next;
            nodeB->next = NULL;
            nodeA->prev = NULL;
        }else{
            tempB = nodeB;
            nodeB->prev = nodeA;
            nodeA = nodeA->next;
            nodeB = nodeB->prev;
            nodeB->next = tempB;
        }
    }
    tempB = nodeB;
    nodeB->prev = nodeA;
    nodeB = nodeB->prev;
    nodeB->next = tempB;
    nodeB->prev = NULL;
    return nodeB;
}

void showList(Node *node){
    if(node == NULL){
        printf("\nKok tidak ada?");
    }else{
        while(node->next != NULL){
            printf("%d ", node->data);
            node = node->next;
        }
        printf("%d\n", node->data);
    }
}

void main(){
    Node *head_A = NULL;
    Node *head_B = NULL;
    int pilihan;
    printf("------------- PROGRAM REVERSE DLL STACK -------------\n");
    do{
        head_A = insertNode(head_A);
        printf("Tambah nilai lagi? 999 = Exit : ");
        scanf(" %d", &pilihan);
    }while(pilihan != 999);
    printf("Stack sebelum di-reverse: ");
    showList(head_A);
    head_B = moveNodes(head_A, head_B);
    printf("Stack sesudah di-reverse: ");
    showList(head_B);
}
