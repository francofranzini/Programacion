#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int n1  = 0,n2 = 0;
    while(n1 >= n2){
        printf("Ingrese dos numeros: ");scanf("%i %i", &n1, &n2);
    }
    printf("[");
    while(n2 - n1 > 1){
        printf("%i, ", n1);
        n1++;
    }
    printf("%i]\n", n1); 
    return 0;
}