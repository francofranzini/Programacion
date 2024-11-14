#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)
int sumArray(int* arr, int n){
    int suma = 0;
    forn(i,n){
        suma += arr[i];
    }
    return suma;
}
int prodAlt(int* arr, int n){
    int prod = 1;
    forn(i,n){
        prod *= arr[i];
        i++;
    }
    return prod;
}
int main(){
    int arreglo[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int suma_arreglo = sumArray(arreglo, 12);
    int prod_arreglo = prodAlt(arreglo, 12);
    printf("La suma es: %i \n", suma_arreglo);
    printf("El producto de los elementos en posiciones pares es: %i \n", prod_arreglo);
    return 0;
    
}
