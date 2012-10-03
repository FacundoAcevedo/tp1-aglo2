#ifndef LISTA_CON_ITER_H
#define LISTA_CON_ITER_H

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include "listaycola.h"
/*
 *ESTRUCTURAS
 */
typedef struct lista_con_iter lista_con_iter_t;

/*
 *PRIMITIVAS
 */

lista_con_iter_t* lista_con_iter_crear();

void lista_con_iter_destruir(lista_con_iter_t* lista_con_iter, void destruir(void *));

#endif //LISTA_CON_ITER_H
