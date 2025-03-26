#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)
int max(int a, int b){
    if(a > b) return a;
    else return b;
}
int main(){
    int arr[100];
    int maximo = 0, aux = 0;
    int rta;
    forn(i, 100) arr[i] = 0;
    int x = 1;
    while(x >= 0){
        scanf("%i", &x);
        if(x >= 0 && x <= 99){
            arr[x] += 1;
            aux = maximo;
            maximo = max(maximo, arr[x]);
            if(maximo != aux) rta = x;
        } 
    }
    printf("La respuesta es: %i \n", rta);
    return 0;
    
}
