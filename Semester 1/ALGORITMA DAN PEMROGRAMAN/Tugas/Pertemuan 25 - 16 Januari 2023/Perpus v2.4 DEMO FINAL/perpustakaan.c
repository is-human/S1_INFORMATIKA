//versi 2.4 DEMO FINAL
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>





//#[VARIABEL GLOBAL - START]#################################################################################################################

//Konstanta (Nilai Tetap)
#define MAX_JUMLAH 100
#define MAX_STRING 31
#define PROPERTI_BUKU 6
#define PROPERTI_PEMINJAMAN 5

//Data Buku
char rak_buku[MAX_JUMLAH][PROPERTI_BUKU][MAX_STRING];
int jumlah_buku = 3;                                    //Jumlah "buku" yang tersimapn dalam "rak_buku" saat ini
int jumlah_buku_tersedia = 2;                           
int kode_unik = 20103;                                  //Kode unik dari buku terbaru(buku ke-3)
char properti_buku[PROPERTI_BUKU][10] = {"Kode", "Judul", "Tema", "Penulis", "Tahun", "Status"};

//Data Peminjaman
char daftar_peminjaman[MAX_JUMLAH][PROPERTI_PEMINJAMAN][MAX_STRING];
int jumlah_peminjaman = 2;
char properti_peminjaman[PROPERTI_BUKU][25] = {"Kode Buku", "Peminjam", "Tanggal Peminjaman", "Batas Waktu", "Tanggal Pengembailan"};
char properti_peminjaman_isian[PROPERTI_BUKU][MAX_STRING] = {
                                                                "Kode Buku", 
                                                                "Peminjam", 
                                                                "Tgl Peminjaman [yyyy.mm.dd]", 
                                                                "Batas Waktu [yyyy.mm.dd]", 
                                                                "Tgl Pengembailan [yyyy.mm.dd]"
                                                            };

//#[VARIABEL GLOBAL - END]###################################################################################################################





//#[PEMBANTU - START]########################################################################################################################

//MEMBUAT DATA BONEKA
void bikinDataDummy(){
    //Buku 1
    strcpy(rak_buku[0][0], "20101");                // Kode
    strcpy(rak_buku[0][1], "Kiamat Gan!");          // Judul
    strcpy(rak_buku[0][2], "Edukasi");              // Tema
    strcpy(rak_buku[0][3], "Yanto Dharmaboi");      // Pemulis
    strcpy(rak_buku[0][4], "2012");                 // Tahun
    strcpy(rak_buku[0][5], "TIDAK TERSEDIA");       // Status

    //Buku 2
    strcpy(rak_buku[1][0], "20102");
    strcpy(rak_buku[1][1], "Kiamat OTW");
    strcpy(rak_buku[1][2], "Fiksi");
    strcpy(rak_buku[1][3], "Yanto Dharmaboi");
    strcpy(rak_buku[1][4], "2011");
    strcpy(rak_buku[1][5], "TERSEDIA");

    //Buku 3
    strcpy(rak_buku[2][0], "20103");
    strcpy(rak_buku[2][1], "Kiamat Ditunda");
    strcpy(rak_buku[2][2], "Komedi");
    strcpy(rak_buku[2][3], "Yanto Dharmaboi");
    strcpy(rak_buku[2][4], "2014");
    strcpy(rak_buku[2][5], "TERSEDIA");

    //-------------------------------------------------

    //Peminjaman 1
    strcpy(daftar_peminjaman[0][0], "20103");                  // Kode Buku
    strcpy(daftar_peminjaman[0][1], "Ferry Ferryansyah");      // Peminjam
    strcpy(daftar_peminjaman[0][2], "2022.02.10");             // Tanggal Peminjaman
    strcpy(daftar_peminjaman[0][3], "2022.02.20");             // Batas Waktu
    strcpy(daftar_peminjaman[0][4], "2022.02.15");             // Tanggal Pengembalian
    
    //Peminjaman 2
    strcpy(daftar_peminjaman[1][0], "20101");
    strcpy(daftar_peminjaman[1][1], "Ferdy Samsudin");
    strcpy(daftar_peminjaman[1][2], "2023.01.02");
    strcpy(daftar_peminjaman[1][3], "2023.01.10");
    // strcpy(daftar_peminjaman[1][4], "2023.01.07");
    strcpy(daftar_peminjaman[1][4], "-");

}

void tampilkanJejak(char posisi[100]){
    printf("\n\nPERPUSTAKAAN \\ %s\n\n", posisi);
}

//#[PEMBANTU - END]##########################################################################################################################




//PROSEDUR UNTUK MENUKAR POSISI DATA PEMINJAMAN DARA PADAN INDEKS n DENGAN n+1
void tukarPosisiPeminjaman(int indeks_kiri, int indeks_kanan){
    char sementara[MAX_STRING];
    for(int a = 0;  a < PROPERTI_PEMINJAMAN; a++){
        strcpy(sementara, daftar_peminjaman[indeks_kiri][a]);
        strcpy(daftar_peminjaman[indeks_kiri][a], daftar_peminjaman[indeks_kanan][a]);
        strcpy(daftar_peminjaman[indeks_kanan][a], sementara);
    }
}




