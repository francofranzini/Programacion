#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)
int isin(char* str, char c){
    int is = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == c) is = 1;
    }
    return is;
}
int howmuchisin(char* str, char c){
    int cant = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == c) cant++;
    }
    return cant;
}
int main(){
    char* prueba = "Niggachin";
    char g = 'g';
    
    printf("%i \n", isin(prueba, g));
    printf("%i \n", howmuchisin(prueba, g));
    return 0;
    
}
