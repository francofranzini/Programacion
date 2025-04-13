#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;
typedef int (*FuncionComparacion) (int dato1, int dato2);



typedef SNodo *SList;
SList slist_intersecar_2(SList lista1, SList lista2,FuncionComparacion visit);
SList slist_ordenar(SList lista, FuncionComparacion comparador);
int dato_segun_comparador(SList lista, FuncionComparacion comparador, int dato_inicial);
SList slist_intersecar(SList lista1, SList lista2);
SList slist_eliminar_elemento(SList lista, int elemento);
SList slist_reverso_aux(SList actual, SList ultimo);
SList slist_reverso(SList lista);
SList slist_intercalar(SList lista1, SList lista2);
/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

SList slist_partir2(SList lista);

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);
int slist_contiene2(SList lista, int dato, FuncionComparacion visit);
/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

#endif /* __SLIST_H__ */
