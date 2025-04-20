#include "pila.h"

int main(){

    Pila* pila_de_prueba = pila_crear(10);
    pila_apilar(pila_de_prueba, 500);
    pila_apilar(pila_de_prueba, 700);

    pila_tope(pila_de_prueba); //--> 700

    pila_desapilar(pila_de_prueba);
    pila_apilar(pila_de_prueba, 600);

    pila_imprimir(pila_de_prueba);
    pila_destruir(pila_de_prueba);


    return 0;
}