#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char label;
    int data;
    struct Node *next;
}Node;

Node *createNode(char alphabet){
    Node *newNode = malloc(sizeof(Node));
    scanf(" %d", &(newNode->data));
    newNode->label = alphabet;
    return newNode;
}

Node *insertNodes(Node *node, int len){
    Node *newNode[len];
    Node *tail = NULL;
    char alph = 'A';
    for(int i = 0; i < len; i++){        
        printf("Jarak Terminal %c - %c : ", alph, (i+1 == len) ? 'A' : alph+1);
        newNode[i] = createNode(alph);
        if(node == NULL){
            node = newNode[0];
            tail = node;
        }else{
            tail->next = newNode[i];
            tail = tail->next;
        }
        alph++;
        if(i + 1 == len) tail->next = node;
    }
    return node;
}

void traverseNodes(Node *node, int distance){
    if(node == NULL){
        printf("Mau ke mana gan?");
        return;
    }else{
        Node *tail = node;
        int keblablasan = -1;
        while(1){
            if(tail == node) keblablasan++;
            distance -= tail->data;
            if(distance < 2 && distance > -2){
                tail = tail->next;
                if(tail == node) keblablasan++;
                break;
            }else if(distance > 1 && distance < (tail->next->data - 1)) break;
            tail = tail->next;
        }
        printf("\nAndi turun di terminal %c.\n", tail->label);
        if(keblablasan > 0) printf("Andi telah berputar sebanyak %d kali.\n", keblablasan);
    }
}

int main(){
    Node *head = NULL;
    int len, dist;
    printf("Jarak Tujuan\t : ");
    scanf("%d", &dist);
    printf("Jumlah Terminal  : ");
    scanf("%d", &len);
    head = insertNodes(head, len);
    traverseNodes(head, dist);
    return 0;
}