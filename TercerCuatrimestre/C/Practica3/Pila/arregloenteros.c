#include "arregloenteros.h"

#include <stdlib.h>
#include <stdio.h>
ArregloEnteros* arreglo_enteros_crear(int capacidad){
    ArregloEnteros* nuevo_arreglo = malloc(sizeof(ArregloEnteros));
    nuevo_arreglo->capacidad = capacidad;
    nuevo_arreglo->direccion = malloc(sizeof(int)*capacidad);
    return nuevo_arreglo;
}
void arreglo_enteros_destruir(ArregloEnteros* arreglo){
    free(arreglo->direccion);
    free(arreglo);
}
int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos){
    printf("%i\n", arreglo->direccion[pos]);
}
void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato){
    arreglo->direccion[pos] = dato;
}
int arreglo_enteros_capacidad(ArregloEnteros* arreglo){
    return arreglo->capacidad;
}
void arreglo_enteros_imprimir(ArregloEnteros* arreglo){
    for(int i = 0; i<arreglo->capacidad; i++) printf("%i\n", arreglo->direccion[i]);
}
void arreglo_enteros_imprimir_reverso_desde(ArregloEnteros* arreglo, int inicio){
    for (int i = inicio; i>= 0; i--){
        printf("%i\n", arreglo->direccion[i]);
    }
}
