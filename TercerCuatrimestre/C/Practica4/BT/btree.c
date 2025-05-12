#include "btree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _BTNodo {
  int dato;
  struct _BTNodo *left;
  struct _BTNodo *right;
};

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo) { return nodo == NULL; }

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitanteInt visit) {
  /** COMPLETAR */
  if(arbol == NULL) return;
  if(orden == BTREE_RECORRIDO_POST){
    btree_recorrer(arbol->left, orden, visit);
    btree_recorrer(arbol->right, orden, visit);
    visit(arbol->dato);
  }
  if(orden == BTREE_RECORRIDO_IN){
    btree_recorrer(arbol->left, orden, visit);
    visit(arbol->dato);
    btree_recorrer(arbol->right, orden, visit);
  }
  if(orden == BTREE_RECORRIDO_PRE){
    visit(arbol->dato);
    btree_recorrer(arbol->left, orden, visit);
    btree_recorrer(arbol->right, orden, visit);
  }
    // R, izq, der
    /*
        R
      /   \
    izq   der
    */


  //assert(0);
  return;
}
void btree_recorrer_it(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteInt visit, FuncionCopia c, FuncionDestructora d){
  if(arbol == NULL) return;
  visit(arbol->dato);
  Pila* nodos = pila_crear();
  pila_apilar(nodos, arbol->right, c);
  pila_apilar(nodos, arbol->left, c);
  while(!pila_es_vacia(nodos)){
    BTree nodo = pila_tope(nodos);
    pila_desapilar(nodos, d);
    if(nodo != NULL){
      visit(nodo->dato);
      pila_apilar(nodos, nodo->right,(FuncionCopia) c);
      pila_apilar(nodos, nodo->left,(FuncionCopia) c);
    }
  }
}
int btree_nnodos(BTree arbol){
  if(btree_empty(arbol)) return 0;
  return 1 + btree_nnodos(arbol->left) + btree_nnodos(arbol->right);
}
int btree_buscar(BTree arbol, int dato){
  if(btree_empty(arbol)) return 0;
  if(arbol->dato == dato) return 1;
  return btree_buscar(arbol->left) || btree_buscar(arbol->right);
}
BTree btree_copiar(BTree arbol){
  if(btree_empty(arbol)) return NULL;
  else{
    BTree nuevo_nodo = btree_crear();
    nuevo_nodo->dato = arbol->dato;
    nuevo_nodo->left = btree_copiar(arbol->left);
    nuevo_nodo->right = btree_copiar(arbol->right);
    return nuevo_nodo;
  }
}
