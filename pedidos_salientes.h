#ifndef SAL_H
#define SAL_H
#include "pila.h"


pila_t* salientes_crear();


void salientes_destruir(pila_t* salientes, (*pedido_destruir));
