#include <stdio.h>

int isin(char* str, char c){
    int is = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == c) is = 1;
    }
    return is;
}

int panabro(char str[100]){
    int rta = 0;

    for(int i='a'; i<='z'; i++){
        if(isin(str,i)) rta = 1;
        else rta = 0; 
    }
    return rta;
}


int main(){
    
    char s[100];

    printf("ingrese una cadena\n");
    scanf("%[^\n]", s);

    int rta = panabro(s);
    if(rta == 1) printf("es panabro\n");
    else printf("no es panabro\n");
    
    return 0;
}