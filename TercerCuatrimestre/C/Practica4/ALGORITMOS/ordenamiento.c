#include <stdio.h>
#include <stdlib.h>

#include "ordenamiento.h"


int* mezclar(int* izq, int* der, int i, int j){
  int x = 0, y = 0, k = 0;
  int* mezcla = malloc(sizeof(int)*(i+j));
  while(x < i && y < j){
    if(izq[x] < der[y]){
      mezcla[k++] = izq[x++];
    }
    else mezcla[k++] = der[y++];
  }
  while(x < i) mezcla[k++] = izq[x++];
  while(y < j) mezcla[k++] = der[y++];
  return mezcla;
}

int* mergesort(int* a, int j,int n){
  if(n-j < 2){ 
    int* ret = malloc(sizeof(int)); 
    ret[0] = a[j];
    return ret;
  }
  int m = j + (n-j)/2;
  int* izq, *der;
  izq = mergesort(a, j ,m);
  der = mergesort(a, m, n);
  int* merge;
  merge = mezclar(izq, der, m-j,n-m);
  free(izq);
  free(der);
  return merge;
}

int particionar(int* a, int inicio, int final, int pivot){
  int j = inicio;
  for(int i = inicio; i<final; i++){
    if(a[i] <= pivot){
      int aux = a[i];
      a[i] = a[j];
      a[j++] = aux;
    }
  }
  return j;
}

void quicksort(int* a, int inicio, int final){
  if(final-inicio < 2) return;
  int p = a[final-1];

  int medio = particionar(a, inicio, final-1, p);
  int aux = a[medio];
  a[medio] = p;
  a[final-1] = aux;
  //a = [(...<p...), p, (...>=p...)]
  quicksort(a, inicio, medio);
  quicksort(a, medio+1, final);
}