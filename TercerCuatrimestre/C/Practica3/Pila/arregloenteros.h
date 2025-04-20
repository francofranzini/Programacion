#ifndef __ENTEROS_H__
#define __ENTEROS_H__



typedef struct ArregloEnteros_{
    int* direccion;
    int capacidad;
}ArregloEnteros;

ArregloEnteros* arreglo_enteros_crear(int capacidad);


void arreglo_enteros_destruir(ArregloEnteros* arreglo);

int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos);

void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato);

int arreglo_enteros_capacidad(ArregloEnteros* arreglo);

void arreglo_enteros_imprimir(ArregloEnteros* arreglo);

void arreglo_enteros_imprimir_reverso_desde(ArregloEnteros* arreglo, int inicio);
#endif