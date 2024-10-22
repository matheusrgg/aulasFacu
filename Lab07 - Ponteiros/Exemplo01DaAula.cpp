#include <stdio.h>

int main(void){
	int a;
	int *p;
	a =5;
	p = &a;
	*p = 6;
	printf("%d", a);
	return 0;
}