//#[MANAJEMEN BUKU - START]##################################################################################################################

//PROSEDUR UNTUK MENAMPILKAN DATA BUKU
void tampilkanDataBuku(int kategori, char kata_kunci[MAX_STRING]){

    int tempSpace;
    int totalData = 0;

    printf("+=====+===========+================================+======================+===============================+==========+======================+\n");
    printf("|BARIS| KODE BUKU | JUDUL BUKU                     | TEMA                 | NAMA PENULIS                  | TAHUN    | STATUS               |\n");
    printf("+=====+===========+================================+======================+===============================+==========+======================+\n");    
    for(int a = 0; a < jumlah_buku; a++){        

        if(kategori >= 0 && kategori < PROPERTI_BUKU && kata_kunci != ""){
            if(strcmp(rak_buku[a][kategori], kata_kunci) != 0){
                if(a == jumlah_buku - 1 && totalData == 0){
                    //Data Tidak Ditemukan 
                    printf("|                                                            DATA TIDAK DITEMUKAN                                                           |\n");
                    printf("+-------------------------------------------------------------------------------------------------------------------------------------------+\n"); 
                    break;
                }
                continue;
            }
        }

        //Baris
        if(a < 9) printf("| %d   ", a+1);
        else if(a < 99) printf("| %d  ", a+1);
        else printf("| %d ", a+1);

        //Kode
        printf("| %s ", rak_buku[a][0]);
        tempSpace = 9 - strlen(rak_buku[a][0]);
        for(int t = 0; t < tempSpace; t++){
            printf(" ");
        }

        //Judul
        printf("| %s ", rak_buku[a][1]);
        tempSpace = MAX_STRING - 1 - strlen(rak_buku[a][1]);
        for(int t = 0; t < tempSpace; t++){
            printf(" ");
        }

        //Tema
        printf("| %s ", rak_buku[a][2]);
        tempSpace = 20 - strlen(rak_buku[a][2]);
        for(int t = 0; t < tempSpace; t++){
            printf(" ");
        }

        //Penulis
        printf("| %s", rak_buku[a][3]);
        tempSpace = MAX_STRING - 1 - strlen(rak_buku[a][3]);
        for(int t = 0; t < tempSpace; t++){
            printf(" ");
        }

        //Tahun
        printf("| %s ", rak_buku[a][4]);
        tempSpace = 8 - strlen(rak_buku[a][4]);
        for(int t = 0; t < tempSpace; t++){
            printf(" ");
        }

        //Status
        printf("| %s ", rak_buku[a][5]);
        tempSpace = 20 - strlen(rak_buku[a][5]);
        for(int t = 0; t < tempSpace; t++){
            printf(" ");
        }

        //Baris Baru
        printf("|\n");
        printf("+-----+-----------+--------------------------------+----------------------+-------------------------------+----------+----------------------+\n");

        totalData = totalData + 1;

        // printf("|[%d\t][%s\t\t][%s\t][%s\t\t][%s\t][%s\t]|\n", a+1, rak_buku[a][0], rak_buku[a][1], rak_buku[a][2], rak_buku[a][3], rak_buku[a][4]);
    }

    printf("~ Total Data Buku = %d\n", totalData);
}

//PROSEDUR UNTUK MENCARI DATA BUKU (SEARCH)
void cariDataBuku(){

    int kategori;
    char kata_kunci[MAX_STRING];
    char konfirmasi[] = "t";

    do{
        do{
            system("cls");
            tampilkanJejak("Beranda \\ Data Buku \\ Pencarian Data Buku");
            tampilkanDataBuku(-1, "");
            printf("\nKategori Pencarian\n");
            for(int i = 0; i < PROPERTI_BUKU; i++){
                printf(" %d. %s\n", i+1, properti_buku[i]);
            }
            printf("\n> Pilih Kategori : ");
            scanf("%d", &kategori);

            kategori = kategori - 1;

            printf("> Cari %s : ", properti_buku[kategori]);
            scanf("\n%[^\n]s", kata_kunci);
            
        }while(kategori < 0 || kategori > PROPERTI_BUKU || strlen(kata_kunci) < 1 || strlen(kata_kunci) > 30);

        printf("\n~ Hasil Pencarian Data Dengan %s = %s \n", properti_buku[kategori], kata_kunci);
        tampilkanDataBuku(kategori, kata_kunci);

        printf("\n> Ulangi Pencarian [Y/T] : ");
        scanf("%s", &konfirmasi);

    }while(strcmp(konfirmasi, "Y") == 0 || strcmp(konfirmasi, "y") == 0);

}

//PROSEDUR UNTUK MENUKAR POSISI DATA BUKU DARA PADAN INDEKS n DENGAN n+1
void tukarPosisiBuku(int indeks_kiri, int indeks_kanan){
    char sementara[MAX_STRING];
    for(int a = 0;  a < PROPERTI_BUKU; a++){
        strcpy(sementara, rak_buku[indeks_kiri][a]);
        strcpy(rak_buku[indeks_kiri][a], rak_buku[indeks_kanan][a]);
        strcpy(rak_buku[indeks_kanan][a], sementara);
    }
}

