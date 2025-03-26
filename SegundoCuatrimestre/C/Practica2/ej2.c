#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    printf("1. Azul \t 2 \tPrimera\n");
    printf("2. Roja \t 1 \t Primera\n");
    printf("3. Verde \t 3 \t Segunda\n");
    printf("4. Rosa \t 2 \t Segunda\n");
    printf("5. Gris \t 1 \t Tercera\n");

    int h;
    printf("Ingrese una habitacion: "); scanf("%i",&h);ENDL;
    switch(h){
        case 1:
            printf("2 \tPrimera\n");
            break;
        case 2:
            printf("1 \tPrimera\n");
            break;
        case 3:
            printf("3 \t Segunda\n");
            break;
        case 4:
            printf("2 \t Segunda\n");
            break;
        case 5:
            printf("1 \t Tercera\n");
            break;
    }
    return 0;
}