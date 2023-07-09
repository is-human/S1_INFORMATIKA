#include <stdio.h>
#include <stdlib.h>

typedef struct Node *address;

struct Node{
    address prev;
    int data;
    address next;
};

typedef struct{
    address first;
    address last;
}list_integer;

void createList(list_integer *l){
    l->first = NULL;
    l->last = NULL;
}

address createNode(int val){
    address newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(list_integer *l, int val){
    address newNode = createNode(val);
    if((l->first == NULL) && (l->last == NULL)){
        newNode->prev = newNode;
        newNode->next = newNode;
        l->first = newNode;
        l->last = newNode;
    }else{
        newNode->prev = l->last;
        l->last->next = newNode;
        newNode->next = l->first;
        l->first->prev = newNode;
        l->last = newNode;
    }
}

void reverseList(list_integer *l){
    address temp;
    address curr = l->first;
    while(curr->next != l->first){
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->prev;
    }
    temp = curr->next;
    curr->next = curr->prev;
    curr->prev = temp;

    temp = l->first;
    l->first = l->last;
    l->last = temp;
}

void printList(list_integer *l){
    if(l->first == NULL){
        printf("[Empty]\n");
    }else{
        address temp = l->first;
        while(temp->next != l->first){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

void main(){
    list_integer list;
    createList(&list);
    int temp;

    printf("Sebelum di-reverse : \n");
    printf("List : ");
    while (temp != 50){
        scanf("%d", &temp);
        insertNode(&list, temp);
    }
    reverseList(&list);
    printf("Setelah di-reverse : \n");
    printf("List : ");
    printList(&list);
}