//PROSEDUR UNTUK MENGURUTKAN DATA BUKU (SORT)
void urutkanDataBuku(){
    int tipe, kategori;
    bool selesai = false;
    do{
        system("cls");
        tampilkanJejak("Beranda \\ Data Buku \\ Pengurutan Data Buku");
        tampilkanDataBuku(-1, "");
        printf("\nKategori Pengurutan\n");
        //Menampilkan semua properti buku kecuali properti terakhir yaitu "Status"
        for(int i = 0; i < PROPERTI_BUKU; i++){
            printf(" %d. %s\n", i+1, properti_buku[i]);
        }
        printf("\n> Pilih Kategori : ");
        scanf("%d", &kategori);
        printf("\nTipe Pengurutan\n");
        printf(" 1. Dari nilai terkecil ke yang terbesar (Ascending)\n");
        printf(" 2. Dari nilai terbesar ke yang terkecil (Descending)\n");
        printf("\n> Pilih Tipe : ");
        scanf("%d", &tipe);
        
    }while(kategori < 1 || kategori > PROPERTI_BUKU || tipe < 1 || tipe > 2);

    //Bubble Sort
    for(int a = 0; a < jumlah_buku - 1; a++){
        for(int b = 0; b < jumlah_buku - 1 - a; b++){
            if(tipe == 1){
                if(strcmp(rak_buku[b][kategori-1], rak_buku[b+1][kategori-1])>0){
                    tukarPosisiBuku(b, b+1);
                }
            }
            else if(tipe == 2){
                if(strcmp(rak_buku[b][kategori-1], rak_buku[b+1][kategori-1])<0){
                    tukarPosisiBuku(b, b+1);
                }
            }
        }
    }

}

//PROSEDUR UNTUK MENAMBAH DATA BUKU (INSERT)
void tambahDataBuku(){
    tampilkanJejak("Beranda \\ Data Buku \\ Penambahan Data Buku");
    tampilkanDataBuku(-1, "");

    int indeks_baru = jumlah_buku;
    char tempSTR[PROPERTI_BUKU-1][MAX_STRING];
    char konfirmasi;

    printf("\nMasukkan Data Buku Baru [%d]\n", indeks_baru+1);

    for(int a = 1; a < PROPERTI_BUKU-1; a++){
        printf("> %s : ", properti_buku[a]);
        scanf("\n%[^\n]s", tempSTR[a-1]);
    }

    printf("\n> Konfirmasi Penambahan [Y/T] : ");
    scanf("\n%c", &konfirmasi);

    if(konfirmasi == 'Y' || konfirmasi == 'y'){
        jumlah_buku = jumlah_buku + 1;                      //menambah jumlah buku yang ditampung sebanyak 1
        jumlah_buku_tersedia = jumlah_buku_tersedia + 1;    

        for(int a = 1; a < PROPERTI_BUKU-1; a++){
            strcpy(rak_buku[indeks_baru][a], tempSTR[a-1]);
        }

        kode_unik = kode_unik + 1;

        char str[MAX_STRING];
        sprintf(str, "%d", kode_unik);

        strcpy(rak_buku[indeks_baru][0], str);
        strcpy(rak_buku[indeks_baru][5], "TERSEDIA");
    }
}

//PROSEDUR UNTUK MENGUBAH DATA BUKU (UPDATE)
void ubahDataBuku(){

    int baris;
    int kolom;
    char konfirmasi[] = "t";


    do{
        system("cls");
        tampilkanJejak("Beranda \\ Data Buku \\ Pengubahan Data Buku");
        tampilkanDataBuku(-1, "");
        printf("\n> Ubah Data Buku Dari Baris : ");
        scanf("%d", &baris);


        printf(
                "\n~ | %d | %s | %s | %s | %s | %s | %s |\n", 
                baris, 
                rak_buku[baris-1][0], 
                rak_buku[baris-1][1], 
                rak_buku[baris-1][2], 
                rak_buku[baris-1][3], 
                rak_buku[baris-1][4], 
                rak_buku[baris-1][5]
            );
        printf("\n~ Pada Pengubahan Data Buku, Anda tidak diberikan akses untuk mengubah kode buku dan status.\n");

        printf("\nKolom Data\n");
        //Menampilkan semua properti buku kecuali properti pertama dan terakhir yaitu "Kode" dan "Status"
        for(int i = 1; i < PROPERTI_BUKU - 1; i++){
            printf(" %d. %s\n", i, properti_buku[i]);
        }
        printf("\n> Pilih Kolom : ");
        scanf("%d", &kolom);
        
    }while(baris < 1 || baris > jumlah_buku || kolom < 1 || kolom > 4);

    baris = baris - 1;

    char tempSTR[MAX_STRING];
    printf("\n> Ubah %s : %s => ", properti_buku[kolom], rak_buku[baris][kolom]);
    scanf("\n%[^\n]s", tempSTR);

    printf("> Konfimasi Perubahan [Y/T] : ");
    scanf("%s", &konfirmasi);

    if(strcmp(konfirmasi, "Y") == 0 || strcmp(konfirmasi, "y") == 0){
        strcpy(rak_buku[baris][kolom], tempSTR);
    }

}

