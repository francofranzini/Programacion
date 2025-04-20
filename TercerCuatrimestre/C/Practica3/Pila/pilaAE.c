#include "pila.h"
#include "arregloenteros.h"

struct _Pila{
    ArregloEnteros* arr;
    int ultimo;
};


Pila* pila_crear(int size){
    Pila* nueva_pila = malloc(sizeof(Pila));
    nueva_pila->arr = arreglo_enteros_crear(size);
    nueva_pila->ultimo = -1;
    return nueva_pila;
}

void pila_destruir(Pila* pila){
    arreglo_enteros_destruir(pila->arr);
    free(pila);
}

int pila_es_vacia(Pila* pila){
    return (pila->ultimo == -1);
}

int pila_tope(Pila* pila){
    return arreglo_enteros_leer(pila->arr, pila->ultimo);
}

void pila_apilar(Pila* pila, int dato){
    if(pila->ultimo < arreglo_enteros_capacidad(pila->arr)){
        arreglo_enteros_escribir(pila->arr, pila->ultimo + 1, dato);
        pila->ultimo++;
    }
}
void pila_desapilar(Pila* pila){
    if(pila->ultimo >= 0) pila->ultimo--;
}
void pila_imprimir(Pila* pila){
    for(int i = pila->ultimo; i>= 0; i--){
        arreglo_enteros_imprimir_reverso_desde(pila->arr, pila->ultimo);
    }
}
