#include <stdio.h>

typedef struct Kata{
    int top;
    char data[100];
}kata;

int str_len(char str[]){
    //inisialisasi variabel count untuk menyimpan panjang string
    int count;
    //menambah nilai count sampai akhir string
    for(count = 0; str[count] != '\0'; ++count);
    //mengmbalikan jumlah karakter dalam string
    return count;
}

void isPelindrom(kata *normal){ 
    int p; 
    kata rotated;
    for(int i = 0; i <= normal->top; i++){
        rotated.data[i] = normal->data[normal->top - i];
        rotated.top++;
    }

    for(int i = 0; i <= normal->top; i++){
        if(normal->data[i] != rotated.data[i]){
            p = 0;
            break;
        } p = 1;
    }

    printf("Kata \"%s\" %s pelindrom.", 
            rotated.data,
            (p == 0) ? "bukanlah" : "merupakan");
}

int main(){
    kata n_word;
    printf("Sebutkan 1 kata buat hari ini : ");
    fflush(stdin); gets(n_word.data);
    n_word.top = str_len(n_word.data) - 1;
    printf("len %d\n", n_word.top);
    isPelindrom(&n_word);
}