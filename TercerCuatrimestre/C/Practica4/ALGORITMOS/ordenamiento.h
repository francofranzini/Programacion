#ifndef __ORDENAMIENTO_H__
#define __ORDENAMIENTO_H__

void copy(int* a, int* x, int i, int j);
int* mezclar(int* izq, int* der, int i, int j);
int* mergesort(int* a, int j,int n);
int particionar(int* a, int inicio, int final, int pivot);
void quicksort(int* a, int inicio, int final);


#endif // __ORDENAMIENTO_H__