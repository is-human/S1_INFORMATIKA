#include <stdio.h>

void hanoi(int piringan, char dari, char bantu, char ke){
    if(piringan>0){
        hanoi(piringan-1, dari, ke, bantu);
        printf("Pindahkan piringan %d dari %c ke %c\n", piringan, dari, ke);
        hanoi(piringan-1, bantu, dari, ke);
    }
}

void main(){
    int piringan;
    printf("banyak priringan: ");
    scanf("%d", &piringan);
    hanoi(piringan, 'A', 'B', 'C');
}