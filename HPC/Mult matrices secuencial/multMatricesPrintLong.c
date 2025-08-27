#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

// Función para generar una matriz cuadrada con números enteros aleatorios
void generarMatriz(long **matriz, int n, int limite)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      matriz[i][j] = rand() % limite; // limitar valores
}

// Función para imprimir una matriz cuadrada
void imprimirMatriz(long **matriz, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      printf("%15ld\t", matriz[i][j]);
    printf("\n");
  }
}

// Función para multiplicar dos matrices cuadradas
void multiplicarMatrices(long **A, long **B, long **C, int n)
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

  // Calcular límite seguro para evitar overflow en 32 bits
  long limite = (long)sqrt(INT_MAX / n);
  if (limite <= 0)
    limite = 1;

  printf("Valores aleatorios entre 0 y %ld para evitar overflow.\n\n", limite - 1);

  // Reservar memoria para las matrices
  long **A = (long **)malloc(n * sizeof(long *));
  long **B = (long **)malloc(n * sizeof(long *));
  long **C = (long **)malloc(n * sizeof(long *));
  for (int i = 0; i < n; i++)
  {
    A[i] = (long *)malloc(n * sizeof(long));
    B[i] = (long *)malloc(n * sizeof(long));
    C[i] = (long *)malloc(n * sizeof(long));
  }

  // Generar y mostrar matrices
  generarMatriz(A, n, limite);
  generarMatriz(B, n, limite);

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
