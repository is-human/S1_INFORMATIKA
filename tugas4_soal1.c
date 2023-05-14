//memanggil header file stdio.h untuk akses fungsi standar input dan output
#include <stdio.h>
//membuat stack atau struct bernama alias menara dengan member yaitu alias, top, cincin
typedef struct Menara{
    char alias;
    int top;
    int cincin[100];
}menara;

//mengambil element paling baru/atas/akhir dari stack
int pop(menara *stack){
    int cincin = stack->cincin[stack->top];
    stack->top--;
    return cincin;
}
//fungsi utama yang pertama kali akan dieksekusi program
int main(){
    //deklarasi 3 stack menara
    menara tiang[3];
    //deklarasi variabel pembantu
    int tot_cincin, cincin;
    //memberi huruf sebagai alias siap menara
    tiang[0].alias = 'S';
    tiang[1].alias = 'A';
    tiang[2].alias = 'D';
    //menset nilai top dari tiap menara
    tiang[0].top = -1;
    tiang[1].top = -1;
    tiang[2].top = -1;
    //meminta user memasukkan nilai jumlah cincin
    printf("Masukkan Jumlah Cincin: ");
    scanf("%d", &tot_cincin);
    //memasukkan cincin ke menara 'S' dari yang paling besar ke kecil
    for (int i = 0; i < tot_cincin; i++){
        //push
        tiang[0].cincin[i] = tot_cincin - i;
        tiang[0].top++;
    }
    //melakukan 2 kali perulangan untuk perpindahan cincin dari tiang 'S' ke 'A' dan 'A' ke 'D'
    for(int i = 0; i < 2; i++){
        //memindahkan tiap cincin dari tiang 1 ke tiang sebelahnya secara berurutan dari atas kebawah
        for (int j = 0; j < tot_cincin; j++){
            cincin = pop(&tiang[i]);
            tiang[i+1].cincin[j] = cincin;
            tiang[i+1].top++;
            printf("Memindahkan cicin dim %d dari '%c' ke '%c'.\n", cincin, tiang[i].alias, tiang[i+1].alias);
        }
        
    }
    //selesai 👍
    return 0;
}
