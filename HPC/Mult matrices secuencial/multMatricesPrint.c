#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar una matriz cuadrada con números enteros aleatorios
void generarMatriz(int **matriz, int n)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      matriz[i][j] = rand();
}

// Función para imprimir una matriz cuadrada
void imprimirMatriz(int **matriz, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      printf("%20d\t", matriz[i][j]);
    printf("\n");
  }
}

// Función para multiplicar dos matrices cuadradas
void multiplicarMatrices(int **A, int **B, int **C, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      C[i][j] = 0;
      for (int k = 0; k < n; k++)
        C[i][j] += A[i][k] * B[k][j];
    }
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Uso: %s <tamano_matriz>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  if (n <= 0)
  {
    printf("El tamaño debe ser un entero positivo.\n");
    return 1;
  }

  // Inicializar la semilla para números aleatorios
  srand(time(NULL));

  // Reservar memoria para las matrices
  int **A = (int **)malloc(n * sizeof(int *));
  int **B = (int **)malloc(n * sizeof(int *));
  int **C = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    A[i] = (int *)malloc(n * sizeof(int));
    B[i] = (int *)malloc(n * sizeof(int));
    C[i] = (int *)malloc(n * sizeof(int));
  }

  // Generar y mostrar matrices
  generarMatriz(A, n);
  generarMatriz(B, n);

  printf("Matriz A:\n");
  imprimirMatriz(A, n);
  printf("\nMatriz B:\n");
  imprimirMatriz(B, n);

  // Multiplicar
  multiplicarMatrices(A, B, C, n);

  printf("\nResultado de A x B:\n");
  imprimirMatriz(C, n);

  // Liberar memoria
  for (int i = 0; i < n; i++)
  {
    free(A[i]);
    free(B[i]);
    free(C[i]);
  }
  free(A);
  free(B);
  free(C);

  return 0;
}
