#include "pila.h"
#include "glist.h"

struct _Pila{
    GList lista;
    int ultimo;
};

Pila* pila_crear(int size){
    Pila* nueva_pila = malloc(sizeof(Pila));
    nueva_pila->lista = glist_crear();
    nueva_pila->ultimo = -1;
    return nueva_pila;
}
/*
// 
// 
//      COMO TRABAJO CON GLIST
//      SIN MODIFICAR PILA.H
//      SIENDO QUE NECESITO FUNCIONES PARA CADA OPERACION
// 
//      1) SON OPERACIONES ASOCIADAS AL CREAR PILA?
//      2) NO SE ME OCURRIO OTRA
// 
// 
// 
*/












/*
void pila_destruir(Pila* pila, FuncionDestructora d){
    glist_destruir(pila->lista, d);
}
int pila_es_vacia(Pila* pila){
    return glist_vacia(pila);
}
int pila_tope(Pila* pila, FuncionVisitante v){
   if(!pila_es_vacia(pila)) v(pila->lista);
}
void pila_apilar(Pila* pila, int dato){

}

*/