#ifndef __BTREE_H__
#define __BTREE_H__

typedef void (*FuncionVisitanteInt)(int dato);
typedef void (*FuncionVisitanteExtra) (int dato, void *extra);
#include "../../Practica3/Pila/pila.h"
typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_PRE_IT,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _BTNodo *BTree;

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear();

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo);

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo);

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right);

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitanteInt visit);

void btree_recorrer_it(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteInt visit, FuncionCopia c, FuncionDestructora d);

/*
  Retorna la cantidad de nodos del arbol
*/
int btree_nnodos(BTree arbol);

/*
  Retorna 1 si dato esta en el arbol, 0 si no
*/
int btree_buscar(BTree arbol, int dato);


/*
  Retorna una copia fisica del arbol
*/
BTree btree_copiar(BTree arbol);


/*
  Retorna la altura del arbol
*/
int btree_altura(BTree arbol);

/*
  Retorna la cantidad de nodos a profundidad k
*/
int btree_nnodos_profundidad(BTree arbol, int k);

/*
  Retorna la profundidad del nodo que contiene dato
*/
int btree_profundidad_aux(BTree arbol, int dato, int k);
int btree_profundidad(BTree arbol, int dato);

/*
  Retorna la suma de los nodos de un BTree
*/
int btree_sumar(BTree arbol);
/*
  Recorre el arbol con parametro extra
*/
void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteExtra visita, void* extra);

/*
  Devuelve la suma de los nodos de un arbol usando el acumulador
*/
int suma_extra(BTree arbol);
void sumador(BTree arbol, int* k);

/*
  Devuelve max(a,b)
*/
int max(int a, int b);

void btree_recorrer_bfs(BTree arbol, FuncionVisitanteInt visit);

#endif /* __BTREE_H__ */
