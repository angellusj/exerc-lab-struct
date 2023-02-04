#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main(void){
    int qnt_frutas;
    printf("Digite a quantidade de frutas: ");
    scanf("%d", &qnt_frutas);
    char ** frutas = (char**) malloc (qnt_frutas*sizeof(char*));
 
    if(frutas==NULL){
        printf("Erro!");
        exit(1);
    }
 
    int linha;
    for (linha=0;linha<qnt_frutas;linha++){
        frutas[linha]=(char*)malloc(50*sizeof(char));
    }
 
    float * preco = (float*) malloc(qnt_frutas*sizeof(float));
    if(preco==NULL){
        printf("Erro!");
        exit(1);
    }
 
    for(linha=0;linha<qnt_frutas;linha++){
    getchar();
    printf("\nInforme o nome da fruta %d: ",linha+1);
    fgets(frutas[linha],50,stdin);
        // scanf("%[^\n]s", frutas[linha]);
    frutas[linha] = (char*) realloc(frutas[linha],strlen(frutas[linha])*sizeof(char));
    printf("Informe o preço da fruta %d: ",linha+1);
        scanf("%f", &preco[linha]);
    }
 
    for(linha=0;linha<qnt_frutas;linha++){
    printf("\nFruta: %sPreço: %.2f\n",frutas[linha],preco[linha]);
        free(frutas[linha]);
    }
 
    free(frutas); free(preco);
    return 0;
}
