#ifndef __HEAP_H__
#define __HEAP_H__

typedef int (*FuncionComparadora)(void* a, void* b); 
typedef void (*FuncionVisitante)(void* a);
typedef void* (*FuncionCopia)(void* a);

typedef struct _BHeap {
  void **arr;
  int capacidad;
  int ultimo;
  FuncionComparadora comp;
} *BHeap;

BHeap bheap_crear(int, FuncionComparadora);
void bheap_destruir(BHeap);
int bheap_es_vacio(BHeap);
void bheap_recorrer(BHeap, FuncionVisitante);
void bheap_insertar(BHeap , void* );
void* bheap_eliminar(BHeap);

BHeap bheap_crear_desde_arr(void **arr, int largo, FuncionCopia copiar,
FuncionComparadora comp);


void heapify(BHeap heap, int i, FuncionComparadora c);

#endif // HEAP_H
