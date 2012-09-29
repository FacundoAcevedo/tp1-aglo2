#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "cola.h"
#include "pedidos_entrantes.c"

// Creo las zonas
cola_t* zona1;
cola_t* zona2;
cola_t* zona3;
cola_t* zona4;
cola_t* zona5;

zona1 = cola_crear();
zona2 = cola_crear();
zona3 = cola_crear();
zona4 = cola_crear();
zona5 = cola_crear();

cola_t* zona1_aux;
cola_t* zona2_aux;
cola_t* zona3_aux;
cola_t* zona4_aux;
cola_t* zona5_aux;

zona1_aux = cola_crear();
zona2_aux = cola_crear();
zona3_aux = cola_crear();
zona4_aux = cola_crear();
zona5_aux = cola_crear();

cola_t** vector[] = {*zona1, *zona2, *zona3, *zona4, *zona5};

// Reparte todos los elementos de la lista de pedidos_entrantes entre las
// cinco zonas del tipo cola_t. 
bool zona_preparar_pedidos(cola_t** vector[], pedidos_entrantes_t* pedidos){
	// Si pedidos_entrantes no existe
	if (!pedidos_entrantes) return false;
	// Si la lista de pedidos_entrantes esta vacia
	if (pedidos_entrantes->lista == NULL) return false;
	int i;
	lista_t* lista = pedidos_entrantes->lista;
	// Reparto entre las zonas
	while (lista->tamanio >= 0){
		for (i=0, i<5, i++){
			if (lista->tamanio >= 0){
				pedido_t* pedido;
				pedido = pedidos_entrantes_sacar(lista);
				/*cola_apilar(vector[i], pedido);*/
				cola_encolar(vector[i], pedido);
				}
			}
		}
	return true;
	}

// Desencola un pedido de la zona que se pasa por parametro.
// Devuelve el pedido desencolado.
pedido_t* zona_sacar (cola_t** vector[], int zona){
	if (cola_esta_vacia(vector[zona-1])) return NULL;
	pedido_t* pedido_sacado;
	pedido_sacado = cola_desencolar(vector[zona-1]);
	return pedido_sacado;	
	}
