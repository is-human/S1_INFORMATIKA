#include <stdio.h>
#include <string.h>
 
struct Buah{
   int berat;
   char namaBuah[10];
};

void cetak (struct Buah *b){
    printf("\nOutput: \n");
    printf("Berat buah : %dkg\n", b->berat);
    printf("Nama buah  : %s\n", b->namaBuah);
}

int main(){
  
    struct Buah buah;   
 
    printf("Input: \n");
    printf("Masukkan Berat buah : ");
    scanf("%d", &buah.berat);
    printf("Masukkan Nama buah  : ");
    fflush(stdin); gets(buah.namaBuah);
 
    cetak (&buah);
    return 0;
}

