#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int operar(int n){
    if(n%2 == 0){
        n /= 2;
    }
    else{
        n *= 3;
        n += 1;
    }
    return n;
}

int main(){
    int n = -1;
    while(n < 1){
        printf("Ingrese un nro positivo: ");scanf("%i", &n);
    }
    int k = 0;
    while(n != 1){
        n = operar(n);
        printf("El siguiente valor es %i \n", n); 
        k++;
    }
    printf("El valor final es 1, numero de pasos %i \n", k);
    return 0;
}