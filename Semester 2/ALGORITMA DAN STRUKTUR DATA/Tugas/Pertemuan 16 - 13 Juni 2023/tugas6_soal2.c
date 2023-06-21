#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct Node{
    struct Node *prev;
    char data[MAX];
    struct Node *next;
}Node;

Node *createNode(){
    Node *newNode = malloc(sizeof(Node));
    printf("Masukkan nama ke antrian : ");
    scanf("\n%[^\n]s", newNode->data);
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

Node *deleteNode(Node *node, char nama[MAX]){
    if(node == NULL){
        printf("Antrian masih kosong.\n");
        system("pause");
    }else{
        Node *temp = node;
        while(strcmp(temp->data, nama) != 0 && temp->next != NULL){
            temp = temp->next;
        }
        if(strcmp(temp->data, nama) == 0){
            if(temp->prev == NULL && temp->next == NULL){
                free(temp);
                node = NULL;
            }else if(temp == node){
                node = temp->next;
                node->prev = NULL;
                free(temp);
            }else if(temp->next == NULL){
                temp->prev->next = NULL;
                free(temp);
            }else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
        }else{
            printf("Nama tidak ditemukan dalam antrian.\n");
            system("pause");
        }
    }
    return node;
}

void show(Node *node){
    if(node == NULL){
        printf("[Kosong]\n");
    }else{
        int i = 1;
        while(node->next != NULL){
            printf("[%d] Nama: %s\n", i++, node->data);
            node = node->next;
        }
        printf("[%d] Nama: %s\n", i++, node->data);
    }
}

void checkNode(Node *node, char nama[MAX]){
    if(node == NULL){
        printf("Antrian masih kosong.\n");
        system("pause");
    }else{
        Node *temp = node;
        int i = 0;
        while(strcmp(temp->data, nama) != 0 && temp->next != NULL){
            temp = temp->next;
            i++;
        }
        if(strcmp(temp->data, nama) == 0){
            if(i == 0){
                printf("Saudara/i %s silahkan masuk.\n", nama);
                system("pause");
                return;
            }
            printf("Antrian atas nama %s kurang %d antrian lagi.\n", nama, i);
            system("pause");
        }else{
            printf("Nama tidak ditemukan dalam antrian.\n");
            system("pause");
        }
    }
}

void main(){
    Node *head = NULL;
    int pilihan;
    char nama[MAX];
    do{
        system("cls");
        printf("------------ ANTRIAN RUMAH SAKIT ------------\n");
        printf("Daftar Pasien dalam Antrian:\n");
        show(head);
        printf("\n1. Tambah Antrian");
        printf("\n2. Hapus Antrian");
        printf("\n3. Cek Antrian");
        printf("\n5. Exit");
        printf("\nPilihan: ");
        scanf("%d", &pilihan);
        if(pilihan == 1){
            head = insertNode(head);
        }else if(pilihan == 2){
            printf("Masukkan nama yang ingin di hapus: ");
            scanf("\n%[^\n]s", nama);
            head = deleteNode(head, nama);
        }else if(pilihan == 3){
            printf("Masukkan nama yang ingin di cari: ");
            scanf("\n%[^\n]s", nama);
            checkNode(head, nama);
        }else if(pilihan == 5){
            printf("\n\nProgram Berakhir.\n");
            exit(0);
        }
    }while(1);
}