//PROSEDUR UNTUK MENGHAPUS DATA BUKU (DELETE)
void hapusDataBuku(){

    int baris;
    char konfirmasi;
    int indeksBuku;

    do{
        system("cls");
        tampilkanJejak("Beranda \\ Data Buku \\ Hapus Data Buku");

        tampilkanDataBuku(-1, "");

        printf("\n> Hapus Data Buku Dari Baris : ");
        scanf("%d", &baris);

    }while(baris < 1 || baris > jumlah_buku);

    printf("\n> Konfirmasi Hapus Data [Y/T] : ");
    scanf("\n%c", &konfirmasi);

    if(konfirmasi == 'Y' || konfirmasi == 'y'){
        
        for(int a = 0; a < jumlah_peminjaman; a++){
            if(
                strcmp(daftar_peminjaman[a][0], rak_buku[baris-1][0]) == 0
            ){
                for(int b = 0; b < PROPERTI_PEMINJAMAN; b++){
                    strcpy(daftar_peminjaman[a][b], "");
                }
                for(int c = a; c < jumlah_peminjaman-1; c++){
                    tukarPosisiPeminjaman(c, c+1);
                }
                a = a - 1;
                jumlah_peminjaman = jumlah_peminjaman - 1;
            }
        }

        if(strcmp(rak_buku[baris-1][PROPERTI_BUKU-1], "TERSEDIA") == 0){
            jumlah_buku_tersedia = jumlah_buku_tersedia - 1;
        }

        for(int a = 0; a < PROPERTI_BUKU; a++){
            strcpy(rak_buku[baris-1][a], "");
        }

        for(int a = baris-1; a < jumlah_buku-1; a++){
            tukarPosisiBuku(a, a+1);
        }
        jumlah_buku = jumlah_buku - 1;
    }
    
}

//PROSEDUR UNTUK MENAMPILKAN MENU MANAJEMEN BUKU (MENU)
void tampilkanMenuBuku(){
    bool selesai = false;
    int pilihan;

    do{
        tampilkanJejak("Beranda \\ Data Buku");
        tampilkanDataBuku(-1, "");
        printf("\nMenu Data Buku\n");
        printf(" 0. Kembali\n");
        printf(" 1. Pencarian Data Buku\n");
        printf(" 2. Pengurutan Data Buku\n");
        printf(" 3. Penambahan Data Buku\n");
        printf(" 4. Pengubahan Data Buku\n");
        printf(" 5. Hapus Data Buku\n");
        printf("\n> Pilih Menu : ");

        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 0:
            system("cls");
            return;
            break;
        case 1:
            system("cls");
            cariDataBuku();
            system("cls");
            break;
        case 2:
            system("cls");
            urutkanDataBuku();
            system("cls");
            break;
        case 3:
            system("cls");
            tambahDataBuku();
            system("cls");
            break;
        case 4:
            system("cls");
            ubahDataBuku();
            system("cls");
            break;
        case 5:
            system("cls");
            hapusDataBuku();
            system("cls");
            break;
        default:
            system("cls");
            break;
        }

    }while(selesai == false);
}

//#[MANAJEMEN BUKU - END]####################################################################################################################





//#[MANAJEMEN PEMINJAMAN - START]############################################################################################################

//FUNGSI UNTUK MENDAPATKAN INDEKS DARI BUKU DENGAN KODE YANG DITENTUKAN
int cariIndeksJudulBuku(char kode_buku[MAX_STRING]){
    //Mencari Judul dari buku dengan Kode yang ditentukan
    //Sequential(Linear) Search
    for(int a = 0; a < jumlah_buku; a++){
        if(strcmp(rak_buku[a][0], kode_buku) == 0){
            return a;
        }
    }

    return -1;
}

