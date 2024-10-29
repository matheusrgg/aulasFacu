#include <stdio.h>

struct ponto{
	char nome;
	int x,y;
};

void dobraPontos(int n, struct ponto *p){
	int i;
	for(i=0; i<n;i++){
		p[i].x = p[i].x*2;
		p[i].y = p[i].y*2;
	}
}

int main(void){
	struct ponto xy[3] = {
	{'A',10,20},
	{'B',11,22},
	{'C',12,25},
	};
	dobraPontos(3,xy);
	int i;
	for(i=0; i<3; i++){
		printf("Ponto %c(%d,%d)\n", xy[i].nome, xy[i].x, xy[i].y);
	}
	return 0;
	
}
