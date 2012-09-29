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

cola_t** vector[] = {*zona1, *zona2, *zona3, *zona4, *zona5};

bool zona_preparar_pedidos(cola_t** vector[], pedidos_entrantes_t* pedidos){
	if (!pedidos_entrantes) return false;
	if (pedidos_entrantes->lista == NULL) return false;
	int i;
	lista_t* lista = pedidos_entrantes->lista;
	while (lista->tamanio >= 0){
		for (i=0, i<5, i++){
			if (lista->tamanio >= 0){
				pedido_t* pedido;
				pedido = pedidos_entrantes_sacar(lista);
				cola_apilar(vector[i], pedido);
				}
			}
		}
	return true;
	}
