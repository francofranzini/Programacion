#include "pila.h"
//#include "glist.h"

struct _Pila{
    GList lista;
    int ultimo;
};

Pila* pila_crear(){
    Pila* nueva_pila = malloc(sizeof(Pila));
    nueva_pila->lista = glist_crear();
    nueva_pila->ultimo = -1;
    return nueva_pila;
}

void pila_destruir(Pila* pila, FuncionDestructora d){
    glist_destruir(pila->lista, d);
    free(pila);
}
int pila_es_vacia(Pila* pila){
    return glist_vacia(pila->lista);
}
void* pila_tope(Pila* pila){
   return pila->lista->data;
}
void pila_apilar(Pila* pila, void* dato, FuncionCopia c){
   pila->lista = glist_agregar_inicio(pila->lista, dato, c);
}
void pila_desapilar(Pila* pila, FuncionDestructora d){
    pila->lista = glist_eliminar_inicio(pila->lista, d);
}
void pila_imprimir(Pila* pila, FuncionVisitante v){
    glist_recorrer(pila->lista, v);
}