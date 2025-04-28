#include "glist.h"
#include "cola.h"
#include <stdio.h>
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

int main(){
    Cola* tucola = cola_crear();
    Tupla* t1 = malloc(sizeof(Tupla));
    Tupla* t2 = malloc(sizeof(Tupla));
    t1->first = 1;
    t1->second = 2;
    t2->first = 4;
    t2->second = 5;
    encolar(tucola, t1,(FuncionCopia) copia);
    encolar(tucola, t2,(FuncionCopia) copia);
    encolar(tucola, t1, (FuncionCopia) copia);
    desencolar(tucola,(FuncionDestructora) destruir);
    cola_imprimir(tucola,(FuncionVisitante) visit);
    return 0;
}