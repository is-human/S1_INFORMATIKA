//memangggil header file stdio.h untuk akses fungsi standar input dan output
#include <stdio.h>

//deklarasi dan inisialisasi array global juga variabel kunci
int arr[3][2] = {{3, 6}, {9, 8}, {15, 10}}, kunci;

//prosedur bernama cari untuk mencari nilai di array sesuai kunci
void cari(){
    //perulangan untuk menyeser dimensi 1 array
    for(int a = 0; a < 3; a++){
        //perulangan untuk menyeser dimensi 2 array
        for(int b = 0; b < 2; b++){
            //menajalankan blok kode di dalamnya jika kunci sama dengan nilai array pada indeks[a][b]
            if(kunci == arr[a][b]) {
                //menempilkan hasil yang diinginkan
                printf("Elemen %d berada di indeks[%d][%d]", kunci, a, b);
                //kembali ke fungsi main tanpa membawa apa-apa
                return; 
            }
        }
    }
    //menampilkan pesan bila nilai tidak ditemukan pada array
    printf("Tidak ada elemen tersebut di dalam array.");
}

//fungsi utama yang akan pertama-kali dieksekusi program
int main(){
    //menampilkan tulisan "array : "
    printf("array : ");
    //perulangan untuk menyeser dimensi 1 array
    for(int a = 0; a < 3; a++){
        //perulangan untuk menyeser dimensi 2 array
        for(int b = 0; b < 2; b++){
            //menampilkan isi array
            printf("%d, ", arr[a][b]);
        }
    }
    //menampilkan permintaan input
    printf("\nmasukkan elemen yang ingin dicari indeksnya : ");
    //menerima inputan berupa integer yang akan disimpan sebagai kunci
    scanf(" %d", &kunci);
    //memanggil fungsi cari untuk melakukan pencarian
    cari();
}

