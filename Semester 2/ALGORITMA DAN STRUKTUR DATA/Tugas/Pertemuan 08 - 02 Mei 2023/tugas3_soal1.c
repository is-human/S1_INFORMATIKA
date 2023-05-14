//memanggil header file stdio.h untuk akses fungsi standar input dan output
#include <stdio.h>
//membuat struct bernama barang dengan member nama, modal, dan jual
struct barang{
    char nama[20];
    int modal, jual;
};
//fungsi utama yang pertama kali akan dieksekusi program
int main(){
    //deklarasi variabl item dengan tipe struktur barang
    struct barang item;
    //menerima inputan Nama berupa string
    printf("Nama : ");
    fflush(stdin);gets(item.nama);
    //menerima inputan nilai Modal berupa angka desimal
    printf("Modal : ");
    scanf("%d", &item.modal);
    //menerima inputan nilai Modal berupa angka desimal
    printf("Jual : ");
    scanf("%d", &item.jual);
    //menampilkan hasil hitung keuntungan
    printf("Margin adalah : %d", item.jual - item.modal);
    return 0;
}

