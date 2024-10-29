#include<stdio.h>
#include<locale.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_PRODUTOS 100
#define MAX_VENDAS 100



typedef struct{ // Para salvar produtos
    char nome[50];
    float preco_kg_ou_unidade;
    int tipo_venda;
    float estoque; 
} Produto;	

typedef struct{ // Para salvar as vendas
    char nome_produto[50];
    float quantidade;
    float preco_total;
} Venda;

Produto produtos[MAX_PRODUTOS]; // Contador de produtos e vendas
Venda vendas[MAX_VENDAS];
int total_produtos = 10;
int total_vendas = 0;


void ProdutosCadastrados(){
    strcpy(produtos[0].nome, "banana");
    produtos[0].preco_kg_ou_unidade = 4.50;
    produtos[0].tipo_venda = 1; // Vendido por peso
    produtos[0].estoque = 100;  // Estoque inicial

    strcpy(produtos[1].nome, "maca");
    produtos[1].preco_kg_ou_unidade = 7.50;
    produtos[1].tipo_venda = 1; 
    produtos[1].estoque = 100;   

    strcpy(produtos[2].nome, "laranja");
    produtos[2].preco_kg_ou_unidade = 6.00;
    produtos[2].tipo_venda = 1; 
    produtos[2].estoque = 100;   

    strcpy(produtos[3].nome, "tomate");
    produtos[3].preco_kg_ou_unidade = 2.75;
    produtos[3].tipo_venda = 1; 
    produtos[3].estoque = 100;   

    strcpy(produtos[4].nome, "brocolis");
    produtos[4].preco_kg_ou_unidade = 10.80;
    produtos[4].tipo_venda = 1; 
    produtos[4].estoque = 100;  

    strcpy(produtos[5].nome, "alface");
    produtos[5].preco_kg_ou_unidade = 1.50;
    produtos[5].tipo_venda = 0; // Vendido por unidade
    produtos[5].estoque = 100;  // Estoque inicial

    strcpy(produtos[6].nome, "cenoura");
    produtos[6].preco_kg_ou_unidade = 1.20;
    produtos[6].tipo_venda = 0; 
    produtos[6].estoque = 100;  

    strcpy(produtos[7].nome, "abacate");
    produtos[7].preco_kg_ou_unidade = 4.10;
    produtos[7].tipo_venda = 0; 
    produtos[7].estoque = 100;  

    strcpy(produtos[8].nome, "cebola");
    produtos[8].preco_kg_ou_unidade = 1.50;
    produtos[8].tipo_venda = 0; 
    produtos[8].estoque = 100;  

    strcpy(produtos[9].nome, "abobrinha");
    produtos[9].preco_kg_ou_unidade = 2.20;
    produtos[9].tipo_venda = 0; 
    produtos[9].estoque = 60;   
}


void CadastroProduto(){ //Função para a opção de cadastrar produtos
    Produto novo_produto;
    printf("Digite o nome do novo produto: ");
    scanf("%s", novo_produto.nome);
    printf("Digite o preço em R$ do quilo ou da unidade do produto: ");
    scanf("%f", &novo_produto.preco_kg_ou_unidade);
    printf("O produto é vendido por unidade (0) ou por peso (1)? ");
    scanf("%d", &novo_produto.tipo_venda);
    printf("Digite a quantidade em estoque: ");
    scanf("%f", &novo_produto.estoque); // Solicita o valor de estoque

    produtos[total_produtos] = novo_produto; // Salva o novo produto e avança para o próximo local disponível na memória
    total_produtos++;
    printf("Produto cadastrado com sucesso!\n\n");
    Sleep(2000);
    system("cls");
}

