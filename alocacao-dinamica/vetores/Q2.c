#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QNT_ALUNOS 10


int main(void) {
  int qnt_questoes;
  printf("Quantas questões serão? ");
  scanf(" %i", &qnt_questoes);
  char *gabarito = (char *)malloc(sizeof(char) * qnt_questoes);
 
  // gabarito
  for (size_t i = 0; i < qnt_questoes; i++) {
    getchar();
    printf("\nGabarito da questão %lu: ", i + 1);
    fgets(&gabarito[i], 2, stdin);
  }
  
  return 0;
}
