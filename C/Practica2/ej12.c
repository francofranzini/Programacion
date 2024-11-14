#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)
int main(){
    int a[10];
    int n;
    forn(i, 10){
        scanf("%d", (a + i));
    }
    scanf("%i", &n);
    int rta = -1;
    forn(i,10){
        if(a[i] == n) rta = i;
    }
    printf("%i \n", rta);
    return 0;
    
}
