#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int k;
    printf("Ingrese K: "); scanf("%i", &k);
    int arr[k];
    printf("Ingrese los elementos del array: ");
    for(int i = 0; i<k; ++i){
        scanf("%i", &arr[i]);
    }
    //[1,2,3,4,5] --> [3,4,5,1,2]
    int p = 0;
    printf("Ingrese (<k) el numero desde el que desea permutar: ");scanf("%i", &p);
    int cambiada[k];
    for(int i = 0; i<k; ++i){
        cambiada[i] = arr[(i+p)%k];
    }
    printf("[");
    for(int i = 0; i<k-1; i++){
        printf("%i, ", cambiada[i]);
    }
    printf("%i] \n", cambiada[k-1]);
    return 0;
}