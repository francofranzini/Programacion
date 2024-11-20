#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)
struct alumno{
    char* nombre;
    char* direccion; // != char direccion[30]
    int edad;
    char* legajo;//distinto de char legajo[6]
};
// struct alumno{
//     char[30] nombre;
//     char[30] direccion;
//     int edad;
//     char[6] legajo;
// }
//Es distinto ya que con los corchetes asigna un espacio de memoria
//a direccion, nombre, legajo. Con el char* tenemos que pasar el 
// puntero de la direccion de memoria de un bloque pedido con malloc
//
int main(){
    //Malloc (pedir memoria)
    //free   (liberar memoria)
    int* a = malloc(sizeof(int)*10);
    //Recibe un numero natural como argumento 
    //correspondiente con la cantidad de bytes;
    
    //Si quiero hacerle resize a un espacio de memoria
    //uso la realloc:
    a = realloc(a, sizeof(int) * 20);
    //19/11/2024
    struct alumno alumnos[50]; //array de 50 structs de alumno
    char temp[256];
    printf("Ingrese un nombre: ");scanf("%s", temp);
    alumnos[0].nombre = malloc(sizeof(char)*(strlen(temp)+1));
    strcpy(alumno[0].nombre, temp); //toma direccion de destino y pega lo que hay en la segunda
    //direccion
    //De esta manera guardamos solo con la memoria necesaria
    
    
    alumnos[0].nombre = realloc(alumnos[0].nombre, sizeof(char) * 5);
    //alumno[0].nombre = "Facu" es correcto si el struct esta declarado con corchetes
    //pero guarda en memoria siempre 30 espacios para cada nombre.
    //alumno[0].nombre = malloc(sizeof(char*30)) pudiendo gestionar dinamicamente el 
    //tamaño de cada nombre en cada asignacion. 

    //Luego de usarlo al bloque de memoria:
    free(a);
    return 0;
}
