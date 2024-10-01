#include <stdio.h>

int main(void){
	
	char nome1[10]="Ana Maria";
	char nome2[10];
	int i;
	
	for(i=0; nome1[i] !='\0'; i++){
		nome2[i]= nome1[i];
	}
	
	nome2[i]= '\0';
	return 0;
}
