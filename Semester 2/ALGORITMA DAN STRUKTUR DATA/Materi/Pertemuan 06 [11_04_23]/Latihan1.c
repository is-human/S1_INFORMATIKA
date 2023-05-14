#include <stdio.h>



void tampil(int *arr, int arrLen){
    for(int i = 0; i < arrLen; i++){
        printf("%d\n", *(arr+i));
    }
}

int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arrLen = sizeof(arr)/sizeof(int);
    tampil(arr, arrLen);
}