//PROSEDUR UNTUK MENAMPILKAN DATA PEMINJAMAN
void tampilkanDataPeminjaman(int kategori, char kata_kunci[MAX_STRING]){

    int tempSpace;
    int totalData = 0;
    int indeksBuku;
    // printf("\nJumlah Pemminjaman  = %d\n\n", jumlah_peminjaman);
    printf("+=====+===========+================================+================================+======================+======================+======================+\n");
    printf("|BARIS| KODE BUKU | JUDUL BUKU                     | NAMA PEMINJAM                  | TANGGAL PEMINJAMAN   | BATAS WAKTU          | TANGGAL PENGEMBALIAN |\n");
    printf("+=====+===========+================================+================================+======================+======================+======================+\n");    
    for(int a = 0; a < jumlah_peminjaman; a++){        

        if(kategori >= 0 && kategori < PROPERTI_PEMINJAMAN && kata_kunci != ""){
            if(strcmp(daftar_peminjaman[a][kategori], kata_kunci) != 0){
                if(a == jumlah_peminjaman - 1 && totalData == 0){
                    //Data Tidak Ditemukan 
                    printf("|                                                                      DATA TIDAK DITEMUKAN                                                              |\n");
                    printf("+--------------------------------------------------------------------------------------------------------------------------------------------------------+\n"); 
                    break;
                }
                continue;
            }
        }

        //Baris
        if(a < 9) printf("| %d   ", a+1);
        else if(a < 99) printf("| %d  ", a+1);
        else printf("| %d ", a+1);

        //Kode
        printf("| %s ", daftar_peminjaman[a][0]);
        tempSpace = 9 - strlen(daftar_peminjaman[a][0]);
        for(int t = 0; t < tempSpace; t++){
            printf(" ");
        }

        //Judul
        indeksBuku = cariIndeksJudulBuku(daftar_peminjaman[a][0]);
        printf("| %s ", rak_buku[indeksBuku][1]);
        tempSpace = MAX_STRING - 1 - strlen(rak_buku[indeksBuku][1]);
        for(int t = 0; t < tempSpace; t++){
            printf(" ");
        }

        //Penulis
        printf("| %s ", daftar_peminjaman[a][1]);
        tempSpace = MAX_STRING - 1 - strlen(daftar_peminjaman[a][1]);
        for(int t = 0; t < tempSpace; t++){
            printf(" ");
        }

        //Tanggal Peminjaman
        printf("| %s ", daftar_peminjaman[a][2]);
        tempSpace = 20 - strlen(daftar_peminjaman[a][2]);
        for(int t = 0; t < tempSpace; t++){
            printf(" ");
        }

        //Batas Waktu
        printf("| %s ", daftar_peminjaman[a][3]);
        tempSpace = 20 - strlen(daftar_peminjaman[a][3]);
        for(int t = 0; t < tempSpace; t++){
            printf(" ");
        }

        //Tanggal Peminjaman
        printf("| %s ", daftar_peminjaman[a][4]);
        tempSpace = 20 - strlen(daftar_peminjaman[a][4]);
        for(int t = 0; t < tempSpace; t++){
            printf(" ");
        }

        //Baris Baru
        printf("|\n"); 
        printf("+-----+-----------+--------------------------------+--------------------------------+----------------------+----------------------+----------------------+\n");

        totalData = totalData + 1;

    }
    if(jumlah_peminjaman <= 0){
        //Data Tidak Ditemukan 
        printf("|                                                                      DATA TIDAK DITEMUKAN                                                              |\n");
        printf("+--------------------------------------------------------------------------------------------------------------------------------------------------------+\n"); 
        
    }
    printf("~ Total Data Peminjaman = %d\n", totalData);

}

//PROSEDUR UNTUK MENCARI DATA PEMINJAMAN (SEARCH)
void cariDataPeminjaman(){

    int kategori;
    char kata_kunci[MAX_STRING];
    char konfirmasi[] = "t";

    do{
        do{
            system("cls");
            tampilkanJejak("Beranda \\ Data Peminjaman \\ Pencarian Data Peminjaman");
            tampilkanDataPeminjaman(-1, "");
            printf("\nKategori Pencarian\n");
            for(int i = 0; i < PROPERTI_PEMINJAMAN; i++){
                printf(" %d. %s\n", i+1, properti_peminjaman[i]);
            }
            printf("\n> Pilih Kategori : ");
            scanf("%d", &kategori);

            if(kategori == PROPERTI_PEMINJAMAN){
                printf("\n~ Gunakan \"-\" (tanda minus/kurang) bila hendak mencari data yang belum memiliki Tanggal Pemgembalian (Buku belum dikembalikan).\n");
            }

            kategori = kategori - 1;

            printf("> Cari %s : ", properti_peminjaman_isian[kategori]);
            scanf("\n%[^\n]s", kata_kunci);
            
        }while(kategori < 0 || kategori > PROPERTI_PEMINJAMAN || strlen(kata_kunci) < 1 || strlen(kata_kunci) > 30);

        printf("\n~ Hasil Pencarian Data Dengan %s = %s \n", properti_peminjaman[kategori], kata_kunci);
        tampilkanDataPeminjaman(kategori, kata_kunci);

        printf("\n> Ulangi Pencarian [Y/T] : ");
        scanf("%s", &konfirmasi);

    }while(strcmp(konfirmasi, "Y") == 0 || strcmp(konfirmasi, "y") == 0);

}


//PROSEDUR UNTUK MENGURUTKAN DATA PEMINJAMAN (SORT)
void urutkanDataPeminjaman(){
    int tipe, kategori;
    bool selesai = false;
    do{
        system("cls");
        tampilkanJejak("Beranda \\ Data Peminjaman \\ Pengurutan Data Peminjaman");
        tampilkanDataPeminjaman(-1, "");
        printf("\nKategori Pengurutan\n");

        for(int i = 0; i < PROPERTI_PEMINJAMAN; i++){
            printf(" %d. %s\n", i+1, properti_peminjaman[i]);
        }

        printf("\n> Pilih Kategori : ");
        scanf("%d", &kategori);
        printf("\nTipe Pengurutan\n");
        printf(" 1. Dari nilai terkecil ke yang terbesar (Ascending)\n");
        printf(" 2. Dari nilai terbesar ke yang terkecil (Descending)\n");
        printf("\n> Pilih Tipe : ");
        scanf("%d", &tipe);
        
    }while(kategori < 1 || kategori > PROPERTI_PEMINJAMAN || tipe < 1 || tipe > 2);

    //Bubble Sort
    for(int a = 0; a < jumlah_peminjaman - 1; a++){
        for(int b = 0; b < jumlah_peminjaman - 1 - a; b++){
            if(tipe == 1){
                if(strcmp(daftar_peminjaman[b][kategori-1], daftar_peminjaman[b+1][kategori-1])>0){
                    tukarPosisiPeminjaman(b, b+1);
                }
            }
            else if(tipe == 2){
                if(strcmp(daftar_peminjaman[b][kategori-1], daftar_peminjaman[b+1][kategori-1])<0){
                    tukarPosisiPeminjaman(b, b+1);
                }
            }
        }
    }

}

