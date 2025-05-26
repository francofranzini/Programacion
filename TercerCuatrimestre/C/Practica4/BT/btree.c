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
int max(int a, int b){
  return (a > b ? a : b);
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
  return btree_buscar(arbol->left, dato) || btree_buscar(arbol->right, dato);
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
int btree_altura(BTree arbol){
  if(btree_empty(arbol)) return -1;
  else return 1 + max(btree_altura(arbol->left), btree_altura(arbol->right));
}
int btree_nnodos_profundidad(BTree arbol, int k){
  if(btree_empty(arbol)) return 0;
  if(k == 0) return 1;
  else return btree_nnodos_profundidad(arbol->left, k-1) + btree_nnodos_profundidad(arbol->right, k-1);
}

/*
  Retorna la profundidad de un nodo en un arbol o -1 si no pertenece
*/
int btree_profundidad_aux(BTree arbol, int dato, int k){
  if(arbol == NULL) return -1;
  if(arbol->dato == dato) return k;
  if(dato > arbol->dato) btree_profundidad_aux(arbol->right, dato, k+1);
  else btree_profundidad_aux(arbol->left, dato, k+1);
}
int btree_profundidad(BTree arbol, int dato){
  return btree_profundidad_aux(arbol, dato, 0);
}
/*
  Retorna la suma de los nodos de un BTree
*/
int btree_sumar(BTree arbol){
  if(btree_empty(arbol)) return 0;
  return arbol->dato + btree_sumar(arbol->right) + btree_sumar(arbol->left);
}
void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteExtra visita, void* extra){
  if(btree_empty(arbol)) return;
  if(orden == BTREE_RECORRIDO_PRE){
    visita(arbol->dato, extra);
  }
  btree_recorrer_extra(arbol->left, orden, visita, extra);
  if(orden == BTREE_RECORRIDO_IN){
    visita(arbol->dato, extra);
  }
  btree_recorrer_extra(arbol->right, orden, visita, extra);
  if(orden == BTREE_RECORRIDO_POST){
    visita(arbol->dato, extra);
  }
}
void sumador(BTree arbol, int* k){
  (*k) += arbol->dato;
}
int suma_extra(BTree arbol){
  int k = 0;
  btree_recorrer_extra(arbol, BTREE_RECORRIDO_IN,(FuncionVisitanteExtra) sumador,&k);
  return k;
}

void imprimir_nodos_prof(BTree arbol, FuncionVisitanteInt visit, int profundidad, int* nodos){
  if(arbol == NULL) return;
  if(profundidad == 0){
    visit(arbol->dato);
    (*nodos) = 1;
  }
  else{
    imprimir_nodos_prof(arbol->left, visit, profundidad-1, nodos);
    imprimir_nodos_prof(arbol->right, visit, profundidad-1, nodos);
  }
}

void btree_recorrer_bfs(BTree arbol, FuncionVisitanteInt visit){
  int i = 0;
  int nodos = 1;
  while(nodos){
    nodos = 0;
    imprimir_nodos_prof(arbol, visit, i, &nodos);
    i++;
  }
  printf("\n");
  
}
