#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int n = -1; 
    printf("Ingrese un numero del 1 al 6: ");scanf("%i", &n);
    if(n<1 || n > 6){
        printf("NUMERO INCORRECTO");
        return 0;
    }
    switch(n){
        case 1:
            printf("6 \n");
            break;
        case 2:
            printf("5 \n");
            break;
        case 3:
            printf("4 \n");
            break;
        case 4:
            printf("3 \n");
            break;
        case 5:
            printf("2 \n");
            break;
        case 6:
            printf("1 \n");
            break;
    }
    return 0;
}