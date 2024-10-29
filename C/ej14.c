#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int i = 0;
    printf("Ingrese una cantidad de pacientes: ");scanf("%i", &i);
    int edad;
    float indice;
    int cantidad = i;
    int suma_edad = 0, edad_ingresados = 0, edad_operados = 0;
    int ingresados = 0, operados = 0;
    while(i > 0){
        printf("Ingrese edad y condicion: ");scanf("%i %f", &edad, &indice);
        suma_edad += edad;
        if(indice > 0.6 && indice <= 0.9){
            ingresados++;
            edad_ingresados += edad;
        } 
        if(indice > 0.9){
            operados++;
            edad_operados += edad;
        }
        i--;
    }
    printf("El promedio de ingresados es %i y de operados es %i \n", edad_ingresados/ingresados, edad_operados/operados);
    printf("La edad promedio de los analizados es: %i", suma_edad/cantidad);
    return 0;
}