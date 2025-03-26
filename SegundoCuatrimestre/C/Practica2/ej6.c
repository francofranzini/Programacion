#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
#define NUMERO_SECRETO 96
int main(){
    int n = -1;
    while(n != NUMERO_SECRETO){
        printf("Ingrese un numero entre 0 y 500: "); scanf("%i", &n);
        if(n > NUMERO_SECRETO) printf("El numero es menor \n");
        if(n < NUMERO_SECRETO) printf("El numero es mayor \n");
    }
    printf("HAS GANADO! \n");
    return 0;
}