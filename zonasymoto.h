#ifndef ZONASYMOTO_H
#define ZONASYMOTO_H
#include "tdas.h"
#include "pedidos.h"
#include "stdbool.h"

//########################################################################
//                        PRIMITIVAS DE ZONAS Y MOTO
//########################################################################

// Destruye la lista "zonas" y los pedidos que contiene
void zonas_destruir(lista_t* zonas, void destruir_pedido(void*));

// Pasa los pedidos de pedidos_entrantes a la lista zonas
bool zona_preparar_pedidos(lista_t* zonas, lista_t* pedidos_entrantes);

// Recibe la lista zonas y saca de ella los pedidos que cumplan los requisitos:
// la cantidad de pizzas en la moto debe ser mayor o igual a la capacidad
// maxima. Recibe también la pila "salientes" a donde ira apilando las motos
// cargadas.
// Devuelve true si la moto se cargo con pizzas; false si pedidos_entrantes
// estaba vacia o si la moto no pudo cargar nada 
lista_t* moto_cargar(lista_t* zonas, pila_t* salientes);

// Recibe una lista "moto" y la devuelve ordenada por la distancia
// De los pedidos que contiene de menor a mayor
lista_t* moto_ordenar(lista_t* moto);


#endif
