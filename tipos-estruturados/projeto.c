#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 3
// 3 alunos no maximo
#define MAX_TURMAS 3
// 3 turmas no maximo

typedef struct aluno {
  int mat;
  char nome[81];
  float notas[3];
  float media;
} Aluno;

typedef struct turma {
  char *id;  /* caractere que identifica a turma, por exemplo, A ou B */
  int vagas; /* numero de vagas disponiveis para fechar a turma */
  Aluno *alunos[MAX_VAGAS];
} Turma;

Turma *turmas[MAX_TURMAS];


void obterNumero(long int *holder,size_t size){
  size = (!size) ? 100: size;
  char *b1 = (char*) malloc(sizeof(char)*size);
  char *ePTR;
  scanf(" %s",b1);
  *holder = strtol(b1, &ePTR, 10); // Para evitar bugs quando passado letras.
}

int turmaVazia(){
  return (turmas[0]->id!=NULL) ? 0 : 1;
}

Turma *procura_turma(char *id) {
  for (size_t i = 0; i < MAX_TURMAS; i++) {
    if (turmas[i]->id==NULL) break; // Evita acesso a turmas vazias.
    if (strcmp(turmas[i]->id, id) == 0) {      // Significa que sao iguais
      return turmas[i];
    }
  }
  printf("Turma inexistente.\n");
  return NULL;
}

void cria_turma() { // Prototipo sem tipo de escopo
  char *id = (char *)malloc(sizeof(char));
  printf("Criando nova turma... \n");
  printf("Digite um ID: ");
  scanf(" %s",id);
  for (size_t i = 0; i < MAX_TURMAS; i++) { // Procura turma livre
    if (turmas[i]->id==NULL) { // Turma encontrada
      turmas[i]->id = (char *)malloc(sizeof(char));
      turmas[i]->id = id; // Assimila id a turma vazia.
      turmas[i]->vagas = MAX_VAGAS; // Da valores padroes.
      for (size_t j = 0; j < MAX_VAGAS; j++)
        turmas[i]->alunos[j] = NULL; // NULL para todas as vagas
      printf("Turma %s criada com sucesso!\n", id);
      return;
    } else if(strcmp(turmas[i]->id,id)==0){
      printf("Esta turma jÃ¡ foi registrada.\n");
      return;
    }
  }
  printf("NÃ£o hÃ¡ mais espaÃ§o para novas turmas.\n");
}

void matricula_aluno() {
  char *id = (char *)malloc(sizeof(char));
  printf("Para realizar a matricula do aluno informe:\nID da turma: ");
  scanf(" %s", id);
  Turma *alvo = procura_turma(id);
  if (alvo==NULL)
    return;
  if (alvo->vagas <= 0){
    printf("Vagas totalmente preenchidas.\n");
    return;
  }
  for (size_t i = 0; i < MAX_VAGAS; i++) { // Procurar a primeira vaga
    if (alvo->alunos[i] == NULL) { // Vaga encontrada
      alvo->alunos[i] = malloc(sizeof(Aluno)); // Acolhe vaga, para preenche-la em seguinte
      while (alvo->alunos[i]->mat<=0){
        printf("NÃºmero da matricula: ");
        obterNumero((long int*)&alvo->alunos[i]->mat, 10);
      }
      getchar(); // por culpa do \n deixado pelo scanf, serve para pega-lo
      printf("Nome do aluno: ");
      fgets(alvo->alunos[i]->nome,81,stdin);
      --alvo->vagas;
      break;
    }
  }
  printf("Aluno matriculado com sucesso!\n");
  return;
}

void lanca_notas() {
  char *id = (char *)malloc(sizeof(char));
  printf("Lancando notas, aguarde...\n");
  printf("Informe o ID da turma: ");
  scanf(" %s", id);
  Turma *alvo = procura_turma(id);
  if (alvo==NULL) return;
  if (alvo->vagas==MAX_VAGAS){
    printf("Nenhum aluno matriculado nesta turma.\n");
    return;
  }
  for (size_t i = 0; i < MAX_VAGAS; i++){
    if (alvo->alunos[i]==NULL) return;
    printf("\nMatricula: %d \tAluno: %s\n", alvo->alunos[i]->mat, alvo->alunos[i]->nome);
    for (size_t j = 0; j < 3; j++){
      printf("Digite a nota %lu: ",j+1);
      scanf(" %f",&alvo->alunos[i]->notas[j]);
      alvo->alunos[i]->media+=alvo->alunos[i]->notas[j];
    }
    alvo->alunos[i]->media/=3;
  }
}

void imprime_alunos() {
  char *id = (char *)malloc(sizeof(char));
  printf("Listando alunos, aguarde...\n");
  printf("Informe o ID da turma: ");
  scanf(" %s", id);
  Turma * alvo = procura_turma(id);
  if (alvo == NULL) return;
  if (alvo->vagas==MAX_VAGAS){
    printf("Nenhum aluno matriculado nesta turma.\n");
    return;
  }
  for (size_t i = 0; i < MAX_VAGAS; i++){
    if (alvo->alunos[i]==NULL) break;
    printf("\nMatricula: %i \tNome: %s",alvo->alunos[i]->mat,alvo->alunos[i]->nome);
    printf("Media: %.2f\n",alvo->alunos[i]->media);
  }
}

void imprime_turmas() {
  printf("Listando turmas, aguarde...\n");
  for (size_t i = 0; i<MAX_TURMAS; i++){
    if (turmas[i]->id==NULL) return; // Parar de listar na primeira turma vazia.
    printf("Turma %s - %i vagas disponÃ­veis\n",turmas[i]->id,turmas[i]->vagas);
  }
}

int main (int argc, char *argv[])
{
  for (size_t i = 0; i < MAX_TURMAS; i++) {
    turmas[i] = (Turma*) malloc(sizeof(Turma));
    if (turmas[i]==NULL){
      printf("Erro, sem memÃ³ria suficiente.\n");
      return 1;
    }
  }
  size_t opt = 0;
  while (opt != 6) {
    printf("\nMENU:\n"
           "1 - Criar turma\n"
           "2 - Listar turmas\n"
           "3 - Matricular aluno\n"
           "4 - LanÃ§ar notas\n"
           "5 - Listar alunos\n"
           "6 - Sair\n\n");
    printf("Selecione uma opÃ§Ã£o: ");
    obterNumero((long int*)&opt, 3); printf("\n");
    if (opt>0 && opt<7){
      switch (opt) {
        case 1:
          cria_turma();
          break;
        case 2:
          (turmaVazia()==0) ? imprime_turmas() : printf("Turmas vazias.\n");
          break;
        case 3:
          (turmaVazia()==0) ? matricula_aluno() : printf("Turmas vazias.\n");
          break;
        case 4:
          (turmaVazia()==0) ? lanca_notas() : printf("Turmas vazias.\n");
          break;
        case 5:
          (turmaVazia()==0) ? imprime_alunos() : printf("Turmas vazias.\n");
          break;
        case 6:
          break;
      }
    } else {
      printf("Dite uma opÃ§Ã£o dentro das listadas.\n");
    }
  }
  printf("Saindo...\n");
  for (size_t i = 0; i < MAX_TURMAS; i++)
    turmas[0]=NULL;
  return 0;
}
