#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *arq;
	arq = fopen("03Escrita_fgetc.txt", "rb");
	
	if(arq == NULL){
		printf("Erro na abertura do arquivop. \n");
		exit(1);
	}
	
	char c;
	int i;
	
	for(i=0; i<5;i++){
		c = fgetc(arq);
		printf("%c", c);
		
	}
	
	fclose(arq);
	return 0;
}
