#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "estructuras.h"
#include "lista.h"
#include "buscador.c"


unsigned int get_id();
lista_iter_t* buscar_id(pedidos_entrantes_t* pedidos, unisigned int id);

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

void (destruir_pedido)(void*dato){
	pedido_destruir((pedido_t*)dato);
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


// Crea una objeto pedidos_entrantes
pedidos_entrantes_t* pedidos_entrantes_crear(){
	pedidos_entrantes_t* pedidos_entrantes;
	pedidos_entrantes = malloc (sizeof(pedidos_entrantes_t));
	if (!pedidos_entrantes) return NULL;
	lista_t* lista;
	lista = lista_crear();
	lista_iter_t* iter = lista_iter_crear(lista);
	return pedidos_entrantes;
	}
	
// devuelve la cantidad de pedidos que contiene la lista pedidos_entrantes
size_t pedidos_entrantes_largo(const pedidos_entrantes_t* pedidos_entrantes){
	return pedidos_entrantes->lista->largo;
	}
	
// Agrega pedido al final de la lista.
bool pedidos_entrantes_agregar (pedidos_entrantes_t* pedidos_entrantes, pedido_t* pedido){
	if (lista_insertar_ultimo(pedidos_entrantes->lista, pedido)) return true;
	return false;
	}

// Saca el primer pedido de la lista.
// Recibe: struct pedidos_entrantes.
// Devuelve el dato del tipo pedido_t* que fue sacado de la lista.
pedido_t* pedidos_entrantes_sacar (pedidos_entrantes_t* pedidos_entrantes){
	return (lista_borrar_primero(pedidos_entrantes->lista));
	}

// Modifica la zona de un pedido.
// Recibe: struct pedidos_entrantes, un int con la nueva zona
// y un unsigned int id que identifica al pedido a modificar.
bool pedidos_entrantes_zona (pedidos_entrantes_t* pedidos_entrantes, unsigned int id, int nueva_zona){
	if (pedidos_entrantes->lista->largo == 0) return false;
	lista_iter_t* iter_pedido_a_modif = lista_iter_buscar(pedidos_entrantes->iter, id);
	pedido_t* pedido_a_modif = lista_iter_ver_actual(pedidos_entrantes->lista, iter_pedido_a_modif);
	pedido_cambiar_zona(pedido_a_modif, nueva_zona);
	return true;
	}

// Modifica cant_pizzas de un pedido
// Recibe: struct pedidos_entrantes, un int con la nueva cantidad
// y un unsigned int id que identifica al pedido a modificar.
bool pedidos_entrantes_cant_pizzas (pedidos_entrantes_t* pedidos_entrantes, unsigned int id, int nueva_cant){
	if (pedidos_entrantes->lista->largo == 0) return false;
	lista_iter_t* iter_pedido_a_modif = lista_iter_buscar(pedidos_entrantes->iter, id);
	pedido_t* pedido_a_modif = lista_iter_ver_actual(pedidos_entrantes->lista, iter_pedido_a_modif);
	pedido_cambiar_zona(pedido_a_modif, nueva_cant);
	return true;
	}
	
// Saca el pedido de la lista de pedidos_entrantes y lo destruye.
// Recibe: struct pedidos_entrantes, un unsigned int con el id del pedido
// a cancelar.
bool pedidos_entrantes_cancelar (pedidos_entrantes_t* pedidos_entrantes, unsigned int id){
	if (pedidos_entrantes->lista->largo == 0) return false;
	lista_iter_t* iter_pedido_a_cancelar = lista_iter_buscar(pedidos_entrantes->iter, id);
	pedido_t* pedido_a_cancelar = lista_borrar(pedidos_entrantes->lista, iter_pedido_a_cancelar);
	pedido_destruir(pedido_a_cancelar);
	return true;
	}

// Destruyo el struct pedidos_entrantes
// Recibe: struct pedidos_entrantes
void pedidos_entrantes_destruir (pedidos_entrantes_t* pedidos_entrantes){
	// Si pedidos_entrantes no existe, termina la funcion
	if (!pedidos_entrantes) return;
	
	// Se destruye el iterador de pedidos_entrantes
	lista_iter_destruir(pedidos_entrantes->iter);
	// Se destruye la lista con lista_destruir, pasándole el dato de pedido_destruir()
	lista_destruir(pedidos_entrantes->lista, (*destruir_pedido));
	
	//~ // Si la lista de pedidos_entrantes esta vacia, se libera la lista
	//~ if (pedidos_entrantes->lista->inicio == NULL){
		 //~ free(pedidos_entrantes->lista);
		 //~ return;
		//~ }
	//~ 
	//~ // Sino, se deben borrar los nodos (que contienen datos del tipo pedido_t)
	//~ pedido_t* borrado;
	//~ int i;
	//~ size_t largo;
	//~ largo = pedidos_entrantes_largo(pedidos_entrantes); 
	//~ // Se itera sobre los nodos de la lista
	//~ for (i=0; i<largo; i++){
		//~ // borrado es el valor del nodo borrado
		//~ borrado = lista_borrar_primero(pedidos_entrantes->lista);
		//~ // Se destruye borrado con pedido_destruir
		//~ pedido_destruir(borrado);	
		//~ }
	//~ // Se libera la lista vacia
	//~ free (pedidos_entrantes->lista);
	//~ 
	//~ // Se libera la estructura pedidos_entrantes
    free(pedidos_entrantes);
    return;
 }

