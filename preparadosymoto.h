#ifndef PREPARADOSYMOTO_H
#define PREPARADOSYMOTO_H
#include "tdas.h"
#include "pedidos.h"
#include "stdbool.h"

//########################################################################
//                        PRIMITIVAS DE PREPARADOS Y MOTO
//########################################################################

// Pasa los pedidos de pedidos_entrantes a la lista preparados
bool pedidos_preparar(lista_t* preparados, lista_t* pedidos_entrantes);

// Recibe la lista preparados y saca de ella los pedidos que cumplan los requisitos:
// la cantidad de pizzas en la moto debe ser mayor o igual a la capacidad
// maxima. Recibe también la pila "salientes" a donde ira apilando los pedidos
// cargados.
// Devuelve una lista moto ordenada si la moto se cargo con pizzas; NULL
// si pedidos_entrantes estaba vacia o  la moto no pudo cargar nada 
lista_t* moto_cargar(lista_t* preparados, pila_t* salientes);

// Recibe una lista "moto" y la devuelve ordenada por la distancia
// de los pedidos que contiene de menor a mayor
lista_t* moto_ordenar(lista_t* moto);


#endif
