#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int n = 5;
    char c;
    char* s = "bucle";
    for(int i = 1; i<= 5; i++){
        printf("%.*s %i", i, s, n);
        if(i == 1) printf(" T \n");
        if(i == 2) printf(" s \n");
        if(i == 3) printf(" R \n");
        if(i == 4) printf(" q \n");
        if(i == 5) printf(" P \n");
        --n;
    }
    return 0;
}