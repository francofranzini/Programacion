#include <stdio.h>
#include "colaConPilas.h" // Include the header file for colaConPilas


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

int main() {
    // Initialize the queue
    colaConPilas *cola = cola_con_pila_crear();

    // Create some Tuplas to test
    Tupla t1 = {1, 2};
    Tupla t2 = {3, 4};
    Tupla t3 = {5, 6};

    // Enqueue Tuplas into the queue
    cola_con_pila_encolar(cola, &t1, (FuncionCopia) copia, (FuncionDestructora) destruir);
    cola_con_pila_encolar(cola, &t2, (FuncionCopia) copia, (FuncionDestructora) destruir);
    cola_con_pila_encolar(cola, &t3, (FuncionCopia) copia, (FuncionDestructora) destruir);

    cola_con_pila_imprimir(cola, (FuncionVisitante) visit);
    puts("");
    cola_con_pila_desencolar(cola, (FuncionDestructora) destruir, (FuncionCopia)copia);
    
    cola_con_pila_imprimir(cola, (FuncionVisitante) visit);
    cola_con_pila_desencolar(cola, (FuncionDestructora) destruir, (FuncionCopia)copia);
    puts("");
    cola_con_pila_imprimir(cola, (FuncionVisitante) visit);
    puts("");
    cola_con_pila_destruir(cola, destruir);
    

    return 0;
}