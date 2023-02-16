#include<stdio.h>

typedef union tipo{
	char alimento[70];
	char bebida[70];
	char eletronico[70];
}Tipo;

typedef struct produto{
	char nome[70];
	float preco;
	Tipo type;
}Produto; 

int main(){
	Produto p;
	printf("Informe o nome do produto desejado: \n");
	scanf(" %[^\n]", p.nome);
	printf("Informe o preço do produto desejado: \n");
	scanf("%f", &p.preco);
	printf("Informe o tipo de produto desejado: \n");
	scanf(" %[^\n]", p.type.alimento);
	
	printf("Pedido realizado:\nNome: %s \nPreço: %.2f\nTipo: %s", p.nome, p.preco, p.type.alimento);
	
	return 0;
}
