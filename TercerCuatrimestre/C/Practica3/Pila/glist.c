#include "glist.h"
#include <assert.h>
#include <stdlib.h>

/**
 * Devuelve una lista vacía.
 */
GList glist_crear() { return NULL; }

/**
 * Destruccion de la lista.
 * destroy es una función que libera el dato almacenado.
 */
void glist_destruir(GList list, FuncionDestructora destroy) {
  GNode *nodeToDelete;
  while (list != NULL) {
    nodeToDelete = list;
    list = list->next;
    destroy(nodeToDelete->data);
    free(nodeToDelete);
  }
  free(list);
}

/**
 * Determina si la lista es vacía.
 */
int glist_vacia(GList list) { return (list == NULL); }

/*
 * Predicado sobre los elementos de GList
 */


/**
 * Agrega un elemento al inicio de la lista.
 * copy es una función que retorna una copia física del dato.
 */
GList glist_agregar_inicio(GList list, void *data, FuncionCopia copy) {
  GNode *newNode = malloc(sizeof(GNode));
  assert(newNode != NULL);
  newNode->next = list;
  newNode->data = copy(data);
  return newNode;
}


/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void glist_recorrer(GList list, FuncionVisitante visit) {
  for (GNode *node = list; node != NULL; node = node->next)
    visit(node->data);
}

GList glist_filtrar(GList lista, FuncionCopia c, Predicado p){
  if(glist_vacia(lista)) return NULL;
  if(p(lista->data)){
    GNode* nuevo_nodo = malloc(sizeof(GNode));
    nuevo_nodo->data = c(lista->data);
    nuevo_nodo->next = glist_filtrar(lista->next, c, p);
    return nuevo_nodo;
  }
  glist_filtrar(lista->next, c, p);
}
SGList sglist_crear(){return NULL;}
void sglist_destruir(SGList lista, FuncionDestructora d){
  while(lista!=NULL){
    GNode* nodo_destruir;
    nodo_destruir = lista;
    lista = lista->next;
    d(nodo_destruir->data);
    free(nodo_destruir);
  }
}

int sglist_vacia(SGList lista){
  return lista == NULL;
}

void sglist_recorrer(GList lista, FuncionVisitante visit){
  while(lista!=NULL){
    visit(lista->data);
    lista = lista->next;
  }
}

SGList sglist_insertar(SGList lista, void* dato, FuncionCopia c, FuncionComparadora comparadora){
  if(lista == NULL) return NULL;
  if(comparadora(dato, lista->data)){
    GNode* nuevo_nodo = malloc(sizeof(GNode));
    nuevo_nodo->data = c(dato);
    nuevo_nodo->next = lista;
    return nuevo_nodo;
  }
  lista->next = sglist_insertar(lista->next, dato,c,comparadora);
  return lista;
}

int sglist_buscar(SGList lista, void* dato, FuncionComparadora c){
  //c(x, y) = 1 si x > y
  //c(x, y) = 0 si x = y
  //c(x, y) = -1 si x < y
  if(lista == NULL) return 0;
  int x = c(lista->data, dato);
  if(x > 0) return 0; //Se paso
  if(x == 0) return 1;
  sglist_buscar(lista->next, dato, c);
}

GList glist_eliminar_inicio(GList lista, FuncionDestructora d){
  if(lista == NULL ) return NULL;
  GNode* sig = lista->next;
  d(lista->data);
  free(lista);
  return sig;
}
