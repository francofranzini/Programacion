#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int i = 0;
    printf("[ ");
    while(2*i+1 < 99){
        printf("%i, ",2*i+1 );
        i++;
    }
    printf("%i ]", 2*i + 1);

    return 0;
}