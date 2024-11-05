#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int i;
    printf("Ingrese un numero: "); scanf("%i", &i);
    int n = i-1;
    int divisores = 0;
    while(n>1){
        if(i % n == 0) divisores++;
        n--;
    }
    if(divisores == 0) printf("ES PRIMO %i \n", i);
    else printf("NO ES PRIMO %i \n", i);
    return 0;
}