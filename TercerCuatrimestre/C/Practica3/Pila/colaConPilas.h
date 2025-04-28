#ifndef __COLA_CON_PILA_H__
#define __COLA_CON_PILA_H__
#include "pila.h"
#include "glist.h"
#include "stdio.h"

typedef struct _colaConPilas{
    Pila* pila1;
    Pila* pila2;
}colaConPilas;

colaConPilas* cola_con_pila_crear();
// Crea una cola con dos pilas
void cola_con_pila_destruir(colaConPilas* cola, FuncionDestructora d);
// Destruye la cola y libera la memoria
void cola_con_pila_encolar(colaConPilas* cola, void* dato, FuncionCopia c, FuncionDestructora d);
// Encola un elemento en la cola
void cola_con_pila_desencolar(colaConPilas* cola, FuncionDestructora d, FuncionCopia c);
// Desencola un elemento de la cola
void cola_con_pila_imprimir(colaConPilas* cola, FuncionVisitante v);
// Imprime los elementos de la cola
#endif