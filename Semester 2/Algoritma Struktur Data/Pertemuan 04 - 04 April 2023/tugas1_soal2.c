//memangggil header file stdio.h untuk akses fungsi standar input dan output
#include <stdio.h>

//fungsi utama yang akan pertama-kali dieksekusi program
int main(){
    //deklarasi dan inisialaisai array juga variabel temp
    int x[5] = {15, 21, 4, 6, 2}, temp;
    //menampilkan tulisan "Array awal : "
    printf("Array awal : \n");
    //perulangan untuk menyeser seluruh isi array
    for(int i = 0; i < 5; i++){
        //menampilkan nilai array pada indeks i
        printf("%d, ", x[i]);
    }
    //perulangan untuk menyeser seluruh isi array
    for(int a = 0; a < 4; a++){
        //perulangan lagi untuk menyeser array yang mana akan semakin kecil seseran setiap iterasinya
        for(int b = 0; b < 4 - a; b++){
            //menjalankan blok kode jika nilai array di-indeks pada iterasi ini lebih besar dari indeks setelahnya
            if(x[b] > x[b+1]){
                //pertukaran nilai yang dibantu variabel temp. temp disisipkan dengan nilai array di indeks b
                temp = x[b];
                //array indeks b disisipkan nilai array pada indeks setelahnya
                x[b] = x[b+1];
                //array pada indeks setelahnaya disisipi nilai yang disimpan di variabel temp
                x[b+1] = temp;
            }
        }
    }
    //menampilkan tulisan "Array yang telah di ubah"
    printf("\nArray yang telah di ubah : \n");
    //perulangan untuk menyeser seluruh isi array
    for(int i = 0; i < 5; i++){
        //menampilkan isi array yang sudah diubah urutannya
        printf("%d, ", x[i]);
    }
}