//PROSEDUR UNTUK MENAMBAH DATA PEMINJAMAN (INSERT)
void tambahDataPeminjaman(){

    // char ch;

    bool status_buku = true;
    int indeks_buku;
    int indeks_baru = jumlah_peminjaman;
    char tempSTR[PROPERTI_PEMINJAMAN-1][MAX_STRING];
    char konfirmasi;


    do{
        system("cls");
        // printf("\njumlah buku tersedia = %d\n", jumlah_buku_tersedia);
        tampilkanJejak("Beranda \\ Data Peminjaman \\ Penambahan Data Peminjaman");
        tampilkanDataBuku(PROPERTI_BUKU-1, "TERSEDIA");

        if(jumlah_buku_tersedia <= 0){
            printf("\n~ Tidak ada buku yang TERSEDIA untuk dipinjam.\n");
            printf("~ Tidak dapat menambahkan data peminjaman baru.\n\n");
            system("pause");
            return;
            // printf("\n> Kembali [Y] : ");
            // scanf("\n%c", &ch);
            // if(ch || ch == '\n'){
            //     return;
            // }
        }

        if(status_buku == false){
            printf("\n~ Buku dengan kode \"%s\" tidak tersedia.\n", tempSTR[0]);
        }

        printf("\nMasukkan Data Peminjaman Baru\n");

        for(int a = 0; a < PROPERTI_PEMINJAMAN-1; a++){
            printf("> %s : ", properti_peminjaman_isian[a]);
            scanf("\n%[^\n]s", tempSTR[a]);
        }

        indeks_buku = cariIndeksJudulBuku(tempSTR[0]);
        if(indeks_buku != -1 && strcmp(rak_buku[indeks_buku][PROPERTI_BUKU-1], "TERSEDIA") == 0){
            status_buku = true;
        }else{
            status_buku = false;
        }

        printf("\n> Konfirmasi Penambahan [Y/T] : ");
        scanf("\n%c", &konfirmasi);

        if(konfirmasi == 'T' || konfirmasi == 't'){
            break;
        }

    }while(status_buku != true);


    if(konfirmasi == 'Y' || konfirmasi == 'y'){
        for(int a = 0; a < PROPERTI_PEMINJAMAN-1; a++){
            strcpy(daftar_peminjaman[indeks_baru][a], tempSTR[a]);
        }
        strcpy(daftar_peminjaman[indeks_baru][PROPERTI_PEMINJAMAN-1], "-");
        jumlah_peminjaman = jumlah_peminjaman + 1; //menambah jumlah peminjaman yang ditampung sebanyak 1

        strcpy(rak_buku[indeks_buku][PROPERTI_BUKU-1], "TIDAK TERSEDIA");
        jumlah_buku_tersedia = jumlah_buku_tersedia - 1;
    }

}

