#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
    int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    int curr_p, curr_s, next_p, next_s;
    triangle tmp;

    for(int h = 0; h < n-1; h++){
        for(int i = 0; i < n-h-1; i++){

            curr_p = (tr[i].a + tr[i].b + tr[i].c) * 0.5;
            curr_s = sqrt(curr_p * (curr_p - tr[i].a) * (curr_p - tr[i].b) * (curr_p - tr[i].c));

            next_p = (tr[i+1].a + tr[i+1].b + tr[i+1].c) * 0.5;
            next_s = sqrt(next_p * (next_p - tr[i+1].a) * (next_p - tr[i+1].b) * (next_p - tr[i+1].c));
            
            if(next_s < curr_s){
                tmp = tr[i];
                tr[i] = tr[i+1];
                tr[i+1] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    triangle tr[n];
    for(int i = 0; i < n; i++){
        scanf(" %d %d %d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);

    return 0;
}