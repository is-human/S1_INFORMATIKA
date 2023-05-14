//memanggil header file stdio.h untuk akses fungsi standar input dan output
#include <stdio.h>
//fungsi pertama yang pertama kali akan dieksekusi program
int main(){
	//deklarasi variabel len(panjang) dan sum(total)
	int len, sum = 0;
	//menerima dan menyimpan input pengguna berupa angka untuk panjang array
	scanf("%d", &len);
	//deklarasi array dengan panjang yang ditentukan pengguna
	int arr[len];
	//perulangan sebanyak panjang array
	for(int i = 0; i < len; i++){
		//menerima dan menyimpan input untuk array pada indeks i
	    scanf(" %d", &arr[i]);
		//menjumlahkan inputan ke variabel total
	    sum += arr[i];
	}
	//menamoilkan hasil dari pembagian total dengan jumlah yang casting menjadi float
	printf ("%.2f", (float) sum/len);
}


