#include <stdio.h>
#include <math.h>
int bisiesto(int ano){
    if(ano%400 == 0 || (ano % 4 == 0) && (ano % 100 != 0)) return 1;
    else return 0;
}
int main(){
    int ano;
    printf("Ingrese el ano: "); scanf("%d", &ano);
    if(bisiesto(ano)) printf("BISIESTO");
    else printf("NO BISIESTO");
    return 0;
}