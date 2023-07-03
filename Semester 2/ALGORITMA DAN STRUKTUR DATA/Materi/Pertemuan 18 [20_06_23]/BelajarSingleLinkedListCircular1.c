#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node *createNode(){
    Node *newNode = malloc(sizeof(Node));
    printf("Add value : ");
    scanf("%d", &(newNode->value));
    return newNode;
}

Node *addNode(Node *node){
    Node *newNode = createNode();
    if(node == NULL){
        newNode->next = newNode;
        node = newNode;
    }else{
        Node *tail = node;
        while(tail->next != node){
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = node;
    }
    return node;
}

Node *deleteLast(Node *node){
    Node *tail = node;
    if(tail->next == node){
        free(tail);
        return NULL;
    }
    while(tail->next->next != node){
        tail = tail->next;
    }
    Node *temp = tail->next;
    tail->next = node;
    free(temp);
    return node;
}

void traversalNode(Node *node){
    if(node == NULL){
        printf("[Kosong]");
        return;
    }else{
        Node *tail = node;
        while(tail->next != node){
            printf("[%d] ", tail->value);
            tail = tail->next;
        }
        printf("[%d] ", tail->value);
    }
}

Node *insertFirst(Node *node){
    Node *newNode = createNode();
    Node *tail = node;
    while(tail->next != node){
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->next = node;
    return newNode;
}

Node *deleteFirst(Node *node){
    Node *tail = node;
    if(tail->next == node){
        free(tail);
        return NULL;
    }
    while(tail->next != node){
        tail = tail->next;
    }
    tail->next = node->next;
    free(node);
    tail->next = NULL;
    return tail->next;
}

int main()
{
    Node *head = NULL;
    int choice;
    do{
        system("cls");
        traversalNode(head);
        printf("\nMenu : \n");
        printf("1. Insert Node\n");
        printf("2. Insert First\n");
        printf("3. Delete First\n");
        printf("4. Delete Last\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        if (choice == 1){
            head = addNode(head);
        }
        else if (choice == 2){
            head = insertFirst(head);
        }
        else if (choice == 3){
            head = deleteFirst(head);
        }
        else if (choice == 4){
            head = deleteLast(head);
        }
    } while (choice != 0);
}