#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QNT_ALUNOS 3

// To do list

float puxarNota(char *resposta, char *gabarito, float qnt_questoes) {
  float nota;
  // printf("%s\n%s\n", resposta, gabarito);
  for (size_t i = 0; i < qnt_questoes; i++)
    nota = (resposta[i] == gabarito[i]) ? nota + (10 / qnt_questoes) : nota;
  // printf("%.2f\n", nota);
  return nota;
}

void coletarRespostas(char *resposta, int qnt_questoes) {
  for (size_t i = 0; i < qnt_questoes; i++) {
    getchar();
    printf("\nQual é a alternativa correta da questão nº%lu? ", i + 1);
    fgets(&resposta[i], 2, stdin);
  }
}

int main(void) {
  int qnt_questoes;
  size_t i;
  printf("Quantas questões serão? ");
  scanf(" %i", &qnt_questoes);
  char *gabarito = (char *)malloc(sizeof(char) * qnt_questoes);
  char **respostas = (char **)malloc(sizeof(char *) * QNT_ALUNOS);
  // gabarito
  for (i = 0; i < qnt_questoes; i++) {
    getchar();
    printf("\nGabarito da questão %lu: ", i + 1);
    fgets(&gabarito[i], 2, stdin);
  }
  for (i = 0; i < QNT_ALUNOS; i++) {
    respostas[i] =
        (char *)malloc(sizeof(char) * qnt_questoes); // aproveitar e alocar né
    printf("\nRespostas do aluno %lu:", i + 1);
    coletarRespostas(respostas[i], qnt_questoes);
  }
  // debug
  for (i = 0; i < QNT_ALUNOS; i++) {
    printf("\nNota do aluno %lu: %.2f\n", i + 1,
           puxarNota(respostas[i], gabarito, (float)qnt_questoes));
  }
  return 0;
}
