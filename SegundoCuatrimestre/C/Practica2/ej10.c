#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int n[200];
    for(int i = 100; i< 200; i++){
        n[i-100] = i;
    }
    for(int i =0; i<100; i++){
        printf("%i ",n[i]);
    }
    return 0;
}