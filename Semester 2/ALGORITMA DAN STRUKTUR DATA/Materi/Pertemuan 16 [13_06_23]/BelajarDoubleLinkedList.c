#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}Node;

Node *CreateNewNode(){
    Node *newNode = NULL;
    newNode = (Node*) malloc(sizeof(Node));
    printf("Masukkan Nilai: ");
    scanf("%d", &(newNode->data));
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *InsertNode(Node *node){
    Node *newNode = CreateNewNode();
    if(node == NULL){
        node = newNode;
    }else{
        Node *tmp = node;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->prev = tmp;
    }
    return node;
}

void show(Node *node){
    if(node == NULL){
        printf("[Kosong]");
    }else{
        while(node->next != NULL){
            printf("[%d] ", node->data);
            node = node->next;
        }
        printf("[%d] ", node->data);
    }
}

void showDesc(Node *node){
    if(node == NULL){
        printf("[Kosong]");
    }else{
        while(node->next != NULL){
            node = node->next;
        }
        while(node->prev != NULL){
            printf("[%d] ", node->data);
            node = node->prev;
        }
        printf("[%d] ", node->data);
    }
}

Node *InsertBefore(Node *node){
    int findValue;
    printf("Masukkan nilai sebelum: ");
    scanf("%d", &findValue);
    if(node == NULL){
        printf("Nilai tidak ditemukan.\n");
        system("pause");
    }else{
        Node *tmp = node;
        while(tmp->data != findValue && tmp->next != NULL){
            tmp = tmp->next;
        }
        if(tmp->data == findValue){
            Node *newNode = CreateNewNode();
            if(tmp->prev == NULL){
                tmp->prev = newNode;
                newNode->next = tmp;
                node = newNode;
            }else{
                newNode->prev = tmp->prev;
                newNode->next = tmp;
                tmp->prev->next = newNode;
                tmp->prev = newNode;
            }
        }else{
            printf("Nilai tidak ditemukan.\n");
            system("pause");
        }
    }
    return node;
}

Node *DeleteBefore(Node *node){
    int findValue;
    printf("Hapus nilai sebelum : ");
    scanf("%d", &findValue);
    if(node == NULL){
        printf("Nilai tidak ditemukan.\n");
        system("pause");
    }else{
        Node *tmp = node;
        while(tmp->data != findValue && tmp->next != NULL){
            tmp = tmp->next;
        }
        if(tmp->data == findValue){
            if(tmp->prev == node){
                Node *temp = node;
                node = temp->next;
                free(temp);
            }else if(tmp == node){
                printf("Tidak bisa menghapus nilai NULL.\n");
                system("pause");
            }else{
                tmp->prev->prev->next = tmp;
                tmp->prev = tmp->prev->prev;
            }
        }else{
            printf("Nilai tidak ditemukan.\n");
            system("pause");
        }
    }
    return node;
}

int main()
{
    Node *head = NULL;
    int pilihan;
    do{
        system("cls");
        (pilihan != 2) ? show(head) : showDesc(head);
        printf("\nMenu: \n");
        printf("1. Insert Node\n");
        printf("2. Show Descending\n");
        printf("3. Insert Before\n");
        printf("4. Delete Before\n");
        printf("0. Exit\n");
        printf("Masukkan Pilihan : ");
        scanf("%d", &pilihan);
        if(pilihan == 1){
            head = InsertNode(head);
        }
        else if(pilihan == 2){
            continue;
        }
        else if(pilihan == 3){
            head = InsertBefore(head);
        }
        else if(pilihan == 4){
            head = DeleteBefore(head);
        }
        else if(pilihan == 0){
            exit(0);
        }
    }while(1);

    return 0;
}
