#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)
int main(){
    int vector[5] = {10, 20, 30, 40, 50};
    int a = 3;
    //int* ptr = &a;
    //int* qtr = vector; //a
    //| int 3    | int* &a   |    error    |    int* &a   |
    //|int** &ptr| int 3     | int* vector | int** &vector|
    //|int 10    |int* vector|int** &vector|    int 10    | 
    //|int* qtr+1|  int 11   |   int 11    |    int* &a   |

    return 0;
    
}
