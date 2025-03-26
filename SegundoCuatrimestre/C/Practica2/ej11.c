#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)
int main(){
    int n[50];
    for(int i = 0; i<50; i++){
        n[i] = 3*i;
    }
    forn(i,50){
        printf("%i ", n[i]);//*(&n+i)
    }
    return 0;
}
