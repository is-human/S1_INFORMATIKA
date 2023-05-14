//memangggil header file stdio.h untuk akses fungsi standar input dan output
#include <stdio.h>

//fungsi utama yang akan pertama kali dieksekusi program
int main(){
    //deklarasi array dan variabel total
    int arr[70], total = 0;
    //menampilkan tulisan "array : "
    printf("array : ");
    //perulangan untuk menyeser isi array
    for(int i = 0; i < 70; i++){
        //mengisi arr[i] dengan i tambah 1
        arr[i] = i + 1;
        //menambahkan nilai di atas ke variabel total
        total += arr[i];
        //menampilkan nilai tesebut
        printf("%d, ", arr[i]);
    }
    //menampilkan nilai rata-rata dari seluruh elemen array
    printf("\nrata-rata dari array tersebut adalah : %.2f", (float) total/70);
}

