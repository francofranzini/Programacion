#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
int dia(int x){
    int a = x%19;
    int b = x%4;
    int c = x%7;
    int d = (19 * a + 24)%30;
    int e = (2 * b + 4 * c + 6 * d + 5)%7;
    int n = 22 + e + d;

    return n;
}
int main(){
    int x;
    printf("Ingrese el año: "); scanf("%i", &x);
    int n = dia(x);
    if(n > 31){
        printf("Pascua el dia %i de Abril de %i \n", n-31, x);
    }
    else printf("Pascua el dia %i de Marzo de %i \n", n, x);
    
    return 0;
}