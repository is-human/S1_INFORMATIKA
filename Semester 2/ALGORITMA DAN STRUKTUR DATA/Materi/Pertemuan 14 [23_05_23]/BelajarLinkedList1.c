#include <stdio.h>
#include <stdlib.h>

//Deklarasi pointer dengan tipe data struct node
typedef struct node *address;

// Isi dari struct
struct node{
	int data;
	address next;
};

//fungsi membuat node baru
address createNode(int nilai){
    address p;
    //alokasi memori sebesar node itu sendiri (memboking tempat/memori)
    p = (address) malloc(sizeof(struct node));
	p->data = nilai;
    p->next = NULL;
    return (p);
}

//fungsi menambahkan node baru di depan list
address insertFirst(address head, int nilai){
	address new_node = createNode(nilai);
	new_node->next = head;
	head = new_node;
	return head;
}

//fungsi menambahkan node baru di akhir list
address insertLast(address head, int nilai){
	//iterasi mencari node terakhir
	address tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}
	//buat node baru
	address new_node = createNode(nilai);
	tail->next = new_node;
	return head;
}

//funsgi menyelipkan node baru sesudah node pilihan
address insertAfter(address head, int nilai, int prev_nilai){
	//mencari node sebelumnya, mulai dari simpul pertama
	address cursor = head;
	while(cursor->data != prev_nilai){
		if(cursor->next == NULL){
			printf("Gaada coy");
			return head;
		}
		cursor = cursor->next;
	}
	address new_node = createNode(nilai);
	new_node->next = cursor->next;
	cursor->next = new_node;
	return head;
}

//fungsi menyelipkan node baru sesudah node pilihan
address insertBefore(address head, int nilai, int next_nilai){
	if(head->data == next_nilai){
		head = insertFirst(head, nilai);
	}else{
		address cursor, prev_cursor;
		cursor = head;
		do{
			prev_cursor = cursor;
			cursor = cursor->next;
			// if(cursor->next == NULL) keluar
		}while(cursor->data != next_nilai);

		address new_node = createNode(nilai);
		new_node->next = cursor;
		prev_cursor->next = new_node;
	} return head;
}

//fungsi menghapus node di awal list
address deleteFirst(address head){
	if(head == NULL){
		return;
	}
	address first = head;
	head = head->next;
	//memutus hubungan dengan node setelahnya
	first->next = NULL;
	//membebasakan memori yang dipakai node terdepan
	free(first);
	return head;
}

//fungsi menghapus node di akhir list
address deleteLast(address head){
	if(head == NULL){
		return;
	}
	address tail = head;
	address prev_tail = NULL;
	while(tail->next != NULL){
		prev_tail = tail;
		tail = tail->next;
	}
	//memutus hubungan dengan node paling akhir
	prev_tail->next = NULL;
	//membebaskan memori yang dipakai node terakhir
	free(tail);
	return head;
}

//fungsi menghapus node setelah node terpilih
address deleteAfter(address head, int nilai){
	address cursor = head;
	while(cursor != NULL){
		if(cursor->data == nilai){
			break; //keluar dari iterasi
		} cursor = cursor->next;
	}
	if(cursor != NULL){
		address temp = cursor->next;
		cursor->next = temp->next;
		temp->next = NULL;
		free(temp);
	}
	return head;
}

//fungsi menampilkan data node dari linked list
void tampilnilai(address head){
    address n = head;
    printf("Daftar nilai linked list : \n");

    while (n != NULL){
        printf("[%d] ", n->data);
        n = n->next;
    };
    printf("\n");
}

//fungsi menghitung jumlah node
address count(address head){
    int count = 0;
    struct node *p;
    p = head;
    while (p != NULL){
        p = p->next;
        count++;
    }
    printf("Jumlah node adalah : %d\n", count);
    return(head);

}

//fungsi membersihkan/mengkosongkan linked list
address dispose(address head){
    if(head == NULL){
        return;
    }
    while(head != NULL){
        address tmp = head;
        head = head->next;
        tmp->next = NULL;
        free(tmp);
    }
    printf("Semua node (simpul) telah dihapus\n");
    return head; //linked list baru
}

int main()
{
    int pilih, val, val1;
    address head = NULL;
    while(1){
    system("cls");
    tampilnilai(head);
    printf("\n======================== SINGLE LINKED LIST ========================\n");
    printf("1. Insert First\n");
    printf("2. Insert Last\n");
    printf("3. Insert After\n");
    printf("4. Insert Before\n");
    printf("5. Delete First\n");
    printf("6. Delete Last\n");
    printf("7. Delete After\n");
    printf("8. Hitung Jumlah Node\n");
    printf("9. Hapus Keseluruhan Node\n");
    printf("10. Keluar\n");
    printf("Pilihan Anda = ");
    scanf("%d", &pilih);
    switch (pilih){
    case 1:
        {
            printf("Masukkan nilai = ");
            scanf("%d", &val);
            head = insertFirst(head, val);
            system("cls");
            break;
        }
    case 2 :
        {
            printf("Masukkan nilai = ");
            scanf("%d", &val);
            head = insertLast(head, val);
            system("cls");
            break;
        }
    case 3 :
        {
            printf("Masukkan nilai = ");
            scanf("%d", &val);
            printf("Masukkan nilai tersebut setelah = ");
            scanf("%d", &val1);
            head = insertAfter(head, val, val1);
            system("cls");
            break;
        }
    case 4 :
        {
            printf("Masukkan nilai = ");
            scanf("%d", &val);
            printf("Masukkan nilai tersebut sebelum = ");
            scanf("%d", &val1);
            head = insertBefore(head, val, val1);
            system("cls");
            break;
        }
    case 5 :
        {
            head = deleteFirst(head);
            system ("cls");
            break;
        }
    case 6 :
        {
            head = deleteLast(head);
            system ("cls");
            break;
        }
    case 7 :
        {
            printf("Masukkan nilai yang ingin dihapus = ");
            scanf("%d", &val);
            head = deleteAfter(head, val);
            system ("cls");
            break;
        }
    case 8 :
        {
            head = count(head);
            system ("Pause");
            break;
        }
    case 9 :
        {
            head = dispose(head);
            system ("Pause");
            break;
        }
    case 10 :
        {
            exit(1);
        }
    default :
        {
            printf("Pilihan tersebut tidak ada");
            break;
        }
    }
    }
    return 0;
}