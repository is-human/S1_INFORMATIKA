//memanggil header file stdio.h untuk akses fungsi standar input dan output
#include <stdio.h>
//membuat struct bernama alias pecahan dengan properti pembilang dan penyebut
typedef struct Pecahan{
    int pembilang;
    int penyebut;
} pecahan;
//fungsi utama yang pertama kali akan dieksekusi program
int main(){
    //deklarasi array bil sepanjang 3 dengan tipe struktur pecahan
    pecahan bil[3];
    //melakukan perulangan sebnayak 3 kali
    for(int i = 0; i < 3; i++){
        //menerima pembilang dan penyebut
        printf("(pembilang, penyebut) : ");
        scanf(" %d %d", &bil[i].pembilang, &bil[i].penyebut);
        //jika pembilang lebih kecil dari penyebut..
        if(bil[i].pembilang < bil[i].penyebut){
            //..maka penyebut = penyebut dibagi pembilangan
            bil[i].penyebut = bil[i].penyebut / bil[i].pembilang;
            //pembilang tersisa 1
            bil[i].pembilang = 1;
        }else{ //jika selain kondisi di atas (pembilang lebih besar dari penyebut)..
            //..maka pembilang = pembilang dibagi penyebut
            bil[i].pembilang = bil[i].pembilang / bil[i].penyebut;
            //penyebut tersisa 1
            bil[i].penyebut = 1;
        }
    }
    //melakukan perulangan sebanyak 3 kali
    for (int i = 0; i < 3; i++){
        //menampilkan hasil penyederhaaan pecahan
        printf("%d/%d\n", bil[i].pembilang, bil[i].penyebut);
    }
    return 0;
}

