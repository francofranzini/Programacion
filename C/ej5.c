#include <stdio.h>
#include <math.h>

char* condicion(int nota){
    if(nota >= 2 && nota <= 5) return "INSUFICIENTE";
    if(nota == 6 ) return "APROBADO";
    if(nota == 7) return "BUENO";
    if(nota == 8) return "MUY BUENO";
    if (nota == 9) return "DISTINGUIDO";
    if (nota == 10) return "SOBRESALIENTE";
    return "CHINGANIN";
}

int main(){
    int nota;
    printf("Ingrese una nota: ");
    scanf("%i", &nota);
    
    printf("%s", condicion(nota));
    return 0;
}