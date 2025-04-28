#include "colaConPilas.h"

colaConPilas* cola_con_pila_crear(){
    colaConPilas* nueva_cola = malloc(sizeof(colaConPilas));
    nueva_cola->pila1 = pila_crear();
    nueva_cola->pila2 = pila_crear();
    return nueva_cola;
}
void cola_con_pila_destruir(colaConPilas* cola, FuncionDestructora d){
    pila_destruir(cola->pila1, d);
    pila_destruir(cola->pila2, d);
    free(cola);
}
void cola_con_pila_encolar(colaConPilas* cola, void* dato, FuncionCopia c, FuncionDestructora d){
    pila_apilar(cola->pila1, dato,c);
}
void cola_con_pila_desencolar(colaConPilas* cola, FuncionDestructora d, FuncionCopia c){
    if(pila_es_vacia(cola->pila2)){
        while(!pila_es_vacia(cola->pila1)){
            pila_apilar(cola->pila2,pila_tope(cola->pila1), c);
            pila_desapilar(cola->pila1, d);
        }
    }
    pila_desapilar(cola->pila2, d);
}
void cola_con_pila_imprimir(colaConPilas* cola, FuncionVisitante v){
    pila_imprimir(cola->pila1, v);
}