#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

void destruir_nodo(BTree t){
  return;
}
static void imprimir_entero(int data) {
  printf("%d ", data);
}
BTree copiar_nodo(BTree t){
  return t;
}

int main() {
  BTree ll = btree_unir(1, btree_crear(), btree_crear());
  BTree l = btree_unir(2, ll, btree_crear());
  BTree r = btree_unir(3, btree_crear(), btree_crear());
  BTree raiz = btree_unir(4, l, r);
  /*         4
           /   \
         2       3
       /  \     /  \
      1   NULL NULL NULL
    /   \
  NULL NULL
  */
  btree_recorrer_bfs(raiz, (FuncionVisitanteInt) imprimir_entero);
  
  
  btree_destruir(raiz);
  return 0;
}
