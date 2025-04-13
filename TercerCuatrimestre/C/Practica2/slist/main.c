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
  SList listax = slist_crear();
  SList listay = slist_crear();

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
  SList lista_reversa = slist_reverso(lista);
  slist_recorrer(lista_ordenada, imprimir_entero);
  puts("");
  slist_recorrer(lista_ordenada_decreciente, imprimir_entero);
  puts("");
  slist_recorrer(lista_reversa, imprimir_entero);
 
  puts("");

  listax = slist_agregar_inicio(listax, 4);
  listax = slist_agregar_inicio(listax, 3);
  listax = slist_agregar_inicio(listax, 2);
  listax = slist_agregar_inicio(listax, 1);

  listay = slist_agregar_inicio(listay, 6);
  listay = slist_agregar_inicio(listay, 5);
  listay = slist_agregar_inicio(listay, 10);
  

  // puts("");
  SList lista_intercalada = slist_intercalar(listax, listay);
  slist_recorrer(lista_intercalada, imprimir_entero);
  puts("");


  

  return 0;
}
