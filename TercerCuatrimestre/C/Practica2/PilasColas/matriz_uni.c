#include "matriz.h"

/*
** Implmentacion utilizando un unico arreglo unidimensional
*/

struct Matriz_ {

  int filas;
  int columnas;
  double* datos;

};


Matriz* matriz_crear(size_t numFilas, size_t numColumnas) {
  Matriz* nueva_matriz = malloc(sizeof(Matriz));
  nueva_matriz->filas = numFilas;
  nueva_matriz->columnas = numColumnas;
  nueva_matriz->datos = malloc(sizeof(double) * (numFilas*numColumnas));

  return nueva_matriz;
}

void matriz_destruir(Matriz* matriz) {
  if(matriz == NULL) return;
  for (int i = 0; i< matriz->filas*matriz->columnas; i++) free(matriz->datos[i]);
  free(matriz->datos);
}

double matriz_leer(Matriz* matriz, size_t fil, size_t col) {
  return matriz->datos[(fil-1)*matriz->columnas + col-1];
}

void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val) {
  matriz->datos[(fil-1)*matriz->columnas + (col-1)] = val;
}

size_t matriz_num_filas(Matriz* matriz) {
  return matriz->filas;
}

size_t matriz_num_columnas(Matriz* matriz) {
  return matriz->columnas;
}
