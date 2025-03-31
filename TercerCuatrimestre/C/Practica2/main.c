#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(int argc, char *argv[]) {

  SList lista = slist_crear();

  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 1);
  lista = slist_agregar_final(lista, 4);
  lista = slist_agregar_final(lista, 5);
  lista = slist_agregar_final(lista, 6);
  lista = slist_agregar_final(lista, 7);

  slist_recorrer(lista, imprimir_entero);
  puts("");
  SList mitad = slist_partir2(lista);
  //printf("%p", mitad);
  slist_recorrer(mitad, imprimir_entero);
  //slist_destruir(lista);

  return 0;
}
