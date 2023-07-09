// memanggil header file "stdio.h" untuk mengakses fungsi input dan output
#include <stdio.h>
// fungsi untuk memeriksa pelindrom yang menerima argumen yaitu: string, tail_index, head_index
void cekPelindrom(char *str, int tail, int head){
    // BASE: memeriksa jka nilai head sama atau lebih besar dari tail, maka..
    if(head >= tail-1){
        // .. string merupakan pelindrom.
        printf("> \"%s\" merupakan Pelindrom.", str);
        // keluar fungsi
        return;
    }
    // RECUREN: memeriksa jika karakter string pada indeks head dan tail sama, maka..
    if(str[head] == str[tail-1]){
        // .. lakukan pemanggilan fungsi "cekPelindrom" dengan parameter yaitu:
        // alamat awal string, tail_index - 1, head_index - 1
        cekPelindrom(str, tail-1, head+1);
    }
    // BASE: jika kondisi di atas tidak terpenuhi, maka..
    else{
        // .. string tidak termasuk pelindrom.
        printf("> \"%s\" tidak termasuk Pelindrom.", str);
        // keluar fungsi
        return;
    }
}
// fungsi utama yang akan pertamakali dijalankan saat kode dieksukusi
void main(){
    // menyiapkan variabel untuk menyimpan string dan panjang string
    char *str;
    int len;
    // menerima masukkan string dari user
    printf("Periksa Pelindrom: ");
    scanf("%s", str);
    // menghitung panjang string
    for(len = 0; str[len] != '\0'; len++); 
    // memeriksa perlindrom atau tidaknya string yang dimasukkan user
    cekPelindrom(str, len, 0);
}