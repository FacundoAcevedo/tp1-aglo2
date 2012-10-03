#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "listaycola.h"
/*#include "pila.h"*/
#include "zonas.h"
/*#include "pedidos_entrantes.h"*/
//~ #include "moto.h"
/*#include "lista_con_iter.h"*/

typedef  struct zona{
    cola_t* cola_ppal;
    lista_con_iter_t* lista_espera;

}zona_t;


struct zona{
	cola_t* cola_ppal;
	lista_con_iter_t* lista_espera;

}zona_t;
zona_t* zona_crear(){
	zona_t* zona = malloc(sizeof(zona_t));
	/*zona = malloc(sizeof(zona_t));*/
	if (zona == NULL) return NULL;
	cola_t* cola_ppal =  cola_crear();
	lista_con_iter_t* lista_espera = lista_con_iter_crear();
	zona->cola_ppal = cola_ppal;
	zona->lista_espera = lista_espera;
	return zona;
}

/*// Reparte todos los elementos de la lista de pedidos_entrantes entre las*/
/*// cinco zonas. */
/*bool zona_preparar_pedidos(zona_t** vector, lista_con_iter_t* pedidos_entrantes){*/
	/*// Si pedidos_entrantes no existe*/
	/*if (!pedidos_entrantes) return false;*/
	/*// Si la lista de pedidos_entrantes esta vacia*/
	/*if (pedidos_entrantes->lista == NULL) return false;*/
	/*int i;*/
	/*lista_t* lista = pedidos_entrantes->lista;*/
	/*// Reparto entre las zonas*/
	/*while (lista_largo(lista) >= 0){*/
		/*for (i=0; i<5; i++){*/
			/*if (lista_largo(lista) >= 0){*/
				/*pedido_t* pedido;*/
				/*pedido = pedidos_entrantes_sacar(pedidos_entrantes);*/
				/*cola_encolar(vector[i]->cola_ppal, pedido);*/
				/*}*/
			/*}*/
		/*}*/
	/*return true;*/
	/*}*/
/*//~ */
/*// Desencola un pedido de la cola principal de la zona que se pasa por parametro.*/
/*// Devuelve el pedido desencolado.*/
/*pedido_t* zona_sacar (zona_t** vector[], int zona){*/
	/*if (cola_esta_vacia((*vector[zona-1])->cola_ppal)) return NULL;*/
	/*pedido_t* pedido_sacado;*/
	/*pedido_sacado = cola_desencolar((*vector[zona-1])->cola_ppal);*/
	/*return pedido_sacado;	*/
	/*}*/
