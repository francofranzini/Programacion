#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int t;
    printf("Ingrese la temperatura: "); scanf("%d", &t);
    if(t <= 0) {
        printf("SOLIDO");
        ENDL;
    }
    if (t > 0 && t < 100){
        printf("LIQUIDO");
        ENDL;
    }
    if (t>= 100){
        printf("GASEOSO");
        ENDL;
    } 
    return 0;
}