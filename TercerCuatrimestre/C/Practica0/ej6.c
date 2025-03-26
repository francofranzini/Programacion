#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* get_new_line(){
    char string[255];
    
    printf("Ingrese una linea: ");scanf("%[^\n]", string);

    char* retorno = malloc(sizeof(char)*strlen(string));
    strcpy(retorno, string);
    return retorno;
    
}
int main(){

    char* linea = get_new_line();
    printf("%s", linea);


    return 0;
}