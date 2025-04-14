#ifndef __GLIST_H__
#define __GLIST_H__

typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionVisitante)(void *dato);
typedef int (*Predicado) (void *dato);
typedef int (*FuncionComparadora) (void* dato, void* dato);
typedef struct _GNode {
  void *data;
  struct _GNode *next;
} GNode;

typedef GNode *GList;
typedef GList SGList;
/**
 * Devuelve una lista vacía.
 */
GList glist_crear();
SGList sglist_crear();


/**
 * Destruccion de la lista.
 */
void glist_destruir(GList lista, FuncionDestructora destruir);
void sglist_destruir(SGList lista, FuncionDestructora d);
/**
 * Determina si la lista es vacía.
 */
int glist_vacia(GList lista);
int sglist_vacia(SGList lista);

/**
 * Agrega un elemento al inicio de la lista.
 */
GList glist_agregar_inicio(GList lista, void *dato, FuncionCopia copiar);

SGList sglist_insertar(SGList lista, void *dato, FuncionCopia copiar, FuncionComparadora comparadora)
/**
Filtra segun predicado
*/
GList glist_filtrar(GList lista, FuncionCopia c, Predicado p);
/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void glist_recorrer(GList lista, FuncionVisitante visitar);
void sglist_recorrer(GList lista, FuncionVisitante visit);

#endif /* __GLIST_H__ */
