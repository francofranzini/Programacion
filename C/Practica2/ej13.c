#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)
int main(){
    int n = 1;
    while(n<5 || n > 100){
        printf("Ingrese un numero entre 5 y 100: ");scanf("%d",&n);
    }
    int arr[n];
    int suma = 0, error = 0, it = 0;
    while(it < n && error == 0){
        scanf("%i", arr + it);
        if(arr[it] < 5 || arr[it] > 100) error = 1;
        suma += arr[it];
        it++;
    }
    if(error != 0) printf("ERROR");
    else{
        if(suma > 30) printf("Es mayor a 30\n");
        else printf("Es menor a 30\n");
    }

    return 0;
}
