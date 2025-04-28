#ifndef __COLA_H__
#define __COLA_H__

typedef struct _Cola Cola;
#include <stdlib.h>
Cola* cola_crear();
void encolar(Cola* cola, void* dato, FuncionCopia c);
void desencolar(Cola* cola, FuncionDestructora c);
void esVacia(Cola* cola);
void cola_imprimir(Cola* cola, FuncionVisitante v);

/*
    Implementaria cola con una lista doblemente enlazada, un puntero al final y un puntero al inicio
    
*/
#endif /* __COLA_H__ */
