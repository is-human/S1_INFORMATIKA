#include <stdio.h>
#include <string.h>

struct Buku {
    char pengarang[50];
    char judul[30];
    int tahun;
};

int main(){
    struct Buku buku[3];
    for(int i = 0; i < 3; i++){
        printf("Pengisisan Buku ke-%i\n", i+1);
        printf("Masukkan nama pengarang : ");
        fflush(stdin); gets(buku[i].pengarang);        
        printf("Masukkan nama judul : ");
        fflush(stdin); gets(buku[i].judul);
        printf("Masukkan nama tahun : ");
        scanf(" %d", &buku[i].tahun);
        getchar();
    }

    for(int i = 0; i < 3; i++){
        printf("| %s | %s | %i |\n", buku[i].pengarang, buku[i].judul, buku[i].tahun);
    }

    return 0;

}
