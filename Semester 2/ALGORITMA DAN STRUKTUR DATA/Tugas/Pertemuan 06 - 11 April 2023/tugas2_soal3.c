//memanggil header file stdio.h untuk akses fungsi standar input dan output
#include <stdio.h>
//prosedur untuk menampilkan titik-titik yang bisa dicapai kuda (knight) sesuai nilai titik [i][j] yang diterima.
void koboImaginaryChess(int i, int j, int size, int *chessBoard){
    //melakukan perulangan sebanyak 8 kali (8 baris)
    for(int x = 0; x < size; x++){
        //melakukan perulangan sebanyak 8 kali (8 kolom)
        for(int y = 0; y < size; y++){
            //menyimpan nilai 0 pada indeks [x][y]
            *(chessBoard + x * size + y) = 0;     
            //jika (i - x) adalah 2, maka baris (x) adalah baris dimana titik yang bisa dicapai kuda (knight) berada.
            if((i - x) == 2){
                //jika (j - y) adalah 1 atau (y - j) adalah 1,
                // maka kolom (y) adalah kolom dimana titik yang bisa dicapai kuda (knight) berada.
                if((j - y) == 1 || (y - j) == 1){
                    //menyimpan nilai 1 pada indeks [x][y] sebagai tanda dari titik yang bisa dicapai kuda (knight).
                    *(chessBoard + x * size + y) = 1;
                }
            }          
            //jika (i - x) adalah 1, maka baris (x) adalah baris dimana titik yang bisa dicapai kuda (knight) berada.
            if((i - x) == 1){
               //jika (j - y) adalah 2 atau (y - j) adalah 2,
               // maka kolom (y) adalah kolom dimana titik yang bisa dicapai kuda (knight) berada.
               if((j - y) == 2 || (y - j) == 2){
                    //menyimpan nilai 1 pada indeks [x][y] sebagai tanda dari titik yang bisa dicapai kuda (knight).
                    *(chessBoard + x * size + y) = 1;
               }    
            }
            //jika (x - i) adalah 1, maka baris (x) adalah baris dimana titik yang bisa dicapai kuda (knight) berada.
            if((x - i) == 1){
               //jika (j - y) adalah 2 atau (y - j) adalah 2,
               // maka kolom (y) adalah kolom dimana titik yang bisa dicapai kuda (knight) berada.
               if((j - y) == 2 || (y - j) == 2){
                    //menyimpan nilai 1 pada indeks [x][y] sebagai tanda dari titik yang bisa dicapai kuda (knight).
                    *(chessBoard + x * size + y) = 1;
               }    
            }     
            //jika (x - i) adalah 2, maka baris (x) adalah baris dimana titik yang bisa dicapai kuda (knight) berada.
            if((x - i) == 2){
                //jika (j - y) adalah 2 atau (y - j) adalah 2,
                // maka kolom (y) adalah kolom dimana titik yang bisa dicapai kuda (knight) berada.
                if((j - y) == 1 || (y - j) == 1){
                    //menyimpan nilai 1 pada indeks [x][y] sebagai tanda dari titik yang bisa dicapai kuda (knight).
                    *(chessBoard + x * size + y) = 1;
                }
            }
            //menampilkan kotak yang direpesentasikan dengan 0 dan 1                   
            printf("%d ", *(chessBoard + x * size + y));
        } 
        //mencetak baris baru (newline)
        printf("\n");
    }
}
//fungsi utama yang akan pertama kali dieksekusi program
int main(){
	//mendeklarasikan variabel-variabel yang diperlukan
	int i, j, arr[8][8];
	//menerima dan menyimpan inputan dari user ke variabel i dan j sebagai titik posisi kuda (knight) bearada.
	scanf("%d %d", &i, &j);
	//memanggil fungsi koboImaginaryChess dengan mengoper variabel-variabel yang diperlukan.
    koboImaginaryChess(i, j, 8, arr[0]);
}


