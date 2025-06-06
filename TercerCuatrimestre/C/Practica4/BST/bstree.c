#include "bstree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Estructura del nodo del arbol de busqueda binaria.
 * Tiene un puntero al dato (dato),
 * un puntero al nodo raiz del subarbol izquierdo (izq),
 * y un puntero al nodo raiz del subarbol derecho (der).
 */
struct _BST_Nodo {
  void *dato;
  struct _BST_Nodo *izq, *der;
};

/**
 * bstee_crear: Retorna un arbol de busqueda binaria vacio
 */
BSTree bstree_crear() { return NULL; }

/**
 * bstree_destruir: Destruye el arbol y sus datos
 */
void bstree_destruir(BSTree raiz, FuncionDestructora destr) {
  if (raiz != NULL) {
    bstree_destruir(raiz->izq, destr);
    bstree_destruir(raiz->der, destr);
    destr(raiz->dato);
    free(raiz);
  }
};

/**
 * bstree_buscar: Retorna 1 si el dato se encuentra y 0 en caso
 * contrario
 */
int bstree_buscar(BSTree raiz, void *dato, FuncionComparadora comp) {
  if (raiz == NULL)
    return 0;
  else if (comp(dato, raiz->dato) == 0) // raiz->dato == dato
    return 1;
  else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    return bstree_buscar(raiz->izq, dato, comp);
  else // raiz->dato < dato
    return bstree_buscar(raiz->der, dato, comp);
}

/**
 * bstree_insertar: Inserta un dato no repetido en el arbol, manteniendo la
 * propiedad del arbol de busqueda binaria
 */
BSTree bstree_insertar(BSTree raiz, void *dato, FuncionCopiadora copia,
                       FuncionComparadora comp) {
  if (raiz == NULL) { // insertar el dato en un nuevo nodo
    struct _BST_Nodo *nuevoNodo = malloc(sizeof(struct _BST_Nodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = copia(dato);
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
  } else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    raiz->izq = bstree_insertar(raiz->izq, dato, copia, comp);
  else if (comp(dato, raiz->dato) > 0) // raiz->dato < dato
    raiz->der = bstree_insertar(raiz->der, dato, copia, comp);
  // si el dato ya se encontraba, no es insertado
  return raiz;
}

/**
 * bstree_recorrer: Recorrido DSF del arbol
 */
void bstree_recorrer(BSTree raiz, BSTreeRecorrido orden,
                     FuncionVisitanteExtra visita, void *extra) {
  if (raiz != NULL) {
    if (orden == BTREE_RECORRIDO_PRE)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->izq, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_IN)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->der, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_POST)
      visita(raiz->dato, extra);
  }
}
/*
  Devuelve la cantidad de nodos en un arbol
*/
int bstree_nnodos(BSTree raiz){
  if(raiz == NULL) return 0;
  return 1 + bstree_nnodos(raiz->izq) + bstree_nnodos(raiz->der);
}
void* bstree_k_esimo_menor_aux(BSTree raiz, int* k){
  if(raiz == NULL) return NULL;

  void* dato;
  dato = bstree_k_esimo_menor_aux(raiz->izq, k);
  if(dato != NULL) return dato;

  if(*k == 0) return raiz->dato;

  (*k)--;
  return bstree_k_esimo_menor_aux(raiz->der, k);
}
void* bstree_k_esimo_menor(BSTree raiz, int k){
  return bstree_k_esimo_menor_aux(raiz, &k);
  
}
/*
  Retorna la altura del arbol
*/
//10, 20, 15, 25, 30, 16, 18, 19
/*
      10
        \
          20
        /   \
       15    25
         \     \
          16    30
            \
             18
               \
                19

SACAR EL 20 DEL ARBOL
10
        \
            1
        /       \
       15        25
         \         \
          16        30
            \       /
             18   27
*/
BSTree bstree_menor(BSTree arbol){
  if(arbol == NULL) return NULL;
  if(arbol->izq == NULL){
    return arbol;
  }
  else{
    bstree_menor(arbol->izq);
  }
}
void destruccionSimbolica(void* dato){
  (void)dato;
}


BSTree bstree_eliminar(BSTree arbol, void *dato,FuncionComparadora c, FuncionDestructora d){
  if(arbol == NULL) return NULL;
  int comp = c(arbol->dato, dato);
  if(comp > 0) arbol->izq = bstree_eliminar(arbol->izq, dato, c, d);
  if(comp < 0) arbol->der = bstree_eliminar(arbol->der, dato, c, d);
  if(comp == 0){
    //ES UNA HOJA
    if(arbol->der == NULL && arbol->izq == NULL){
      d(arbol->dato);
      free(arbol);
      return NULL;
    }
    //SOLO SUBARBOL DERECHO
    if(arbol->izq == NULL && arbol->der != NULL){
      BSTree aux = arbol->der;
      d(arbol->dato);
      free(arbol);
      return aux;
    } 
    //SOLO SUBARBOL IZQUIERDO
    if(arbol->der == NULL && arbol->izq != NULL){
      BSTree aux = arbol->izq;
      d(arbol->dato);
      free(arbol);
      return aux;
    }
    //  DOS SUBARBOLES :(  Necesitamos buscar el menor nodo del subarbol derecho
    //  y ponerlo en la raiz

    //Menor nodo del subarbol derecho (sin hijo izquierdo)
    BSTree aux = bstree_menor(arbol->der);
    d(arbol->dato);
    arbol->dato = aux->dato; // copia simbolica
    arbol->der = bstree_eliminar(arbol->der, aux->dato, c, destruccionSimbolica);
    /*
      Como sabemos que en la primer "busqueda" encontramos el menor del subarbol derecho, dicho nodo no tiene subarbol
      izquierdo, entonces solo entrara al caso de "DOS SUBARBOLES", a lo sumo, una vez. La llamada recursiva llegara a
      "SOLO SUBARBOL DERECHO" o a "ES UNA HOJA".
    */
  }
  kreturn arbol;
}
int es_bst_util(BSTree nodo, void* min, void* max, FuncionComparadora c) {
    if (nodo == NULL) return 1;

    // Siempre que voy al subarbol izquierdo, actualizo el maximo
    // si voy al subarbol derecho, acutalizo el minimo
    if ((min && c(nodo->dato, min) <= 0) || (max && c(nodo->dato, max) >= 0))
        return 0;

    // Revisa recursivamente subárboles
    return es_bst_util(nodo->izq, min, nodo->dato, c) &&
           es_bst_util(nodo->der, nodo->dato, max, c);
}

int es_bst(BSTree raiz, FuncionComparadora c) {
    return es_bst_util(raiz, NULL, NULL, c);
}
