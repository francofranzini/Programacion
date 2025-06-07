#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"

// Copia de un entero
void* copiar_entero(void* a){
    int* copia = malloc(sizeof(int));
    *copia = *(int*)a;
    return copia;
}


// Comparador para enteros
int comparar_enteros(void* a, void* b) {
    int ia = *(int*)a;
    int ib = *(int*)b;
    return ia - ib;
}

// Visitante para imprimir enteros
void imprimir_entero(void* a) {
    printf("%d ", *(int*)a);
}

void test_bheap_crear_y_vacio() {
    BHeap h = bheap_crear(10, comparar_enteros);
    assert(h != NULL);
    assert(bheap_es_vacio(h));
    bheap_destruir(h);
    printf("test_bheap_crear_y_vacio OK\n");
}

void test_bheap_insertar_y_recorrer() {
    BHeap h = bheap_crear(10, comparar_enteros);
    int a = 10, b = 20, c = 15, d=25, e=30, f= 16, g= 18, i = 19;
    bheap_insertar(h, &a);
    bheap_insertar(h, &b);
    bheap_insertar(h, &c);
    bheap_insertar(h, &d);
    bheap_insertar(h, &e);
    bheap_insertar(h, &f);
    bheap_insertar(h, &g);
    bheap_insertar(h, &i);

    assert(!bheap_es_vacio(h));
    
    printf("Elementos en el heap: ");
    bheap_recorrer(h, imprimir_entero);
    printf("\n");
    printf("Eliminamos 30: \n");
    bheap_eliminar(h);
    bheap_recorrer(h, imprimir_entero);
    printf("\n");
    bheap_destruir(h);

    printf("test_bheap_insertar_y_recorrer OK\n");
    
    }

void test_bheap_desde_array() {
    int** arr = malloc(sizeof(int*)*6);
    int a = 10, b = 20, c = 5, d = 6, e = 1, f = 15;
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;
    arr[3] = &d;
    arr[4] = &e;
    arr[5] = &f;
    BHeap h = bheap_crear_desde_arr((void**)arr, 6, copiar_entero, comparar_enteros);
    assert(!bheap_es_vacio(h));
    printf("Elementos en el heap desde array: ");
    bheap_recorrer(h, imprimir_entero);
    printf("\n");
    bheap_destruir(h);
    /*
    // Add assertions to verify the heap 
    int array2[] = {10, 20, 5, 6, 1};
    BHeap h2 = bheap_crear_desde_arr((void**)array2, 5, NULL, comparar_enteros);
    assert(!bheap_es_vacio(h2));
    printf("Elementos en el heap desde segundo array: ");
    bheap_recorrer(h2, imprimir_entero);
    printf("\n");
    bheap_destruir(h2);
    // Add assertions to verify the heap structure

    int array3[] = {7, 8, 9, 10};
    BHeap h3 = bheap_crear_desde_arr((void**)array3, 4, NULL, comparar_enteros);
    assert(!bheap_es_vacio(h3));
    printf("Elementos en el heap desde tercer array: ");
    bheap_recorrer(h3, imprimir_entero);
    printf("\n");
    bheap_destruir(h3);
    // Add assertions to verify the heap structure
    */
    printf("All tests passed!\n");
}
int main() {
    test_bheap_crear_y_vacio();
    test_bheap_insertar_y_recorrer();
    test_bheap_desde_array();
    // Puedes agregar más pruebas aquí
    return 0;
}