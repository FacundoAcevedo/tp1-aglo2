#ifndef TDAS_H
#define TDAS_H

#include <stdbool.h>

/* *****************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

typedef struct _pila pila_t;
typedef struct nodo nodo_t;
typedef struct lista lista_t;
typedef struct lista_iter lista_iter_t;
typedef struct cola cola_t;
typedef struct lista_con_iter lista_con_iter_t;



/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/
pila_t* pila_crear();
void pila_destruir(pila_t *pila, void destruir_dato(void *));
bool pila_esta_vacia(const pila_t *pila);
bool pila_apilar(pila_t *pila, void* valor);
void* pila_ver_tope(const pila_t *pila);
void* pila_desapilar(pila_t *pila);

/* *****************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/
 cola_t* cola_crear();
void cola_destruir(cola_t *cola, void destruir_dato(void*));
bool cola_esta_vacia(const cola_t *cola);
void* cola_ver_primero(const cola_t *cola);
void* cola_desencolar(cola_t *cola);
bool cola_encolar(cola_t *cola, void* valor);


/* *****************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/
 lista_t* lista_crear();
void lista_destruir(lista_t *lista, void destruir_dato(void *));
size_t lista_largo(const lista_t *lista);
bool lista_esta_vacia(const lista_t *lista);
bool lista_insertar_primero(lista_t *lista, void *dato);
bool lista_insertar_ultimo(lista_t *lista, void *dato);
void *lista_ver_primero(const lista_t *lista);
void *lista_borrar_primero(lista_t *lista);
bool lista_insertar(lista_t *lista, lista_iter_t *iter, void *dato);
void *lista_borrar(lista_t *lista, lista_iter_t *iter);

lista_iter_t *lista_iter_crear(const lista_t *lista);
bool lista_iter_avanzar(lista_iter_t *iter);
void *lista_iter_ver_actual(const lista_iter_t *iter);
bool lista_iter_al_final(const lista_iter_t *iter);
void lista_iter_destruir(lista_iter_t *iter);


#endif // TDAS_H
