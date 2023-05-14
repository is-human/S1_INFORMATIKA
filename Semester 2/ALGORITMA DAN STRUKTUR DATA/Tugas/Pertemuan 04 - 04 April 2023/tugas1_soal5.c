//memangggil header file stdio.h untuk akses fungsi standar input dan output
#include <stdio.h>

//fungsi utama yang akan pertama kali dieksekusi program
int main(){
    //deklrasi variabel yang diperlukan, array dan inisialisasinya
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, lantai, bawah, atas;
    //meminta user untuk memilih lantai 1-10
    printf("Pilih Lantai [1-10] : ");
    //menerima input berupa bilangan desimal
    scanf(" %d", &lantai);
    //pengondisian untuk menentukan output berdasar input user
    if(lantai < 3 && lantai >= 0){
        //bila user memilih 'lantai' dengan nilai |0 <= lantai < 3|, maka
        //ditentukan bahwa 'bawah' = 0 dan 'atas' = 5
        bawah = 0; atas = 5;
    }else if(lantai > 8 && lantai <= 10){
        //bila user memilih 'lantai' dengan nilai |8 < lantai <= 10|, maka
        //ditentukan bahwa 'bawah' == 5 dan 'atas' = 10
        bawah = 5; atas = 10;
    }else if(lantai < 0 || lantai > 10){
        //bila user memilih 'lantai' denan nilai |lantai < 0 || lantai > 10|, maka
        //akan diberi peringatan berupa ancaman memanggil farhan kebab
        printf("[PERINGATAN]\n\"Memanggil Farhan Kebab\"");
        //lalu mengarkhiri program
        return 0;
    }else{
        //kondisi default, bila kondisi-kondisi di atas tidak terpenuhi
        //ditentukan sebagai berikut demi membatasi perulangan sebanyak 5 kali saja
        bawah = lantai-3;
        atas = lantai + 2;
    }
    //perulangan dari 'bawah' sampai sebelum 'atas'
    for(bawah; bawah < atas; bawah++){
        //menampilkan angka dari array dengan tanda khusus
        if(arr[bawah] == lantai) printf("[%d] ", arr[bawah]);
        //menampilkan angka dari array
        else printf("%d ", arr[bawah]);
    }
}