void Vender(){
    char nome_produto[50];
    float quantidade, preco_total;
    int encontrado = 0;
    int i;

    printf("Digite o nome do produto a ser vendido: ");
    scanf("%s", nome_produto);

    for (i = 0; i < total_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0) {
            encontrado = 1;

            printf("Estoque disponível: %.2f\n", produtos[i].estoque);
            if (produtos[i].tipo_venda == 1) { // Por peso
                printf("Digite a quantidade (em kg): ");
                scanf("%f", &quantidade);
            } else { // Por unidade
                printf("Digite a quantidade (em unidades): ");
                scanf("%f", &quantidade);
            }

            if (quantidade > produtos[i].estoque){
                system("cls");
                printf("\t\t----------Quantidade insuficiente no estoque!----------\n");
                Sleep(2000);
                system("cls");
            } else {
                preco_total = produtos[i].preco_kg_ou_unidade * quantidade;
                printf("Valor total: R$%.2f\n", preco_total);
                Sleep(2000);
                system("cls");

                // Atualiza o estoque após a venda
                produtos[i].estoque -= quantidade; //-= é uma forma abreviada de escrever  produtos[i].estoque = produtos[i].estoque - quantidade

                // Salva a transação em um espaço de memória e avança para o próximo disponível
                strcpy(vendas[total_vendas].nome_produto, nome_produto);
                vendas[total_vendas].quantidade = quantidade;
                vendas[total_vendas].preco_total = preco_total;
                total_vendas++;
            }
            break;
        }
    }

    if (!encontrado){
        printf("Produto não encontrado!\n");
    }
}

void ExibirHistorico(){
    float lucro_total = 0.0;
    int i;  

    printf("\n--- Histórico de Vendas ---\n");
    for (i = 0; i < total_vendas; i++){
        printf("Produto: %s | Quantidade: %.2f | Valor: R$%.2f\n", vendas[i].nome_produto, vendas[i].quantidade, vendas[i].preco_total);
        lucro_total += vendas[i].preco_total; // Soma o valor total de cada venda
    }
    printf("\nTotal vendido: R$%.2f\n\n\n", lucro_total);
    system("pause");
    getchar();
    system("cls");
}



void SistemaGerente(){
	int opcao;
    ProdutosCadastrados();
    do{
        printf("\n--- Sistema de Vendas Hortifruti ---\n\n");
        printf("[1]- Cadastro de produtos\n");
        printf("[2]- Vender\n");
        printf("[3]- Relatório de vendas\n");
        printf("[4]- Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                system("cls");
                CadastroProduto();
                break;

            case 2:
                system("cls");
                Vender();
                break;

            case 3:
                system("cls");
                ExibirHistorico();
                break;

            case 4:
                system("cls");
                printf("Até logo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);
}

void SistemaConvidado(){
	int opcao;
    ProdutosCadastrados();
    do {
        printf("\n--- Sistema de Vendas Hortifruti ---\n\n");
        printf("[1]- Vender\n");
        printf("[2]- Relatório de vendas\n");
        printf("[3]- Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao){

            case 1:
                system("cls");
                Vender();
                break;

            case 2:
                system("cls");
                ExibirHistorico();
                break;

            case 3:
                system("cls");
                printf("Até logo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);
}



int main(void){
	
	char opcao_login;
	char user[10] = "admin", userDig[10];
	char senha[20] = "admin123", senhaDig[20];
	int ok;
	setlocale(LC_ALL,"portuguese");
	
	
	
	do{
	printf("\t\t-------Bem Vindo!-------\n\n\n\n");
	printf("[1]Login Gerente\t\t\t[2]Modo convidado\n\n");
	scanf("%c",&opcao_login);
	 getchar();
	 system("cls");
}while(opcao_login!='1'&& opcao_login!='2');


switch(opcao_login){
	case'1':
		printf("Login: ");
            scanf("%9s", userDig);

            printf("Senha: ");
            scanf("%19s", senhaDig); 
            ok = (strcmp(userDig, user) == 0) && (strcmp(senhaDig, senha) == 0);
            
            if(ok) {
                system("cls"); 
                printf("\t\t----------------Login realizado com sucesso!!----------------\n");
                sleep(2); 
                system("cls");
                SistemaGerente();
            } else {
                printf("Login incorreto!\n");
            }
            
            
            
            
            break; 
            
            
	
	case '2':
            printf("\t\t----------------Obs: Essa opção possui limitações!----------------\n\n\n");
            sleep(2); 
            system("cls");
            SistemaConvidado();
            
            
            
            break;

        
    }

    return 0;
}
