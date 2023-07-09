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

address insertNode(list_integer *l, int val){
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
    return newNode;
}

void shuffleList(list_integer *l, address *listAddr){
    address temp;
    for (int i = 0; i < 5 - 1; i++){
        int j = i + rand() / (RAND_MAX / (5 - i) + 1);
        temp = listAddr[j];
        listAddr[j] = listAddr[i];
        listAddr[i] = temp;
    }

    for(int i = 0; i < 4; i++){
        if(i == 0){
            l->first = listAddr[0];
            l->last = listAddr[4];
            l->first->next = listAddr[1];
            l->first->prev = l->last;
            l->last->next = l->first;
            l->last->prev = listAddr[3];
        }else{
            listAddr[i]->next = listAddr[i+1];
            listAddr[i]->prev = listAddr[i-1];
        }
    }
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
    address listAddr[5];

    printf("List sebelum diacak : ");
    for(int i = 0; i < 5; i++){
        scanf("%d", &temp);
        listAddr[i] = insertNode(&list, temp);
    }
    shuffleList(&list, listAddr);
    printf("List setelah diacak : ");
    printList(&list);
}