//PROSEDUR UNTUK MENGUBAH DATA PEMINJAMAN (UPDATE)
void ubahDataPeminjaman(){

    int baris;
    int kolom;
    char konfirmasi[] = "t";
    int indeksBuku;
    int indeksBukuBaru;
    char tempSTR[MAX_STRING];
    char tempSTR_2[MAX_STRING];
    bool status_buku = true;


    do{
        do{
            system("cls");
            tampilkanJejak("Beranda \\ Data Peminjaman \\ Pengubahan Data Peminjaman");

            tampilkanDataPeminjaman(-1, "");

            if(status_buku == false && kolom == 0){
                printf("\n~ Buku dengan kode \"%s\" tidak tersedia.\n", tempSTR);
            }

            if(status_buku == false && kolom == PROPERTI_PEMINJAMAN-1){
                printf("\n~ Tidak bisa membatalkan pengembalian. Buku \"%s\" sedang tidak tersedia untuk dipinjam.\n", rak_buku[indeksBuku][1]);
            }

            printf("\n> Ubah Data Peminjaman Dari Baris : ");
            scanf("%d", &baris);

            indeksBuku = cariIndeksJudulBuku(daftar_peminjaman[baris-1][0]);
            
            printf(
                    "\n~ | %d | %s | %s | %s | %s | %s | %s |\n", 
                    baris, 
                    daftar_peminjaman[baris-1][0], 
                    rak_buku[indeksBuku][1],
                    daftar_peminjaman[baris-1][1], 
                    daftar_peminjaman[baris-1][2], 
                    daftar_peminjaman[baris-1][3], 
                    daftar_peminjaman[baris-1][4]
                );
            printf("\n~ Pada Pengubahan Data Peminjaman, Anda tidak diberikan akses untuk mengubah judul buku.\n");

            printf("\nKolom Data\n");
            //Menampilkan semua properti peminjaman
            for(int i = 1; i <= PROPERTI_PEMINJAMAN; i++){
                printf(" %d. %s\n", i, properti_peminjaman[i-1]);
            }
            printf("\n> Pilih Kolom : ");
            scanf("%d", &kolom);

            if(kolom == 1){
                printf("\n~ Daftar buku yang tersedia untuk dipinjam.\n");
                tampilkanDataBuku(PROPERTI_BUKU-1, "TERSEDIA");
            }
            
        }while(baris < 1 || baris > jumlah_peminjaman || kolom < 1 || kolom > PROPERTI_PEMINJAMAN);

        if(kolom == PROPERTI_PEMINJAMAN){
            printf("\n~ Gunakan \"-\" (tanda minus/kurang) bila hendak mengosokan kolom Tanggal Pemgembalian.\n");
        }

        baris = baris - 1;
        kolom = kolom - 1;

        printf("\n> Ubah %s : %s => ", properti_peminjaman_isian[kolom], daftar_peminjaman[baris][kolom]);
        scanf("\n%[^\n]s", tempSTR);

        printf("> Konfimasi Perubahan [Y/T] : ");
        scanf("%s", &konfirmasi);


        //Bila memilih untuk mengubah buku yang dipinjam
        if(kolom == 0){
            indeksBukuBaru = cariIndeksJudulBuku(tempSTR);
            if(indeksBukuBaru != -1 && strcmp(rak_buku[indeksBukuBaru][PROPERTI_BUKU-1], "TERSEDIA") == 0){
                status_buku = true;
            }else{
                if(strcmp(konfirmasi, "Y") == 0 || strcmp(konfirmasi, "y") == 0){
                    status_buku = false;
                }
                else{
                    // status_buku = true;
                    break;
                }
            }
        }else{
            status_buku = true;
        }

        //Antisipasi jika user hendak melakukan pembatalan pengembalian
        if(kolom == PROPERTI_PEMINJAMAN-1){
            if(
                strcmp(rak_buku[indeksBuku][PROPERTI_BUKU-1], "TIDAK TERSEDIA") == 0 &&     //Jika Buku yang dimaskud "TIDAK TERSEDIA" atau sedang dipinjam
                strcmp(daftar_peminjaman[baris][PROPERTI_PEMINJAMAN-1], "-") != 0 &&        //dan Tanggal pengembalian tidak kosong "-" atau buku yang dimaksud sudah dikembalikan
                strcmp(tempSTR, "-") == 0                                                   //dan hendak mengosongi Tanggal Pengembalian, yang mana berarti membatalkan pengembalian
            ){
                status_buku = false;
            }
            else{
                status_buku = true;
            }
        }

    }while(status_buku != true);

    if(strcmp(konfirmasi, "Y") == 0 || strcmp(konfirmasi, "y") == 0){
        strcpy(daftar_peminjaman[baris][kolom], tempSTR);

        int kosong = strcmp(daftar_peminjaman[baris][PROPERTI_PEMINJAMAN-1], "-"); // akan bernilai 0 jika buku belum dikembalikan

        //Jika properti terakhir (Tanggal Pengembalian) tidak kosong
        if(kolom == PROPERTI_PEMINJAMAN-1){
            if(kosong == 0){
                strcpy(rak_buku[indeksBuku][PROPERTI_BUKU-1], "TIDAK TERSEDIA");
                jumlah_buku_tersedia = jumlah_buku_tersedia - 1;
            }
            else{
                strcpy(rak_buku[indeksBuku][PROPERTI_BUKU-1], "TERSEDIA");
                jumlah_buku_tersedia = jumlah_buku_tersedia + 1;
            }
        }

        if(kolom == 0 && kosong == 0){
            strcpy(rak_buku[indeksBuku][PROPERTI_BUKU-1], "TERSEDIA");
            strcpy(rak_buku[indeksBukuBaru][PROPERTI_BUKU-1], "TIDAK TERSEDIA");
        }

    }

}

