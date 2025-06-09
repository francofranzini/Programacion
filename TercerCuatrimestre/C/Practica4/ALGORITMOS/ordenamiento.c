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
  int *izq = malloc(sizeof(int)*(m-j));
  int *der = malloc(sizeof(int)*(n-m));
  izq = mergesort(a, j ,m);
  der = mergesort(a, m, n);
  int* merge;
  merge = mezclar(izq, der, m-j,n-m);
  free(izq);
  free(der);
  return merge;
}
