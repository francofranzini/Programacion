#include <stdio.h>
#include <stdlib.h>



void swap(int* x, int* y){
    int aux = *x;
    *x = *y;
    *y = aux;
}
int main(){

    int a = 5, b = 7;
    swap(&a, &b);
    printf("a: %i, b: %i", a, b);

    return 0;
}