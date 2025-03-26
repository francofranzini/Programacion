#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    float n = 0;
    for(float i = 1; i <= 100;++i ){
        n += 1/i;
    }
    printf("%f\n", n);
    float k = 0;
    for(float i = 1; i<= 30; ++i){
        k += 1/(pow(i,2));
    }
    printf("%f\n", k);
    float j = 0;
    for(float i = 1; i<= 25; i++){
        j += 1/(pow(j, j));
    }
    printf("%f\n", j);
    int r = 0;
    for(int i = 2; i<=10; i++){
        r += (i+1)*i;
    }
    printf("%i \n", r);
    return 0;
}