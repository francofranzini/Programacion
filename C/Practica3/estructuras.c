#include <math.h>
#include <stdio.h>
#define ENDL printf("\n");
#define forn(i,n) for(int i = 0; i<n; ++i)
struct punto{
    double x;
    double y;
};
double distancia(struct punto p1, struct punto p2){
    return sqrt((pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
}
double proy(struct punto p, char eje){
    if(eje == 'x'){
        return p.x;
    }
    if(eje == 'y'){
        return p.y;
    }
    //invalido
    return 0;
}
char pos(struct punto p){
    if(p.x == 0){
        if(p.y == 0) return 'o';
        else return 'y';
    }
    if(p.y == 0) return 'x';
    if(p.x * p.y < 0){
        if(p.x > 0) return '4';
        else return '2';
    }
    else{
        if(p.x > 0) return '1';
        else return '3';
    }
}
int main(){
    struct punto punto1;
    scanf("%lf", &punto1.x);
    punto1.y = 4;
    struct punto punto2;
    punto2.x = 1;
    punto2.y = 1;
    printf("%.2f \n", proy(punto1, 'x'));
    printf("%.2f \n", distancia(punto1, punto2));
    return 0;
    
}
