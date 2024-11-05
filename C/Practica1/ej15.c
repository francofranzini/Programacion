#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int maximo(int a, int b){
    if(a > b) return a;
    else return b;
}
int main(){
    int a, b;
    printf("Ingrese un a y un b: "); scanf("%i %i", &a, &b);
    printf("El maximo entre %i y %i es: %i \n", a, b, maximo(a, b));
    return 0;
}