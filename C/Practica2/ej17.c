#include <stdio.h>
#define N = 1000;
int main () {
    int i , j , a [ N +1]; // linea 4: declaracion de dos enteros y
    // un arreglo de ( 1001 ) componentes
    for ( a [1]=0 , i =2; i <= N ; i ++) {
        a [ i ] = 1;
    }//Llena el array de 1's con un 0 en a[1]
    for (i =2; i <= N /2; i ++) {//i llega hasta N/2, 1 en 1[2,500]
        for ( j ==2; j <= N /i , j ++) {//Llena de 0 las posiciones i*j 2*[2,N/2], 3*[2,N/3],4[4,N/4] donde [i,N/i] es el conjunto natural de i hasta N/i
            a [ i * j ] = 0;
        }
    }
    for ( i =1; i <= N ; i ++) {// Recorre el array buscando si hay algun 1 restante
                                // lo cual se cumple ya que el for anterior solo llena de ceros a i*(2 --> N/i) con N/i > 2
        if ( a [ i ]== true ) {//Se cumple en a[1]
            printf ( " %d " , I ) ;//Error ya que I nunca se declara
        }
    }
    printf ( "\n" ) ;
    return 0;
}