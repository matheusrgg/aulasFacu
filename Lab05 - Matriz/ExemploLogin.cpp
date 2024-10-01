
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

int main(void){
	char login[15]="admin", loginDig[15];
	char senha[15]="1234", senhaDig[15];
	int erro;
	do{
		system("cls");
		erro=0;
		printf("login");
		fflush(stdin);
		scanf("%14[^\n]", loginDig);
		if(strcmp(login, loginDig)!=0){
			printf("Login errado.");
			erro++;
			sleep(1);
		}
		else{
			printf("Senha:");
			fflush(stdin);
			scanf("%14[^\n]", senhaDig);
			if(strcmp(senha,senhaDig)!=0){
				printf("Senha errada.");
				erro++;
				sleep(1);
			}
		}
	}while(erro!=0);
	puts("user logado");
	return 0;
}
