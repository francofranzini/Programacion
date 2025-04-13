#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}
int es_igual(int dato1, int dato2){
  return (dato1 == dato2);
}
int menor_que(int dato1, int dato2){
  return (dato1 <= dato2);
}
int mayor_que(int dato1, int dato2){
  return (dato1 >= dato2);
}
int main(int argc, char *argv[]) {

  SList lista = slist_crear();
  SList lista2 = slist_crear();

  lista = slist_agregar_inicio(lista, 1);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_final(lista, 5);
  lista = slist_agregar_final(lista, 4);
  lista = slist_agregar_final(lista, 7);
  lista = slist_agregar_final(lista, 6);
  
  slist_recorrer(lista, imprimir_entero);
  SList lista_ordenada_decreciente = slist_ordenar(lista, mayor_que);
  SList lista_ordenada = slist_ordenar(lista, menor_que); 
  puts("");
  
  slist_recorrer(lista_ordenada, imprimir_entero);
  puts("");
  slist_recorrer(lista_ordenada_decreciente, imprimir_entero);



  lista2 = slist_agregar_inicio(lista2, 3);
  lista2 = slist_agregar_inicio(lista2, 2);
  lista2 = slist_agregar_inicio(lista2, 1);
  lista2 = slist_agregar_inicio(lista2, 10);
  
  puts("");
  //SList lista_interseccion = slist_intersecar_2(lista, lista2, es_igual);
  
  

  puts("");
  //SList mitad = slist_partir2(lista);
  //printf("%p", mitad);
  //slist_recorrer(mitad, imprimir_entero);
  //slist_destruir(lista);

  return 0;
}
