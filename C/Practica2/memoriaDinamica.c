#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)
int main(){
    //Malloc (pedir memoria)
    //free   (liberar memoria)
    int* a = malloc(sizeof(int)*10);
    //Recibe un numero natural como argumento 
    //correspondiente con la cantidad de bytes;
    
    //Si quiero hacerle resize a un espacio de memoria
    //uso la realloc:
    a = realloc(a, sizeof(int) * 20);


    //Luego de usarlo al bloque de memoria:
    free(a);
    return 0;
}
