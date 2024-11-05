#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int edad;
    printf("Ingrese la edad: ");scanf("%i", &edad);
    if(edad < 18){
        printf("EXENTO");
        ENDL;
    } 
    else{
        if(edad > 65) printf("SEGURIDAD SOCIAL \n");
        else printf("IMPOSIBLE \n");
    }
    return 0;
}