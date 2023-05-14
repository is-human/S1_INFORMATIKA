//memanggil header file stdio.h untuk akses fungsi standar input dan output
#include <stdio.h>
//fungsi untuk memilah dan mengembalikan nilai terbesar dari array
int greatestOf(int *arr){
    //sebagai permisalan, nilai terbesar saat ini adalah 0
    int max = 0;
    //melakukan perulangan untuk menyisir selueruh isi array
    for(int a = 0; a < 4; a++){
        //jika nilai dari array panda ideks a lebih besar dari nilai terbesar saat ini,
        // maka nilai array tersebut akan menggantikan nilai terbesar saat ini. 
        if(arr[a] > max) max = arr[a];
    }
    //mengembalikan nilai terbesar
    return max;
}

//fungsi utama yang pertama kali akan dieksekusi program
int main(){
    //deklarasi array dengan panjang 4 elemen
	int arr[4];
    //menerima dan menyimpan input pengguna untuk setiap elemen array di atas
	scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
    //menampilkan nilai terbesar dari array yang didapat dari nilai kembalian fungsi greatestOf
	printf("%d", greatestOf(arr));
}

