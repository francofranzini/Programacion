#include <stdio.h>
#include <stdlib.h>



void set_in(int* x){
    if(*x != 0) *x = 1;
    else *x = 0;
}
int main(){

    int a = 0;
    set_in(&a);
    printf("%i", a);

    return 0;
}