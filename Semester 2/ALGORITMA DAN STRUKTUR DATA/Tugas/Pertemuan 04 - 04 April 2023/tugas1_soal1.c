//memangggil header file stdio.h untuk akses fungsi standar input dan output
#include <stdio.h>

//fungsi utama yang akan pertama kali dieksekusi program
int main() {
	//deklarasi array dengan ukuran 2 x 3
	int arr[2][3], temp;
	//melakukan perulangan 2x untuk menyeser dimensi 1 dari array
	for(int x = 0; x < 2; x++){
		//melakukan perulangan 3x untuk menyeser dimensi 2 dari array
	    for(int y = 0; y < 3; y++){
			//menampilkan pernyataan indeks array
	        printf("Nilai array indeks[%d][%d] adalah : ", x, y);
			//meneriman input user untuk array pada indeks [x][y]
			scanf("\n%d", &arr[x][y]);
	    }
	}
}


