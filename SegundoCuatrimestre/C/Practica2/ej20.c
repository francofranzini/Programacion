#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)
int len(char* str){
    int l = 0;
    for(int i = 0; str[i] !=  '\0'; i++)l++;
    return l;
}
int unicos(char s[]){
    int unicos[26], rta = 0;
    for(int i = 0; i<26; i++) unicos[i] = 1;
    char c;
    for(int i = 0, x; s[i] != '\0'; i++){
        c = s[i];
        if(c <= 'Z') x = c - 'A';
        else x = c - 'a';
        rta += unicos[x];
        unicos[x] = 0;
    }
    return rta;
} 
int es_capicua(char* str){
    int rta = 1;
    for(int i = 0, j = len(str)-1; i<j; i++, j--){
        if(str[i] != str[j]) rta = 0;
    }
    return rta;
}
int es_pangrama(char* str){
    int unicas = 0,rta = 0, letras[27];
    forn(i, 27) letras[i] = 1;
    char c;
    for(int i = 0, x; str[i] != '\0'; i++){
        c = str[i];
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
            if(c >= 'a' && c <= 'z') x = c -= 'a';
            else x = c -= 'A';
            unicas += letras[x];
            letras[x] = 0;
        }
    }
    if(unicas == 26) rta = 1;
    return rta;
}
int is_included(char* str, char* str2){
    int i =0, j=0, coincidencias =0;
    for(;str2[i] != '\0' && str[j] != '\0'; j++){
        if(str2[i] == str[j]){
            coincidencias++;
            i++;
        }
    }
    if(coincidencias == len(str2)) return 1;
    return 0;
}
int main(){
    char str[100];
    scanf("%[^\n]", str);
    int l = len(str);
    for(int i = l-1; i>= 0; i--){
        printf("%c", str[i]);
    };ENDL;
    if(es_capicua(str)) printf("ES CAPICUA\n");
    else printf("NO ES CAPICUA\n");
    if(es_pangrama(str) ? printf("ES PANGRAMA \n") : printf("NO ES PANGRAMA \n"));
    if(is_included("chotelsonchot", "elsot") ? printf("ESTA INCLUIDA\n") : printf("NO ESTA INCLUIDA\n"));
    return 0;
    
}
