#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	FILE * arq;
	arq = fopen("02Escrita_fputc.txt", "wb");
	
	if(arq == NULL){
		printf("Erro na arbetura do arquivo. \n");
		exit(1);
	}
	
	char string[100];
	printf("Entre com a string a ser gravada no arquivo:");
	scanf("%99[^\n]", string);
	
	//Grava a string, caractere a caractere
	int i;
	for(i=0; i<strlen(string);i++){
			 fputc(string[i],arq);
	}
	fclose(arq);
	return 0;
}
