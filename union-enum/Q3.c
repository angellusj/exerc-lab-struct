#include<stdio.h>

typedef enum mes{
	janeiro=1,
	fevereiro,
	marco,
	abril,
	maio,
	junho,
	julho,
	agosto,
	setembro,
	outubro,
	novembro,
	dezembro
}meses;

typedef struct data{
	int dia;
	int ano;
	meses mouth;
}Data; 

int main(){
	Data d;
	printf("Informe o dia: \n");
	scanf("%d", &d.dia);
	printf("Informe o ano: \n");
	scanf("%d", &d.ano);
	printf("Informe o mes(em número): \n");
	scanf("%d", &d.mouth);
	printf("%d/%d/%d", d.dia, d.mouth, d.ano);
    	
	return 0;
}
