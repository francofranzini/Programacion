#include <stdio.h>
#include <stdlib.h>

int main(){

    int a;
    char b;
    float c;
    char xd[3];
    printf("a: %p\n", &a);
    printf("b: %p\n", &b);
    printf("c: %p\n", &c);
    printf("xd[0]: %p ", &xd[0]);printf("xd[1]: %p ", &xd[1]);printf("xd[2]: %p ", &xd[2]);

    return 0;
}