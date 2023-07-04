#include <stdio.h>

void hello(int count, int max){
	if(count == max) return;
	printf("Hello World! %d\n", count);
	return hello(count+1, max);
}

void main(){
	hello(1, 10);
}