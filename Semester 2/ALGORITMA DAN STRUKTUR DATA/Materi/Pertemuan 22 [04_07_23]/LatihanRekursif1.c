#include <stdio.h>

int pawah(int x, int n){
	if(n == 0) return 1;
	return x * pawah(x, n-1);
}

void main(){
	int x, n;
	printf("Input [X N] : ");
	scanf("%d %d", &x, &n);
	printf("X pangkat N : %d", pawah(x, n));
}