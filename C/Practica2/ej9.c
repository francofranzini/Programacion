#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int n[100];
    for(int i = 0; i<100; i++){
        n[i] = i;
    }
    for(int i = 0; i<100; i++){
        printf("%i ", n[i]);
    }
    return 0;
}