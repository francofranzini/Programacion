#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int i;
    printf("Ingrese un numero: ");scanf("%i", &i);
    double n=1;
    while(i>1){
        n *= i;
        i--;
    }
    printf("%.1f", n);
    return 0;
}