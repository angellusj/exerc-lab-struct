nclude <stdio.h>
#include <stdlib.h>
 
void printMatrix(int** Matrix, size_t tam);
 
int main (int argc, char *argv[])
{
  size_t i,j;
  int** mat = (int**) malloc(3*sizeof(int*));
  for (i = 0; i < 3; i++) {
    mat[i] = (int*) malloc(3*sizeof(int));
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      mat[i][j] = i*3 + j;
    }
  }
  printMatrix(mat, 3);
  free(mat);
  return 0;
}
 
void printMatrix(int** Matrix, size_t tam){
  size_t i, j;
  for (i = 0; i < tam; i++) {
    for (j = 0; j < tam; j++) {
      printf("%i ",Matrix[i][j]);
    }
    printf("\n");
  }
}
