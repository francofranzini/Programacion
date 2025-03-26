#include <stdio.h>
#include <stdlib.h>


void set_first(int x[]){
    x[0] = 0;
}
int main(){
    int arr[5];
    set_first(arr);
    printf("%i", arr[0]);
    

    return 0;
}