#include <stdio.h>
#include <stdlib.h>


int main(){

    char* string_asesina = malloc(sizeof(char)*1000000000000);
    printf("str: %p", string_asesina);
    //En caso de no poder asignar el espacio de memoria retorna NULL (0000000000...)
    return 0;
}