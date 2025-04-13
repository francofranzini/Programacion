#include "slist.h"
#include <stdlib.h>

SList slist_crear() {
  return NULL;
}

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

int slist_longitud(SList lista){
  if(lista == NULL) return 0;
  return 1 + slist_longitud(lista->sig);
}

SList slist_concatenar(SList lista1, SList lista2){
  if(lista1 == NULL) return lista2;
  lista1->sig = slist_concatenar(lista1->sig, lista2);
  return lista1;
}
SList slist_insertar(SList lista, int dato, int pos){
  if(lista == NULL){
    SNodo* nuevo_nodo = malloc(sizeof(SNodo));
    nuevo_nodo->dato = dato;
    nuevo_nodo->sig = NULL;
    return nuevo_nodo;
  }
  if(pos == 0){
    SNodo* nuevo_nodo = malloc(sizeof(SNodo));
    nuevo_nodo->dato = dato;
    nuevo_nodo->sig = lista->sig;
    lista->sig = nuevo_nodo;
    return lista;
  }
  
  lista->sig = slist_insertar(lista->sig, dato, --pos);
  
  return lista;
}
SList slist_eliminar(SList lista, int pos){
  if(lista == NULL) return NULL;
  
  if(pos == 0){
    if(lista->sig == NULL) return NULL;
    else return lista->sig;
  }
  
  lista->sig = slist_eliminar(lista, --pos);
  return lista;
}
SList slist_partir(SList lista){
  SNodo* segunda_mitad = lista->sig;
  int longitud = slist_longitud(lista);
  for(int i = 0; i<longitud/2;i++) lista = lista->sig;
  lista->sig = NULL;
  return segunda_mitad;
}
SList slist_partir2(SList lista){
  if(lista == NULL) return NULL;
  SNodo* segunda_mitad = lista;
  int i = 0;
  for(SNodo* it = lista; it->sig != NULL; it = it->sig->sig){
      segunda_mitad = segunda_mitad->sig;
    }
  return segunda_mitad;
}

int slist_contiene(SList lista, int dato){
  if(lista == NULL) return 0;
  if(lista->dato == dato) return 1;

  return slist_contiene(lista->sig, dato);
}

int slist_contiene2(SList lista, int dato, FuncionComparacion visit){
  if(lista == NULL) return 0;
  if(visit(lista->dato, dato)) return 1;
  return slist_contiene2(lista->sig, dato, visit);
}
int slist_indice(SList lista, int dato){
  if(lista == NULL) return 0;
  if(lista->dato == dato) return 0;
  int indice = 1 + slist_indice(lista->sig, dato);
  if(indice == slist_longitud(lista)) return -1;
  return indice;    
}
SList slist_intersecar(SList lista1, SList lista2){
  if(lista2 == NULL || lista1 == NULL) return NULL;
  if(slist_contiene(lista2, lista1->dato) == 1){
    SNodo* nodo_interseccion = malloc(sizeof(SNodo));
    nodo_interseccion->dato = lista1->dato;
    nodo_interseccion->sig = slist_intersecar(lista1->sig, lista2);
    return nodo_interseccion;
}

  return slist_intersecar(lista1->sig, lista2);
}

SList slist_intersecar_2(SList lista1, SList lista2,FuncionComparacion visit){
  if(lista2 == NULL || lista1 == NULL) return NULL;
  if(slist_contiene2(lista2, lista1->dato, visit)){
    SNodo* nodo_interseccion = malloc(sizeof(SNodo));
    nodo_interseccion->dato = lista1->dato;
    nodo_interseccion->sig = slist_intersecar_2(lista1->sig, lista2, visit);
    return nodo_interseccion;
}

  return slist_intersecar_2(lista1->sig, lista2, visit);
}
int dato_segun_comparador(SList lista, FuncionComparacion comparador, int dato_inicial){
  if(lista == NULL) return dato_inicial;
  if(comparador(lista->dato, dato_inicial)) dato_inicial = lista->dato;
  return dato_segun_comparador(lista->sig, comparador, dato_inicial);
}
SList slist_eliminar_elemento(SList lista, int elemento){
  if(lista == NULL) return NULL;
  if(lista->dato == elemento){
    return lista->sig;
  }
  lista->sig = slist_eliminar_elemento(lista->sig, elemento);
  return lista;
}
SList slist_ordenar_aux(SList lista, FuncionComparacion comparador){
  if(lista == NULL) return NULL;
  SNodo* nuevo_nodo = malloc(sizeof(SNodo));
  nuevo_nodo->dato = dato_segun_comparador(lista, comparador, lista->dato);
  SList lista_sin = slist_eliminar_elemento(lista, nuevo_nodo->dato);
  nuevo_nodo->sig = slist_ordenar(lista_sin, comparador);

  return nuevo_nodo;
}
SList slist_duplicar(SList lista){
  if(lista == NULL) return NULL;
  SNodo* lista_nueva = malloc(sizeof(SNodo));
  lista_nueva->dato = lista->dato;
  lista_nueva->sig = slist_duplicar(lista->sig);
  return lista_nueva;
}
SList slist_ordenar(SList lista, FuncionComparacion comparador){
  if(lista == NULL) return NULL;
  SList lista_nueva = slist_duplicar(lista);
  
  SList lista_ordenada = slist_ordenar_aux(lista_nueva, comparador);
  return lista_ordenada;
}