#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

BHeap bheap_crear(int capacidad, FuncionComparadora c){
    BHeap nuevo_heap = malloc(sizeof(BHeap));
    nuevo_heap->arr = malloc(sizeof(void* )*capacidad+1);
    nuevo_heap->capacidad = capacidad;
    nuevo_heap->ultimo = 0;
    nuevo_heap->comp = c;
    return nuevo_heap;
}

void bheap_destruir(BHeap heap){
    free(heap->arr);
    free(heap);
}

int bheap_es_vacio(BHeap heap){
    return heap->ultimo == 0;
}

void bheap_recorrer(BHeap bheap, FuncionVisitante v){
    if(!bheap_es_vacio(bheap)){
        for(int i = 1; i<=bheap->ultimo; i++){
            v(bheap->arr[i]);
        }
    }
}
void bheap_insertar(BHeap bheap, void* dato){
    //Insertamos al final del heap
    if(bheap->ultimo == bheap->capacidad){
        bheap->arr = realloc(bheap->arr, sizeof(void*)*(bheap->capacidad*2 + 1));
        bheap->capacidad *= 2;
    } 
    //actualizamos la posicion del ultimo
    bheap->ultimo++;
    bheap->arr[bheap->ultimo] = dato;
    int j = bheap->ultimo;
    while(j > 1 && bheap->comp(bheap->arr[j/2], bheap->arr[j]) < 0){
        void* aux = bheap->arr[j/2];
        bheap->arr[j/2] = bheap->arr[j];
        bheap->arr[j] = aux;
        j /= 2;
    }
}
void bheap_eliminar(BHeap bheap){
  if(!bheap_es_vacio(bheap)){
    bheap->arr[1] = bheap->arr[bheap->ultimo];

    bheap->ultimo--;
    heapify(bheap, 1, bheap->comp);
    //heapify es una funcion que conserva la invariante de heap desde un nodo hasta una hoja

  }
}

BHeap bheap_crear_desde_arr(void **arr, int largo, FuncionCopia copiar,FuncionComparadora comp){
  BHeap nuevo_heap = bheap_crear(largo, comp);
  for(int i = 0; i<largo; i++){
    nuevo_heap->arr[i+1] = copiar(arr[i]);
  }
  nuevo_heap->ultimo = largo;
  for (int i = largo / 2; i >= 1; i--) {
    heapify(nuevo_heap, i, comp);
  }
  return nuevo_heap;
}
void heapify(BHeap heap, int i, FuncionComparadora c){
  int largest = i;
  int left = 2*i;
  int right = 2*i + 1;

  if(left <= heap->ultimo && c(heap->arr[largest], heap->arr[left]) < 0){
    largest = left;
  }

  if(right <= heap->ultimo && c(heap->arr[largest], heap->arr[right]) < 0){
    largest = right;
  }

  if(largest != i){ // el hijo derecho o el izquierdo son mayores que largest
    void* aux = heap->arr[i];
    heap->arr[i] = heap->arr[largest];
    heap->arr[largest] = aux;
    heapify(heap, largest, c);
  }

}
