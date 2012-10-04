#ifndef PEDIDOS_H
#define PEDIDOS_H
#include "tdas.h"
/*
 *TIPOS
 */

typedef struct pedido{
    int zona;
    int cant_pizzas;
    unsigned int id;
}pedido_t;



/*
 *PRIMITIVAS
 */
bool pedido_cambiar_cant(pedido_t *pedido,int nueva_cant);

bool pedido_cambiar_zona(pedido_t *pedido,int nueva_zona);

void(destruir_pedido)(void *dato);

void pedido_destruir(pedido_t *pedido);

pedido_t *pedido_crear(int zona,int cant_pizzas);

void pedidos_entrantes_destruir(lista_t* pedidos_entrantes);

bool pedidos_entrantes_cancelar(lista_t *pedidos_entrantes,unsigned int id);

bool pedidos_entrantes_cant_pizzas(lista_t *pedidos_entrantes,unsigned int id,int nueva_cant);

bool pedidos_entrantes_zona(lista_t *pedidos_entrantes,unsigned int id,int nueva_zona);

pedido_t *pedidos_entrantes_sacar(lista_t *pedidos_entrantes);

bool pedidos_entrantes_agregar(lista_t *pedidos_entrantes,pedido_t *pedido);

size_t pedidos_entrantes_largo(const lista_t *pedidos_entrantes);

lista_t *pedidos_entrantes_crear();

unsigned int get_random_id();
lista_iter_t* buscar_id(lista_t* pedidos_entrantes, unsigned int id);

int printeo_salientes(pila_t* salientes, int n);


#endif
