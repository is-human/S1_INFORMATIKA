//BelajarDoubleLinkedListCircular1.c
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

address createNode(){
    address newNode = malloc(sizeof(struct Node));
    printf("Input New Node Value: ");
    scanf("%d", &(newNode->data));
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(list_integer *l){
    address newNode = createNode();
    if((l->first == NULL) && (l->last == NULL)){
        newNode->prev = newNode;
        newNode->next = newNode;
        l->first = newNode;
        l->last = newNode;
    }else{
        newNode->next = l->first;
        l->first->prev = newNode;
        l->first = newNode;
        l->first->prev = l->last;
        l->last->next = l->first;
    }
}

void insertlast(list_integer *l){
    address newNode = createNode();
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

void insertAfter(list_integer *l){
    int value;
    printf("Input New Node After: ");
    scanf("%d", &value);
    if((l->first == NULL) && (l->last == NULL)){
        printf("Linked List is Currently Empty.\n");
        system("pause");
    }else{
        address temp = l->first;
        while(temp->next != l->first){
            if(temp->data == value) break;
            temp = temp->next;
        }
        if(temp->data == value){
            address newNode = createNode();
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
}

void deleteFirst(list_integer *l){
    if((l->first != NULL) && (l->last != NULL)){
        if(l->first == l->last){
            free(l->first);
            l->first = NULL;
            l->last = NULL;
        }else{
            address temp = l->first;
            l->first = temp->next;
            l->first->prev = l->last;
            l->last->next = l->first;
            free(temp);
        }
    }
}

void deleteLast(list_integer *l){
    if((l->first != NULL) && (l->last != NULL)){
        if(l->first == l->last){
            free(l->first);
            l->first = NULL;
            l->last = NULL;
        }else{
            address temp = l->last;
            l->last = temp->prev;
            l->last->next = l->first;
            l->first->prev = l->last;
            free(temp);
        }
    }
}

void deleteNode(list_integer *l){
    int value;
    printf("Delete Node: ");
    scanf("%d", &value);
    if((l->first == NULL) && (l->last == NULL)){
        printf("Linked List is Currently Empty.\n");
        system("pause");
    }else{
        address temp = l->first;
        while(temp->next != l->first){
            if(temp->data == value) break;
            temp = temp->next;
        }
        if(temp->data == value){
            address buff = temp;
            if(l->first == l->last){
                l->first = NULL;
                l->last = NULL;
            }else if(l->first == temp){
                l->first = temp->next; 
                l->first->prev = l->last; 
                l->last->next = l->first; 
            }else if(l->last == temp){
                l->last = temp->prev; 
                l->last->next = l->first; 
                l->first->prev = l->last; 
            }else{
                temp->prev->next = buff->next;
                temp->next->prev = buff->prev;
            }
            free(buff);
        }else{
            printf("%d is Unavailable in Current Linked List.\n", value);
            system("pause");
        }
    }
}

void searchNode(list_integer l){
    int value, count = 1;
    printf("Search Node: ");
    scanf("%d", &value);
    if((l.first == NULL) && (l.last == NULL)){
        printf("Linked List is Currently Empty.\n");
        system("pause");
    }else{
        address temp = l.first;
        while(temp->next != l.first){
            if(temp->data == value) break;
            temp = temp->next;
            count++;
        }
        if(temp->data == value){
            printf("%d is Currently on %d Column of Linked List.\n", value, count);
            system("pause");
        }else{
            printf("%d is Unavailable in Current Linked List.\n", value);
            system("pause");
        }
    }
}

void printList(list_integer l){
    if(l.first == NULL){
        printf("[Empty]\n");
    }else{
        address temp = l.first;
        while(temp->next != l.first){
            printf("[%d] ", temp->data);
            temp = temp->next;
        }
        printf("[%d]\n", temp->data);
    }
}

void main(){
    list_integer l;
    createList(&l);
    int choice;
    while(1){
        system("cls");
        printf("--- Belajar Double Linked List Circular ---\n");
        printList(l);
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert After\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete Node\n");
        printf("7. Search Node\n");
        printf("0. Exit Program\n\n");
        printf("Choose Option: ");
        scanf("%d", &choice);
        if(choice == 1){
            insertFirst(&l);
        }else if(choice == 2){
            insertlast(&l);
        }else if(choice == 3){
            insertAfter(&l);
        }else if(choice == 4){
            deleteFirst(&l);
        }else if(choice == 5){
            deleteLast(&l);
        }else if(choice == 6){
            deleteNode(&l);
        }else if(choice == 7){
            searchNode(l);
        }
        
        else if(choice == 0){
            printf("\nProgrem Ends.");
            exit(0);
        }
    }
}