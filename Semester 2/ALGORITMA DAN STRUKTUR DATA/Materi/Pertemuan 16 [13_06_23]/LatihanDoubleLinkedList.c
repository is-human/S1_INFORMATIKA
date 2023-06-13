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
    printf("Masukkan nilai node baru : ");
    scanf("%d", &(newNode->data));
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *insertFirst(Node *node){
    Node *newNode = createNode();
    if(node == NULL){
        node = newNode;
    }else{
        Node *tmp = node;
        tmp->prev = newNode;
        newNode->next = tmp;
        node = newNode;
    }
    return node;
}

Node *insertLast(Node *node){
    Node *newNode = createNode();
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

Node *insertBefore(Node *node){
    int findValue;
    printf("Masukkan nilai sebelum : ");
    scanf("%d", &findValue);
    if(node == NULL){
        printf("List masih kosong.\n");
        system("pause");
    }else{
        Node *tmp = node;
        while(tmp->data != findValue && tmp->next != NULL){
            tmp = tmp->next;
        }
        if(tmp->data == findValue){
            Node *newNode = createNode();
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

Node *insertAfter(Node *node){
    int findValue;
    printf("Masukkan nilai setelah : ");
    scanf("%d", &findValue);
    if(node == NULL){
        printf("List masih kosong.\n");
        system("pause");
    }else{
        Node *tmp = node;
        while(tmp->data != findValue && tmp->next != NULL){
            tmp = tmp->next;
        }
        if(tmp->data == findValue){
            Node *newNode = createNode();
            if(tmp->next == NULL){
                tmp->next = newNode;
                newNode->prev = tmp;
            }else{
                newNode->prev = tmp;
                newNode->next = tmp->next;
                tmp->next = newNode;
                tmp->next->prev = newNode;
            }
        }else{
            printf("Nilai tidak ditemukan.\n");
            system("pause");
        }
    }
    return node;
}

void show(Node *node){
    if(node == NULL){
        printf("[Kosong]");
    }else{
        printf("ASC  : ");
        while(node->next != NULL){
            printf("[%d] ", node->data);
            node = node->next;
        }
        printf("[%d] ", node->data);
    }
}

void showDesc(Node *node){
    if(node != NULL){
        printf("\nDESC : ");
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

Node *deleteFirst(Node *node){
    if(node == NULL){
        printf("Nilai tidak ditemukan.\n");
        system("pause");
    }else if(node->prev == NULL && node->next == NULL){
        free(node);
        node = NULL;
    }else{
        Node *tmp = node;
        node = tmp->next;
        node->prev = NULL;
        free(tmp);
    }
    return node;
}

Node *deleteLast(Node *node){
    if(node == NULL){
        printf("Nilai tidak ditemukan.\n");
        system("pause");
    }else if(node->prev == NULL && node->next == NULL){
        free(node);
        node = NULL;
    }else{
        Node *tmp = node;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->prev->next = NULL;
        free(tmp);
    }
    return node;
}

Node *deleteBefore(Node *node){
    int findValue;
    printf("Hapus nilai sebelum : ");
    scanf("%d", &findValue);
    if(node == NULL){
        printf("List masih kosong.\n");
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

Node *deleteAfter(Node *node){
    int findValue;
    printf("Hapus nilai setelah : ");
    scanf("%d", &findValue);
    if(node == NULL){
        printf("List masih kosong.\n");
        system("pause");
    }else{
        Node *tmp = node;
        while(tmp->data != findValue && tmp->next != NULL){
            tmp = tmp->next;
        }
        if(tmp->data == findValue){
            if(tmp->next == NULL){
                printf("Tidak bisa menghapus nilai NULL.\n");
                system("pause");
            }else if(tmp->next->next == NULL){
                free(tmp->next);
                tmp->next = NULL;
            }else{
                tmp->next->next->prev = tmp;
                tmp->next = tmp->next->next;
            }
        }else{
            printf("Nilai tidak ditemukan.\n");
            system("pause");
        }
    }
    return node;
}

void searchNode(Node *node){
    int cari, i = 1, found = 0;
    printf("Nilai yang dicari : ");
    scanf("%d", &cari);
    Node *temp = node;
    while(temp != NULL){
        if(temp->data == cari){
            printf("\nNilai ditemukan di urutan ke-%d", i);
            found++;
        }
        i++;
        temp = temp->next;
    }
    if(found == 0){
        printf("\nNilai tidak tersedia dalam list.");
    }
    printf("\n");
    system("pause");
}

int main(){
    Node *head = NULL;
    int pilihan;
    while(1){
        system("cls");
        show(head);
        (pilihan == 9) ? showDesc(head) : printf("");
        printf("\n-------- MENU --------\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert Before\n");
        printf("4. Insert After\n");
        printf("5. Delete First\n");
        printf("6. Delete Last\n");
        printf("7. Delete Before\n");
        printf("8. Delete After\n");
        printf("9. Show Descending\n");
        printf("10. Cari Data\n");
        printf("11. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        if(pilihan == 1){
            head = insertFirst(head);
        }
        else if(pilihan == 2){
            head = insertLast(head);
        }
        else if(pilihan == 3){
            head = insertBefore(head);
        }
        else if(pilihan == 4){
            head = insertAfter(head);
        }
        else if(pilihan == 5){
            head = deleteFirst(head);
        }
        else if(pilihan == 6){
            head = deleteLast(head);
        }
        else if(pilihan == 7){
            head = deleteBefore(head);
        }
        else if(pilihan == 8){
            head = deleteAfter(head);
        }
        else if(pilihan == 9){
            continue;
        }
        else if(pilihan == 10){
            searchNode(head);
        }
        else if(pilihan == 11){
            printf("\nKeluar dari program.");
            exit(0);
        }
    }
    return 0;
}