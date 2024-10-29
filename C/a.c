#include <math.h>
#include <stdio.h>

int main(){
    
    float x, y;
    printf("Introduzca 2n: ");
    scanf("%f %f", &x, &y);
    printf("La suma de %f y %f es %f\n", x, y , x+y);
    printf("La suma de %4f y %.2f es %20.3f \n", x, y, x+y);
    printf ( " La suma de %.2e y %e vale %e \n " , x , y , x + y ) ;

    return 0;
}