#include <stdio.h>

struct LinkedList {
	int data1;
	char data2;
	struct LinkedList* link;
};

int main()
{
	struct LinkedList l1, l2;

	l1.link = NULL;
	l1.data1 = 10;
    l1.data2 = 20;

	l2.link = NULL;
	l2.data1 = 30;
	l2.data2 = 40;

	// Linking L1 dan L2
	l1.link = &l2;

	// Mengkakses data member l2 menggunakan l1
	printf("%d", l1.link->data1);
	printf("\n%d", l1.link->data2);
	return 0;
}