// memanggil header file "stdio.h" untuk mengakses fungsi input dan output
#include <stdio.h>
// fungsi untuk mendapatkan nilai terbesar dalam suatu array 1 dimensi.
// menerima argumen yaitu: alamat indeks pertama array, panjang array
int nilaiTerbesar(int *arr, int len){
    // BASE: memeriksa jika indeks yang akan diperiksa adalah 0, maka keluar.
    if(len-1 == 0) return arr[0];
    // RECUREN: memeriksa jika nilai array pada indeks len-1 lebih besar..
    // .. dari nilai pada indeks len-2 dan apakah len-2 lebih besar atau..
    // .. sama dengan 0.
    if(len-2 >= 0 && arr[len-1] > arr[len-2]){
        // menukar nilai dari array pada indeks len-1 dengan len-2
        int temp = arr[len-1];
        arr[len-1] = arr[len-2];
        arr[len-2] = temp;
    }
    // lakukan pemanggilan fungsi "nilaiTerbsar" dengan argumen: ..
    // .. alamat indeks pertama array dan len yang dikurangi 1.
    nilaiTerbesar(arr, len-1);
}
// fungsi utama yang akan pertama kali dijalankan saat kode dieksekusi
void main(){
    // menyiapkan variabel untuk menyimpan panjang array
    int len;
    // menerima inputan angka dari user untuk panjang array
    printf("Buat array 1 dimensi sepanjang: ");
    scanf("%d", &len);
    // menyiapkan variabel array dengan panjang yang sudah didapat(len)
    int arr[len];
    // melakukan perulangan sebanyak len(panjang yang sudah didapat)
    for(int i = 0; i < len; i++){
        // menerima inputan angka untuk disimpan di array pada indeks ke-i
        printf("Masukkan nilai array untuk indeks %d: ", i);
        scanf("%d", &arr[i]);
    }
    // menampilkan nilai kembalian (hasil) dari pemanggilan fungsi "nilaiTerbesar"..
    // ..  yang mengoper argumen: alamat pertama array, panjang array.
    printf("Nilai terbesar: %d", nilaiTerbesar(arr, len));
}