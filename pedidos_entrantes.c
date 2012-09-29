#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

typedef struct pedido pedido_t;
struct pedido{
	int* zona; // es necesario el * ?
	int* cant_pizzas;  // es necesario el * ?
	} pedido_t;

// Funciones de pedidos_entrantes
// El método de agregar pedido - sacar pedido simulará el de una cola:
// usamos lista_insertar_ultimo para insertar nuevos pedidos y usamos
// lista_borrar_primero para sacar pedidos.

// Crea una lista pedidos_entrantes
lista_t* pedidos_entrantes_crear (){
	lista_t* pedidos_entrantes;
	pedidos_entrantes = lista_crear();
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

// Modifica la zona de un pedido
bool pedidos_entrantes_zona (lista_t* pedidos_entrantes, pedido_t* pedido, int zona_nueva){
	
	}
