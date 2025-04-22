#ifndef __PILA_H__
#define __PILA_H__

#include <stdlib.h>
#include "glist.h"
typedef struct _Pila Pila;

Pila* pila_crear();

void pila_destruir(Pila* pila, FuncionDestructora d);

int pila_es_vacia(Pila* pila);

int pila_tope(Pila* pila, FuncionVisitante v);

void pila_apilar(Pila* pila, void* dato, FuncionCopia c);

void pila_desapilar(Pila* pila);

void pila_imprimir(Pila* pila, FuncionVisitante v);



#endif 
