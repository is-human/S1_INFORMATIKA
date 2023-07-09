// memanggil header file "stdio.h" untuk menggakses input dan output
#include <stdio.h>
// fungsi untuk menghitung digit bilangan bulat yang memnerima argumen:..
// nilai, panjang.
int hitungDigitINT(int val, int len){
    // RECUREN: memeriksa jika val (bilangan bulat) tidak sama dengan 0, ..
    if(val != 0){
        // ..maka kembalikan pemanggilan fungsi "hitungDigitINT" yang mengoper..
        // ..val yang dibagi 10, len yang ditambah 1.
        return hitungDigitINT(val/10, len+1);
    }
    // BASE: jika val (bilangan bulat) sama dengan 0, maka kembalikan..
    // ..len (panjang digit yang telah dihitung).
    return len;
}
// fungsi utama yang akan dijalankan pertama kali saat program dijalankan
void main(){
    // menyiapkan variabel untuk menyimpan bilangan bulat
    int val;
    // menerima inputan user berupa bilangan bulat dan disimpan dalam val
    printf("Masukkan bilangan bulat: ");
    scanf("%d", &val);
    // menampilkan nilai kembalian (hasil) dari pemanggilan fungsi "hitungDigitINT"..
    // ..yang mengoperkan argumen yaitu: nilai(bil bulat), angka nol(awal menghitung).
    printf("Jumlah digit: %d", hitungDigitINT(val, 0));
}