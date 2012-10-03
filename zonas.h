#ifndef ZONA_H
#define ZONA_H
#include "lista_con_iter.h"
//~ #include "pedidos_entrantes.h"
/*
 *TIPOS
 */


typedef struct zona zona_t;



/*
 *PRIMITIVAS
 */

zona_t* zona_crear();

bool zona_preparar_pedidos(zona_t** vector, lista_con_iter_t* pedidos);

//~ pedido_t* zona_sacar (zona_t** vector, int zona_num);

#endif
