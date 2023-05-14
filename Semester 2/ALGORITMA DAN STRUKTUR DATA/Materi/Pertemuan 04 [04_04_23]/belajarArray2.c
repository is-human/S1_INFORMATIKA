#include <stdio.h>

int main(){
    char arr[] = "nama saya joko widodo, presiden indonesia ke-6 menang dua periode";
    int arrLen = sizeof(arr)/sizeof(char), kata = 0, spasi = 0;
    printf("%d", arrLen);
    for(int a = 0; a < arrLen; a++){
        if(arr[a] == ' ') {
            kata++;
            spasi++;
        }
    }
    printf("\n%d dan %d", kata+1, arrLen-spasi);
}