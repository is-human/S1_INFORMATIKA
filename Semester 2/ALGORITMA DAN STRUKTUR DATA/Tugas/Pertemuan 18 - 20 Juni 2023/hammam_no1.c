#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    char data;
    struct Node* next;
};

// parameter head cukup single pointer
// fungsi ini menerapkan prinsip "insert first"
struct Node *addnode(struct Node* head, char value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head == NULL){
        //jika linked list masih kosong, maka jadikan newNode sebagai head dan menyabung ke (next to) diri sendiri (head)
        newNode->next = newNode;
        head = newNode;
    }else{
        //mendapatkan alamat tail
        struct Node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        //alamat tail didapatkan, tersimpan dalam variabel tail

        // Single Linked List Circular. Tail nyambung ke head, seperti berikut
        //newNode menjadi node paling depan karena nyambung ke head(next to head)
        newNode->next = head;
        //tail nyambung ke newNode yang baru saja diposisikan di depan
        tail->next = newNode;
        //sekarang newNode yang menjadi head dalam linked list ini
        head = newNode;
    }
    //kembalikan alamat head ke pemanggil
    return head;
}

int hitung(struct Node* head) {
    int count = 1;
    struct Node* current = head;

    //looping sampe ke node terakhir
    while (current->next != head) {
        if (current->data == 'B') {
            return count; 
        }

        count++;
        current = current->next;
    }

    return count;
}

void deleteLinkedList(struct Node* head) 
{
    struct Node* tail = head;
    //mendapatkan alamat tail
    while (tail->next != head)
    {
        tail = tail->next;
    }
    //manghapus dari depan(head) sampai ke node akhir(tail)
    while(head != tail){
        head = head->next;
        free(tail->next);
        tail->next = head;
    }
    //menghapus node terakhir yang merupakan tail sekaligus head
    free(head);
}

int main() {
    struct Node* head = NULL;
    char input;

    printf("Input : ");
    while ((input = getchar()) != '\n') 
    {
        if (input == 'T' || input == 'B') 
        {   
            // menyimpan alamat head baru yang dikembalikan fungsi "addnode"
            head = addnode(head, input);
        }
    }

    int memakanEkor = hitung(head);

    printf("Ular mati ketika memakan ekornya sebanyak %d kali.\n", memakanEkor);

    deleteLinkedList(head);

    return 0;
}