#include "glist.h"
#include "cola.h"

struct _Cola{
    GList datos;
};


Cola* cola_crear(){
    Cola* nueva_cola = malloc(sizeof(Cola));
    nueva_cola->datos = glist_crear();
    return nueva_cola;
}
void encolar(Cola* cola, void* dato, FuncionCopia c){
    cola->datos = glist_agregar_final(cola->datos, dato, c);
}
void desencolar(Cola* cola, FuncionDestructora d){
    cola->datos = glist_eliminar_inicio(cola->datos, d);
}
void cola_imprimir(Cola* cola, FuncionVisitante v){
    glist_recorrer(cola->datos, v);
}