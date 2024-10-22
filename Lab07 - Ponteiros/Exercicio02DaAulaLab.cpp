#include <stdio.h>
#include <locale.h>
#include <string.h>

void maiuscular(char *pString){
	//declara a variável
	int tamStr,i;
	//pega o tamanho da string que o usuário vai digitar
	tamStr = strlen(pString);
	//vai loopar todos os caracteres da string
	for(i=0; i<tamStr; i++){
		//pega cada letra e faz algo aqui que não entendi
		//97 e 122 o que?
		printf("Isso é cada letra?", pString[i]);
		if(pString[i] >= 97 && pString[i] <= 122){
			pString[i] = pString[i] - 32;
		}
	}
	}
	int main(void){
		setlocale(LC_ALL, "Portugues");
		char string[51];
		printf("Digite uma string de até 50 caracteres: ");
		scanf("%50[^\n]", string);
		maiuscular(string);
		puts(string);
		return 0;
	}

