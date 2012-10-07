#ifndef PEDIDOS_H
#define PEDIDOS_H
#define MAX 50
#include "tdas.h"


typedef struct pedido{
    int zona;
    int distancia;
    int cant_pizzas;
    char id[MAX];
}pedido_t;



/*
 *PRIMITIVAS
 */
bool pedido_cambiar_cant(pedido_t *pedido,int nueva_cant);

bool pedido_cambiar_zona(pedido_t *pedido,int nueva_zona, int nueva_distancia);

void(destruir_pedido)(void *dato);

void pedido_destruir(pedido_t *pedido);

pedido_t *pedido_crear(int zona, int distancia, int cant_pizzas, char* id);

void pedidos_entrantes_destruir(lista_t* pedidos_entrantes);

bool pedidos_entrantes_cancelar(lista_t *pedidos_entrantes,char* id);

bool pedidos_entrantes_cant_pizzas(lista_t *pedidos_entrantes,char* id,int nueva_cant);

bool pedidos_entrantes_zona(lista_t *pedidos_entrantes,char* id,int nueva_zona, int nueva_distancia);

pedido_t *pedidos_entrantes_sacar(lista_t *pedidos_entrantes);

bool pedidos_entrantes_agregar(lista_t *pedidos_entrantes,pedido_t *pedido);

size_t pedidos_entrantes_largo(const lista_t *pedidos_entrantes);

lista_t *pedidos_entrantes_crear();

//~ char* get_random_id();
lista_iter_t* buscar_id(lista_t* pedidos_entrantes, char* id);

int printeo_salientes(pila_t* salientes, int n);
bool pedidos_lista_print (lista_t* lista_pedidos);

#endif
