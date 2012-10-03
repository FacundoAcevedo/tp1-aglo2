#ifndef ZONASYMOTO_H
#define ZONASYMOTO_H
#include "tdas.h"

//########################################################################
//                                PRIMITIVAS DE ZONAS
//########################################################################
typedef struct zona zona_t;

zona_t* zona_crear();

bool zona_preparar_pedidos(zona_t** vector, lista_con_iter_t* pedidos);

pedido_t* zona_sacar (zona_t** vector, int zona_num);

//########################################################################
//                                PRIMTIVAS DE ZONAS
//########################################################################

pila_t* moto_cargar(zona_t* zona);

pedido_t* buscar_adecuado (lista_con_iter_t* lista_espera, int pizzas_cargadas) ;

int intentar_lista_espera(lista_con_iter_t* zona, pila_t* moto);

int intentar_cola_ppal(lista_con_iter_t* zona, pila_t* moto);


#endif
