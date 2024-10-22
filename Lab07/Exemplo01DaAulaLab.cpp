#include <stdio.h>
#include <math.h>
#include <locale.h>
#define PI 3.141592655359

void calcVolumeArea(double vRaio, double *pVolume, double *pArea){
	*pVolume = (4.0/3.0) *PI* pow(vRaio,3);
	*pArea = 4 *PI* pow(vRaio,2);
}

int main(void){
	setlocale(LC_ALL, "Portugues");
	double raio,volume, area;
	printf("Digite o raio da esfera, em cm:");
	scanf("%lf", &raio);
	calcVolumeArea(raio, &volume, &area);
	printf("Volume: %lf cm3 \n¡rea: %lfcm2", volume, area);
	return 0;
}
