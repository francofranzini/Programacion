#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
int max(int a, int b){
    if(a>b) return a;
    else return b;
}
int es_triangulo(int a, int b, int c){
    int x = max(max(a,b),c);
    int y = (a + b + c) - x;
    if(x >= y) return 0;
    else return 1;


}
int main(){
    int a,b,c;
    printf("Ingrese los 3 lados del triangulo: ");scanf("%i %i %i", &a, &b, &c);
    if(es_triangulo(a,b,c)) printf("ES TRIANGULO\n");
    else printf("NO ES TRIANGULO\n");
    return 0;
}