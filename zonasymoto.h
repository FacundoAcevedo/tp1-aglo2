#ifndef ZONASYMOTO_H
#define ZONASYMOTO_H
#include "tdas.h"
#include "pedidos.h"

//########################################################################
//                                PRIMITIVAS DE ZONAS
//########################################################################
typedef struct zona zona_t;

zona_t* zona_crear();

bool zona_preparar_pedidos(zona_t* zona1, zona_t* zona2, zona_t* zona3, zona_t* zona4, zona_t* zona5, lista_t* pedidos);

pedido_t* zona_sacar(zona_t* zona, int zona_num);

//########################################################################
//                                PRIMTIVAS DE ZONAS
//########################################################################

lista_t* moto_cargar(zona_t* zona);

pedido_t* buscar_adecuado (lista_t* lista_espera, int pizzas_cargadas) ;

int intentar_lista_espera(zona_t* zona, lista_t* moto);

int intentar_cola_ppal(zona_t* zona, lista_t* moto);


#endif
