#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node *next;
}Node;

Node *createNode(){
    Node *newNode = malloc(sizeof(Node));
    scanf("%c", &(newNode->data));
    return newNode;
}

Node *insertNodes(Node *node, int len){
    for(int i = 0; i < len; i++){        
        Node *newNode = createNode();
        if(node == NULL){
            newNode->next = node;
            node = newNode;
        }else{
            Node *tail = node;
            while(tail->next != node){
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->next = node;
        }
    }
    return node;
}

Node *deleteFromTail(Node *node, int len){
    for(int i = 0; i < len; i++){
        Node *tail = node;
        if(tail == node && tail->data == 'T'){
            free(tail);
            return NULL;
        }
        while(tail->next->next == node){
            tail->next;
        }
        if(tail->data == 'T'){
            Node *temp = tail->next;
            tail->next = node;
            free(temp);
        }else if(tail->data == 'B'){
            return node;
        }
    }
    // return node;
}

void traversalNode(Node *node){
    if(node == NULL){
        printf("[Kosong]");
        return;
    }else{
        Node *tail = node;
        while(tail->next != node){
            printf("[%d] ", tail->data);
            tail = tail->next;
        }
        printf("[%d] ", tail->data);
    }
}

int main(){
    Node *head = NULL;
    int len;
    printf("Silahkan: \n");
    scanf("&d", &len);
    printf("Masukkan: \n");
    head = insertNodes(head, len);
    printf("Delete: \n");
    head = deleteFromTail(head, len);
    printf("Tampilkan: \n");
    traversalNode(head);
    return 0;
}