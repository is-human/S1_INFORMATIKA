#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
    int s;
};

typedef struct triangle triangle;

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    triangle tmp;
    for(int i = 0; i < n; i++){
        tr[i].s = (tr[i].a + tr[i].b) * 0.5;
    }

    for(int h = 0; h < n-1; h++){
        for(int i = 0; i < n-h-1; i++){
            if(tr[i+1].s > tr[i].s){
                tmp = tr[i];
                tr[i] = tr[i+1];
                tr[i+1] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d %d = %d\n", tr[i].a, tr[i].b, tr[i].s);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    triangle tr[n];
    for(int i = 0; i < n; i++){
        scanf(" %d %d", &tr[i].a, &tr[i].b);
    }
    sort_by_area(tr, n);

    return 0;
}