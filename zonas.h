#ifndef ZONA_H
#define ZONA_H

/*
 *TIPOS
 */


typedef struct zona{
	cola_t* cola_ppal;
        lista_con_iter_t* lista_espera;
}zona_t;



/*
 *PRIMITIVAS
 */

zona_t* zona_crear();

bool zona_preparar_pedidos(zona_t** vector[], lista_con_iter_t* pedidos);

bool zona_preparar_pedidos(zona_t** vector[], lista_con_iter_t* pedidos);

pedido_t* zona_sacar (zona_t** vector[], int zona);

#endif
