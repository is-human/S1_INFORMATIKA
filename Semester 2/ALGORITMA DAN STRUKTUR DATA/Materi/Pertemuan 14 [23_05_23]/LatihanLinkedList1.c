#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

//Deklarasi pointer dengan tipe data struct node
typedef struct node *address;

typedef struct Kontak{
    char nama[MAX];
    char nomor[MAX];
}kontak;


// Isi dari struct
struct node{
	kontak data;
	address next;
};

//fungsi membuat node baru
address createNode(char nama[], char nomor[]){
    address p;
    //alokasi memori sebesar node itu sendiri (memboking tempat/memori)
    p = (address) malloc(sizeof(struct node));
	strcpy(p->data.nama, nama);
	strcpy(p->data.nomor, nomor);
    p->next = NULL;
    return p;
}

//fungsi menambahkan node baru di akhir list
address insertLast(address head, char nama[], char nomor[]){
	//iterasi mencari node terakhir
	address tail = head;
    if(tail != NULL){
        while(tail->next != NULL){
            tail = tail->next;
        }
    }
	//buat node baru
	address new_node = createNode(nama, nomor);
    if(tail != NULL) tail->next = new_node;
    else head = new_node;
    printf("\nData berhasil ditambahkan.\n\n");
    system("pause");
	return head;
}

//funsgi mencari node sesuai nama
void searchByName(address head, char nama[]){
	//mencari node sebelumnya, mulai dari simpul pertama
    if(head == NULL){
        printf("Belum ada data kontak.\n\n");
        system("pause");
        return;
    }
	address cursor = head;
	while(strcmp(cursor->data.nama, nama) != 0){
		if(cursor->next == NULL){
			printf("Kontak %s tidak ditemukan.\n\n", nama);
            system("pause");
			return;
		}
		cursor = cursor->next;
	}
	printf("\nData ditemukan!\n\n");
	printf("> Nama : %s\n", cursor->data.nama);
	printf("> Nomor: %s\n\n", cursor->data.nomor);
    system("pause");
}

//fungsi menampilkan data node dari linked list
void showList(address head){
    address n = head;
    printf("Daftar Kontak: \n");
    if(n == NULL){
        printf(" - kosong - \n\n");
        system("pause");
        return;
    }
    while(n != NULL){
        printf("\n");
        printf("> Nama : %s\n", n->data.nama);
        printf("> Nomor: %s\n", n->data.nomor);
        n = n->next;
    };
    printf("\n");
    system("pause");
}

int main()
{
    int pilih;
    char nama[MAX], nomor[MAX];
    address head = NULL;
    while(1){
        system("cls");
        printf("\nMenu:\n");
        printf("1. Tambah Kontak\n");
        printf("2. Cari Kontak\n");
        printf("3. Cetak Daftar Kontak\n");
        printf("4. Keluar\n");
        printf("Pilihan Menu: ");
        scanf("%d", &pilih);
        switch (pilih){
            case 1:
                    printf("Masukkan Nama: ");
                    scanf("%s", &nama);
                    printf("Masukkan Kontak: ");
                    scanf("%s", &nomor);
                    head = insertLast(head, nama, nomor);
                    break;
            case 2:
                    printf("Cari kontak atas nama: ");
                    scanf("%s", &nama);
                    searchByName(head, nama);
                    break;
            case 3:
                    showList(head);
                    break;
            case 4:
                    exit(1);
            default :
                    printf("Pilihan tidak tersedia!");
                    system("pause");
                    break;
        }
    }
    return 0;
}