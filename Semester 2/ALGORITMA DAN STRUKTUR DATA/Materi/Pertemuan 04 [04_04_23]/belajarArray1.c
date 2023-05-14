#include <stdio.h>

int main(){
    char arr[3][10] = {"Hallo", "Sigit", "Rendang"};
    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 10; b++){
            if(arr[a][b] != 'o'){
                printf("%c ", arr[a][b]);
            }
        }
        printf("\n");
    }
    // printf("Hallo");
}