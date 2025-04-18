#include "matriz.h"

/*
** Implementacion utilizando un arreglo bidimensional (arreglo de punteros a arreglo)
*/

struct Matriz_ {

  int filas;
  int columnas;
  double** datos;

};


Matriz* matriz_crear(size_t numFilas, size_t numColumnas) {
  Matriz* matriz_nueva = malloc(sizeof(Matriz));
  matriz_nueva->filas = numFilas;
  matriz_nueva->columnas = numColumnas;
  matriz_nueva->datos = malloc(sizeof(double*)*numFilas);
  for (int i = 0; i<numFilas; i++){
    matriz_nueva->datos[i] = malloc(sizeof(double)*numColumnas);
  }
  return matriz_nueva;
}

void matriz_destruir(Matriz* matriz) {
  if(matriz == NULL) return;
  for (int i = 0; i < matriz->filas; i++){
    for(int j = 0; j<matriz->columnas; j++) free(matriz->datos[i][j]);
    free(matriz->datos[i]);
  }
}

double matriz_leer(Matriz* matriz, size_t fil, size_t col) {
  if(matriz == NULL) return 0;
  matriz->datos[fil][col];
}

void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val) {
  if(matriz == NULL) return;
  matriz->datos[fil][col] = val;
}

size_t matriz_num_filas(Matriz* matriz) {
  return matriz->filas;
}

size_t matriz_num_columnas(Matriz* matriz) {
  return matriz->columnas;
}


