#ifndef LISTA_CON_ITER
#define LISTA_CON_ITER
#include "lista.h"
/*
 *ESTRUCTURAS
 */
typedef struct lista_con_iter{
	lista_t* lista;
	lista_iter_t* iter;
}lista_con_iter_t;

/*
 *PRIMITIVAS
 */

lista_con_iter_t* lista_con_iter_crear();

void lista_con_iter_destruir(lista_con_iter_t* lista_con_iter, void destruir(void *));

#endif
