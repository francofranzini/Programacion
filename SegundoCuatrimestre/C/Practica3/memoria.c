#include <math.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)

void setzerozero(int a[]){
    a[0] = 0;
}
void setin(int* x){
    int a = *x;
    if(a) *x = 1;
    else *x = 0;
}
void swap(int* x, int* y){
    int aux1 = *x;
    *x = *y;
    *y = aux1;
}
//Malloc retorna null en caso de no poder otorgar
//el espacio de memoria solicitado
char* getnewline(){
    char aux[230];
    scanf("%[^\n]", aux);
    char* r = malloc(sizeof(char) * (strlen(aux)+1));
    strcpy(r, aux);
    return r;
}
int main(){
    //int x, y, z;
    //int arr[] = {1,2,3,4,5};
    //ej1: printf("%p, %p, %p \n", &x, &y, &z);
    //setzerozero(arr);
    //ej2 printf("%i", arr[0]);
    printf("%s\n", getnewline());
    return 0;
}
