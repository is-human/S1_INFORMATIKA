// memanggil header file "stdio.h" untuk mengakses fungsi input dan output
#include <stdio.h>
// memanggil juga "string.h" untuk mendapat akses ke fungsi manipulasi string
#include <string.h>
// panggil pula "math.h" untuk mendapat akses ke fungsi matematika khususnya pow()
#include <math.h>
// fungsi untuk mendapatkan subsekuen dari sebuah string yang menerima argumen..
// ..yaitu: alamat pertama array str, indeks yang akan terus bertambah seiring..
// ..berjalnnya rekursi, subsekuen.
void subsekuen(char *str, int indeks, char *sub){
    // BASE: memeriksa jika indeks sudah mencapai panjang str, ...
    if (indeks == strlen(str)){
        // ..tampilakan subekuan yang didapatkan.
        printf("[%s] ", sub);
        return;
    }
    // RECUREN: jika kondisi diatas belum terpenuhi, maka..
    // ..siapkan variabel alternatif untuk menyimpan subsekuen.
    char altSub[strlen(sub) + strlen(str)];
    // lalu, simpan juga (copy) nilai variabel sub ke altSub.
    strcpy(altSub, sub);
    // simpan nilai str pada indeks saat ini di indeks terakhir sub/altSub
    altSub[strlen(sub)] = str[indeks];
    // tambahkan '\0' sebagai penutup sebuah array karakter (string)
    altSub[strlen(sub) + 1] = '\0';
    // lakukan pemanggilan fungsi "subsekuen" dengan parameter yaitu: ..
    // ..alamat pertama str, indeks saat ini yang ditambah 1, altSub
    subsekuen(str, indeks + 1, altSub);
    // Juga pemanggilan fungsi yang sama dengan parameter yaitu: ..
    // ..alamat pertama str, indeks saat ini yang ditambah 1, sub
    subsekuen(str, indeks + 1, sub);
    // subsekuen akan terus/kembali dipanggil dengan indeks yang terus bertambah..
    // ..hingga mencapai panjang str dan akan menjadi seperti bercabang karena..
    // ..ada alternatif sub baru tiap rekursi(putaran)nya.
}
// fungsi utama yang akan pertama kali akan jalankan saat kode dieksukusi
void main(){
    // menyiapkan variabel untuk menyimpan string, nilai sementara, panjang string
    char *inStr;
    char temp[1] = "";
    int len;
    // menerima input user berupa string yang disimpan di inStr
    printf("Masukkan string: ");
    scanf("%s", inStr);
    // melakukan perulangan sampai akhir menemupakan space kosong untuk menhitung..
    // .. panjang string yang dimasukkan user.
    for(len = 0; inStr[len] != '\0'; len++);
    // menyiapkan variabel array karakter dengan panjang yang sudah didapatkan
    char str[len];
    // menyalin isi inStr ke str. ini diperlukan karena str memiliki panjang..
    // .. atau ukuran yang jelas sehingga bisa menghasilkan nilai yang ..
    // .. sesuai bila nanti diambil niai panjang/ukurannya menggunakan..
    // .. fungsi "strlen()".
    strcpy(str, inStr);
    // 2 pangkat banyak digit adalah jumlah kemungkinan subsekuen sebuah string
    int poss = pow(2, len);
    printf("Subsekuen (%d kemungkinan): \n", poss);
    // panggil fungsi "subsekuan" yang akan menampilkan semua sebsekuen dari..
    // .. string yang diinputkan user.
    subsekuen(str, 0, temp);
}