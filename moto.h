#ifndef MOTO_H
#define MOTO_H
#include "pila.h"

pila_t* moto_cargar(zona_t* zona);

pedido_t* buscar_adecuado (lista_con_iter_t* lista_espera, int pizzas_cargadas) ;

int intentar_lista_espera(lista_con_iter_t* zona, pila_t* moto);

int intentar_cola_ppal(lista_con_iter_t* zona, pila_t* moto);
#endif
