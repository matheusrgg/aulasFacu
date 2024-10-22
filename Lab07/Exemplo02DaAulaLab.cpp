#include <stdio.h>
#include <locale.h>

float calcMedia(int n, float *pVetNotas){
	int i;
	float somatorio=0, media;
	for(i=0; i<n; i++){
		somatorio = somatorio + pVetNotas[i]; //*pode ser array
	}
	media = somatorio/n;
	return media;
}

int main(void){
	setlocale(LC_ALL, "Portugues");
	int n, i;
	printf("Digite o numero de alunos da sala:");
	scanf("%d", &n);
	
	float vetNotas[n];
	for(i=0; i<n;i++){
		printf("Nota aluno %d:", i+1);
		scanf("%f", &vetNotas[i]);
	}
	float media;
	media = calcMedia(n, vetNotas); //vetNotas sem & por ser array
	printf("A média dos %d alunos é %.1f.", n, media);
	return 0;
}
