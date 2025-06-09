#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ordenamiento.h"
int main(){

  int x[8] = {38, 27, 43, 3, 9, 82, 10};


  int* b = malloc(sizeof(int)*7);

  for(int i = 0; i<7; i++) b[i] = x[i];

  // copy(a, b, 0, 4);
  // b = mezclar(a, c, 4, 4);
  // int *y;
  // y = mergesort(b, 0, 7);
  // free(y);
  
  quicksort(b, 0, 7);

  for(int i = 0; i<7; i++) printf("%d ", b[i]);
  
  free(b);
  

  return 0;
}

