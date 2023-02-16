#include<stdio.h>

typedef enum genero{
	feminino=1, 
	masculino
}gender;

typedef struct pessoa{
	char nome[50];
	int idade;
	gender gen;
}Pessoa;

int main(){
	Pessoa p;
	printf("Informe seu nome: \n");
	scanf(" %[^\n]", p.nome);
	printf("Informe sua idade: \n");
	scanf("%d", &p.idade);
	printf("Informe seu genero: \n");
	printf("Opções:\n1-Feminino\n2-Masculino");
	scanf("%d", &p.gen);
	printf("Informações da pessoa:\nNome: %s \nIdade: %d\n", p.nome, p.idade);
		switch(p.gen){
			case feminino:
				printf("%d - Genero Feminino\n", p.gen);
				break;
			case masculino:
				printf("%d - Genero Masculino\n", p.gen);
				break;
			default:
			printf("Outro genero.\n");	
		}
	
	return 0;
}
