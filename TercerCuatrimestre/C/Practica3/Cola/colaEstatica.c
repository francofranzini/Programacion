#include "cola.h"
#include <stdlib.h>
#DEFINE N 50
typedef struct _Cola{
    int datos[N];
    int posicionAAgregar;
    int posicionAEliminar;
}Cola;
Cola* cola_crear(){
    Cola* nueva_cola = malloc(sizeof(Cola));
    nueva_cola->posicionAAgregar = 0;
    nueva_cola->posicionAEliminar = 0;
    return nueva_cola;
}
void enqueue(Cola* p, int dato){
    if(p->posicionAAgregar - p->posicionAEliminar == N) return;
    p->datos[p->posicionAAgregar%N] = dato;

    p->posicionAAgregar++;

    gestionarIndices(p);
}
void gestionarIndices(Cola* p){
    if(p->posicionAAgregar >= N && p->posicionAEliminar >= N){
        p->posicionAAgregar = p->posicionAAgregar - N;
        p->posicionAEliminar = p->posicionAEliminar - N;
    }
}