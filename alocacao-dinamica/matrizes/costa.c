#include <stdio.h>
#include <stdlib.h>

void imprima(char **matriz, int m, int n) {
  int i, j;
  for (i = 0; i < m; i++) {
    printf("\n");
    for (j = 0; j < n; j++)
      printf("%c ", matriz[i][j]);
  }
  printf("\n");
}

int verificaTerra(char x) { return (x == '\0' || x == '.') ? 1 : 0; }
// 1 == água
// 0 == terra

int retornaCosta(char **matriz, int m, int n) {
  int costas = 0, i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (verificaTerra(matriz[i][j]) == 1) // Se for água ele não questiona
        continue;
      if (i == 0 || i == m - 1) { // Para evitar seg fault
        costas++; // Considera costa
        continue;
      }
      if (verificaTerra(matriz[i][j + 1]) == 1 ||
          verificaTerra(matriz[i][j - 1]) == 1 ||
          verificaTerra(matriz[i + 1][j]) == 1 ||
          verificaTerra(matriz[i - 1][j]) == 1) {
        costas++; // na teoria, se qualquer lado for água, é costa.
      }
    }
  }
  return costas;
}

int main(void) {
  int M, N;
  int i, j;
  printf("Defina as linhas: \n");
  scanf(" %d", &M);
  printf("Defina as colunas: \n");
  scanf(" %d", &N);
  char **matriz = (char **)malloc(M * sizeof(char *));
  if (matriz == NULL) {
    printf("ERRO!");
    exit(1);
  }
  for (i = 0; i < M; i++) {
    matriz[i] = (char *)malloc(N * sizeof(char));
  }
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      scanf(" %c", &matriz[i][j]);
    }
  }
  imprima(matriz, M, N);
  printf("Quantidade de costas: %i\n", retornaCosta(matriz, M, N));
  for (i = 0; i < M; i++) {
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}
