//memanggil header file stdio.h untuk akses fungsi standar input dan output
#include <stdio.h>
//memanggil header file stdlib.h untuk akses operasi konversi
#include <stdlib.h> 
//membuat struct dengan nama alias Trapesium yang memiliki member x dan y
typedef struct coordinatTrapesium{
    int x;
    int y;
} Trapesium;
//fungsi utama yang pertama kali akan dieksekusi program
int main(){
    //deklarasi array koordinat sepanjang 6 dengan tipe struktur Trapesium
    Trapesium koordinat[6];
    //deklasrasi dan inisialisasi variabel al dengan 'A' yang nantinya
    //akan dimanfaatkan untuk output
    char al = 'A';
    //variabel untuk menyimpan sisi atas, sisi bawah dan tinggi trapesium
    int atas, bawah, tinggi;
    //perulangan sebanyak 6 kali
    for(int i = 0; i < 6; i++){
        //menampilkan tulisan koordinat saat ini
        printf("Koordinat Titik %c (x,y): ", al);
        //menerima nilai x dan y untuk koordinat saat ini
        scanf(" %d %d", &koordinat[i].x, &koordinat[i].y);
        //menambah angka 1 ke variabel al sehingga maju satu huruf
        al++;
    }
    //sisi atas = pengurangan titik x dari koordinat A dengan B yang dimutlak
    atas = abs(koordinat[0].x - koordinat[1].x);
    //sisi bawah = pengurangan titik x dari koordinat E dengan F yang dimutlak
    bawah = abs(koordinat[4].x - koordinat[5].x);
    //tinggi = pengurangan titik y dari koordinat A dengan C yang dimutlak
    tinggi = abs(koordinat[0].y - koordinat[2].y);
    //nilai-nilai di atas perlu dimutlak agar tidak negatif
    //menampilkan hasil hitung luas trapesium
    printf("Luat trapesium : %.2f", (float) (atas + bawah) * tinggi * 0.5);
    return 0;
}

