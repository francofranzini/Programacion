#include "pila.h"
#include "stdio.h"
typedef struct _Tupla{
    int first;
    int second;
}Tupla;
void visit(Tupla* tupla){
    printf("(%i, %i)\n", tupla->first, tupla->second);
}
void destruir(Tupla* tupla){
    free(tupla);
}
Tupla* copia(Tupla* tupla){
    //Crear copia fisica de tupla
    Tupla* copia_tupla = malloc(sizeof(Tupla));
    copia_tupla->first = tupla->first;
    copia_tupla->second = tupla->second;
    return copia_tupla;
}
Pila* glist_revertir_con_pila(GList lista, FuncionCopia c){
    Pila* nueva_pila = pila_crear();
    while(lista != NULL){
        pila_apilar(nueva_pila, lista->data, c);
        lista = lista->next;
    }
    return nueva_pila;
}
int main(){

    Tupla* tupla1 = malloc(sizeof(Tupla));
    tupla1->first = 1; tupla1->second = 1;
    Tupla* tupla2 = malloc(sizeof(Tupla));
    tupla2->first = 4; tupla2->second = 5;
    
    //pila_apilar(pila_de_prueba, tupla1,(FuncionCopia) copia);
    //pila_apilar(pila_de_prueba, tupla2,(FuncionCopia) copia);
    
    
    
    GList lista1 = glist_crear();
    lista1 = glist_agregar_inicio(lista1, tupla1,(FuncionCopia) copia);
    lista1 = glist_agregar_inicio(lista1, tupla2, (FuncionCopia) copia);
    
    glist_recorrer(lista1,(FuncionVisitante) visit);
    puts("");
    
    Pila* pila_de_prueba;
    pila_de_prueba = glist_revertir_con_pila(lista1, (FuncionCopia) copia);

    pila_imprimir(pila_de_prueba,(FuncionVisitante) visit);
    
    glist_destruir(lista1, (FuncionDestructora) destruir);
    pila_destruir(pila_de_prueba, (FuncionDestructora) destruir);
    
    //free(pila_de_prueba);
    destruir(tupla1); destruir(tupla2);

    return 0;
}