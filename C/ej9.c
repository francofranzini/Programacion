#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");

int main(){
    int i = 0;
    printf("[");
    while (i < 99){
        printf("%d, ", i);
        i++;
    }
    printf("%d ]", i);
    return 0;
}