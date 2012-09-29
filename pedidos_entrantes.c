#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

typedef struct pedido pedido_t;
struct pedido{
	int zona; // es necesario el * ?
	int cant_pizzas;  // es necesario el * ?
	unsigned int id;
	} pedido_t;

long get_id();

pedido_t* pedido_crear( int zona, int cant_pizzas){
	pedido_t* pedido;
	pedido = malloc(sizeof(pedido_t));
	if (pedido == NULL) return NULL;
	pedido->zona = zona;
	pedido->cant_pizzas = cant_pizzas;
	pedido->id = get_id();	
	return pedido;
	}

void pedido_destruir(pedido_t* pedido){
	free(pedido);
	return;
	}

bool pedido_cambiar_zona (pedido_t* pedido, int nueva_zona){
	if (!pedido) return false;
	pedido->zona = nueva_zona;
	return true;
	}
	
bool pedido_cambiar_cant (pedido_t* pedido, int nueva_cant){
	if (!pedido) return false;
	pedido->cant_pizzas = nueva_cant;
	return true;
	}

// Funciones de pedidos_entrantes
// El método de agregar pedido - sacar pedido simulará el de una cola:
// usamos lista_insertar_ultimo para insertar nuevos pedidos y usamos
// lista_borrar_primero para sacar pedidos.


// Crea una lista pedidos_entrantes
lista_t* pedidos_entrantes_crear (){
	lista_t* pedidos_entrantes;
	pedidos_entrantes = lista_crear();
	lista_iter_t* iter = lista_iter_crear(const lista_t* pedidos_entrantes);
	return pedidos_entrantes;
	}
// devuelve la cantidad de pedidos que contiene la lista pedidos_entrantes
size_t pedidos_entrantes_largo(const lista_t *pedidos_entrantes){
	return pedidos_entrantes->largo;
	}
	
// Agrega pedido al final de la lista.
bool pedidos_entrantes_agregar (lista_t* pedidos_entrantes, pedido_t* pedido){
	if (lista_insertar_ultimo(pedidos_entrantes, pedido)) return true;
	return false;
	}

// Elimina el primer pedido de la lista.
pedido_t* pedidos_entrantes_sacar (lista_t* pedidos_entrantes){
	return (lista_borrar_primero(pedidos_entrantes));
	}

// Modifica la zona de un pedido.
// Recibe: lista de pedidos_entrantes, iterador de esa lista, un int con la nueva zona
// y un unsigned int id que identifica al pedido a modificar.
bool pedidos_entrantes_zona (lista_t* pedidos_entrantes, lista_iter_t* iter, unsigned int id, int nueva_zona){
	if (pedidos_entrantes->largo == 0) return false;
	lista_iter_t* iter_pedido_a_modif = lista_iter_buscar(iter, id);
	pedido_t* pedido_a_modif = lista_iter_ver_actual(pedidos_entrantes, iter_pedido_a_modif);
	pedido_cambiar_zona(pedido_a_modif, nueva_zona);
	return true;
	}

// Modifica cant_pizzas de un pedido
// Recibe: lista de pedidos_entrantes, iterador de esa lista, un int con la nueva cantidad
// y un unsigned int id que identifica al pedido a modificar.
bool pedidos_entrantes_cant_pizzas (lista_t* pedidos_entrantes, lista_iter_t* iter, unsigned int id, int nueva_cant){
	if (pedidos_entrantes->largo == 0) return false;
	lista_iter_t* iter_pedido_a_modif = lista_iter_buscar(iter, id);
	pedido_t* pedido_a_modif = lista_iter_ver_actual(pedidos_entrantes, iter_pedido_a_modif);
	pedido_cambiar_zona(pedido_a_modif, nueva_cant);
	return true;
	}

bool cancelar_pedido (lista_t* pedidos_entrantes, lista_iter_t* iter, unsigned int id){
	if (pedidos_entrantes->largo == 0) return false;
	lista_iter_t* iter_pedido_a_cancelar = lista_iter_buscar(iter, id);
	pedido_t* pedido_a_cancelar = lista_borrar(pedidos_entrantes, iter_pedido_a_cancelar);
	pedido_destruir(pedido_a_cancelar);
	return true;
	}