//PROSEDUR UNTUK MENGHAPUS DATA PEMINJAMAN (DELETE)
void hapusDataPeminjaman(){

    int baris;
    char konfirmasi;
    int indeksBuku;

    do{
        system("cls");
        tampilkanJejak("Beranda \\ Data Peminjaman \\ Penghapusan Data Peminjaman");

        tampilkanDataPeminjaman(-1, "");

        if(jumlah_peminjaman <= 0){
            printf("\n~ Tidak ada data peminjaman.\n");
            printf("~ Tidak dapat menghapus data.\n\n");
            system("pause");
            return;
        }

        printf("\n> Hapus Data Peminjaman Dari Baris : ");
        scanf("%d", &baris);


    }while(baris < 1 || baris > jumlah_peminjaman);

    printf("\n> Konfirmasi Penghapusan [Y/T] : ");
    scanf("\n%c", &konfirmasi);

    if(konfirmasi == 'Y' || konfirmasi == 'y'){
        
        if(strcmp(daftar_peminjaman[baris-1][PROPERTI_PEMINJAMAN-1], "-") == 0){
            indeksBuku = cariIndeksJudulBuku(daftar_peminjaman[baris-1][0]);
            strcpy(rak_buku[indeksBuku][PROPERTI_BUKU-1], "TERSEDIA");
            jumlah_buku_tersedia = jumlah_buku_tersedia + 1;
        }

        for(int a = 0; a < PROPERTI_PEMINJAMAN; a++){
            strcpy(daftar_peminjaman[baris-1][a], "");
        }

        for(int a = baris-1; a < jumlah_peminjaman; a++){
            if(a == jumlah_peminjaman-1){
                break;
            }
            tukarPosisiPeminjaman(a, a+1);
        }
        jumlah_peminjaman = jumlah_peminjaman - 1;
    }
    
}

//PROSEDUR UNTUK KEMBALIKAN BUKU (KEMBALI)
void kembalikanBuku(){

    int baris;
    int indeksBuku;
    char tempSTR[30];
    char konfirmasi;

    do{
        system("cls");
        tampilkanJejak("Beranda \\ Data Peminjaman \\ Pengembalian Buku");

        tampilkanDataPeminjaman(-1, "");

        printf("\n> Kembalikan Buku Dari Baris : ");
        scanf("%d", &baris);

        indeksBuku = cariIndeksJudulBuku(daftar_peminjaman[baris-1][0]);

        printf("\n> Tgl Pengembalian [yyyy.mm.dd] : ");
        scanf("\n%[^\n]s", tempSTR);
        
        printf("\n> Konfirmasi Pengembalian [Y/T] : ");
        scanf("\n%c", &konfirmasi);
        
    }while(baris < 1 || baris > jumlah_peminjaman || strcmp(daftar_peminjaman[baris-1][PROPERTI_PEMINJAMAN-1], "-") != 0);
    

    if(konfirmasi == 'Y' || konfirmasi == 'y'){
        strcpy(daftar_peminjaman[baris-1][PROPERTI_PEMINJAMAN-1], tempSTR);

        int kosong = strcmp(daftar_peminjaman[baris-1][PROPERTI_PEMINJAMAN-1], "-"); // akan bernilai 0 jika buku belum dikembalikan

        strcpy(rak_buku[indeksBuku][PROPERTI_BUKU-1], "TERSEDIA");
        jumlah_buku_tersedia = jumlah_buku_tersedia + 1;
    }

}

//PROSEDUR UNTUK MENAMPILKAN MENU MANAJEMEN PEMINJAMAN (MENU)
void tampilkanMenuPeminjaman(){
    bool selesai = false;
    int pilihan;

    do{
        tampilkanJejak("Beranda \\ Data Peminjaman");
        tampilkanDataPeminjaman(-1, "");
        printf("\nMenu Data Peminjaman\n");
        printf(" 0. Kembali\n");
        printf(" 1. Pencarian Data Peminjaman\n");
        printf(" 2. Pengurutan Data Peminjaman\n");
        printf(" 3. Penambahan Data Peminjaman\n");
        printf(" 4. Pengubahan Data Peminjaman\n");
        printf(" 5. Penghapusan Data Peminjaman\n");
        printf(" 6. Pengembalian Buku\n");
        printf("\n> Pilih Menu : ");

        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 0:
            system("cls");
            return;
            break;
        case 1:
            system("cls");
            cariDataPeminjaman();
            system("cls");
            break;
        case 2:
            system("cls");
            urutkanDataPeminjaman();
            system("cls");
            break;
        case 3:
            system("cls");
            tambahDataPeminjaman();
            system("cls");
            break;
        case 4:
            system("cls");
            ubahDataPeminjaman();
            system("cls");
            break;
        case 5:
            system("cls");
            hapusDataPeminjaman();
            system("cls");
            break;
        case 6:
            system("cls");
            kembalikanBuku();
            system("cls");
            break;
        default:
            system("cls");
            break;
        }

    }while(selesai == false);
}

//#[MANAJEMEN PEMINAJAMAN - END]#############################################################################################################





//#[FUNGSI UTAMA - START]####################################################################################################################

int main(){
    bool selesai = false;
    int pilihan;

    bikinDataDummy();

    system("cls");

    do{
        tampilkanJejak("Beranda");
        printf("Menu Beranda\n");
        printf(" 0. Akhiri Program\n");
        printf(" 1. Data Buku\n");
        printf(" 2. Data Peminjaman\n");
        printf("\n> Pilih Menu : ");

        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 0:
            selesai = true;
            printf("\n\n[PROGRAM BERAKHIR]\n\n\n");
            system("pause");
            break;
        case 1:
            system("cls");
            tampilkanMenuBuku();
            break;
        case 2:
            system("cls");
            tampilkanMenuPeminjaman();
            break;
        default:
            system("cls");
            break;
        }

    }while(selesai == false);

    return 0;

}

//#[FUNGSI UTAMA - END]######################################################################################################################