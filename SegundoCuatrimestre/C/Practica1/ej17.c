#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
int max3(int a, int b, int c){
    if(a > b && a > c) return a;
    if(b > a && b > c) return b;
    return c;
};
int es_rectangulo(int a, int b, int c){
    int x, y;
    int mayor = max3(a, b, c);
    if(mayor == a){
        x = b;
        y = c;
    }
    if(mayor == b){
        x = a;
        y = c;
    }
    if(mayor == c){
        x = a;
        y = b;
    }
    if(pow(mayor,2) == pow(x, 2) + pow(y, 2)) return 1;
    return 0;
};

int main(){
    int a, b,c;
    printf("ingrese los 3 lados del rectangulo: "); scanf("%i %i %i", &a, &b, &c);
    if(es_rectangulo(a,b,c)) printf("ES RECTANGULO");
    else printf("NO ES RECTANGULO");   
    return 0;
}