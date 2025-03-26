#include <math.h>
#include <stdio.h>
#include<stdlib.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)
struct estudiante{
    char* apellido;
    int anio_ingreso;
    char division;
};
void aumentar(int* x, int*y, int z){
    *x = *x + 2;
    *y = *y + 5;
    z = z + 4;
}
void ingreseCadena(char* c){
    fgets(c, 10, stdin);
}
int *direccion_local(int x){
    return &x;
}
struct nashe{
    int x;
    char c;
};
int main(){
    int vector[5] = {10, 20, 30, 40, 50};
    //int* ptr = &a;
    //int* qtr = vector; //a
    //| int 3    | int* &a   |    error    |    int* &a   |
    //|int** &ptr| int 3     | int* vector | int** &vector|
    //|int 10    |int* vector|int** &vector|    int 10    | 
    //|int* qtr+1|  int 11   |   int 11    |    int* &a   |

    
    printf("%lld", sizeof(struct nashe));
    return 0;
}
