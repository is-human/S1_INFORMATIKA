#include <stdio.h>
#include <string.h>
 
struct Buku {
   char pengarang[50];
   char judul[30];
   int tahun;
};

typedef struct Buku buku;
 
//membuat fungsi dengan struct sebagai parameter
void tampil(buku b){
    printf("\n\nData yang telah dimasukkan adalah pengarang buku %s, judul buku %s, tahun %i \n", b.pengarang, b.judul, b.tahun);

}

int main( ) {
    
    buku buku;
    printf("Isi Buku Ini    : \n");
    printf("Masukkan nama pengarang : ");
    fflush(stdin);gets(buku.pengarang);
    printf("Masukkan judul          : ");
    fflush(stdin);gets(buku.judul);
    printf("Masukkan tahun : ");
    scanf("%i",&buku.tahun);
    tampil(buku);

   return 0;
}
