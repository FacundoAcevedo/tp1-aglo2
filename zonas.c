#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "listaycola.h"
//~ #include "pila.h"
//~ #include "zonas.h"
//~ #include "pedidos_entrantes.h"
//~ #include "moto.h"
//~ #include "lista_con_iter.h"

typedef struct zona{
	cola_t* cola_ppal;
	//~ lista_con_iter_t* lista_espera;

}zona_t;


zona_t* zona_crear(){
	zona_t* zone;
	zone = malloc(sizeof(zona_t));
	if (zone == NULL) return NULL;
	cola_t* cola_ppal;
	cola_ppal = cola_crear();
	//~ lista_con_iter_t* lista_espera;
	//~ lista_espera = lista_con_iter_crear();
	zone->cola_ppal = cola_ppal;
	//~ zone->lista_espera = lista_espera;

	return zone;
}

zona_t* zona1;
zona1 = zona_crear();
// Creo las zonas
//~ zona_t* zona1;
//~ zona_t* zona2;
//~ zona_t* zona3;
//~ zona_t* zona4;
//~ zona_t* zona5;

// Creo un vector con las 5 zonas
//~ zona_t** vector[] = {*zona1, *zona2, *zona3, *zona4, *zona5};
//~ 
//~ // Reparte todos los elementos de la lista de pedidos_entrantes entre las
//~ // cinco zonas. 
//~ bool zona_preparar_pedidos(zona_t** vector, lista_con_iter_t* pedidos_entrantes){
	//~ // Si pedidos_entrantes no existe
	//~ if (!pedidos_entrantes) return false;
	//~ // Si la lista de pedidos_entrantes esta vacia
	//~ if (pedidos_entrantes->lista == NULL) return false;
	//~ int i;
	//~ lista_t* lista = pedidos_entrantes->lista;
	//~ // Reparto entre las zonas
	//~ while (lista_largo(lista) >= 0){
		//~ for (i=0; i<5; i++){
			//~ if (lista_largo(lista) >= 0){
				//~ pedido_t* pedido;
				//~ pedido = pedidos_entrantes_sacar(pedidos_entrantes);
				//~ cola_encolar(vector[i]->cola_ppal, pedido);
				//~ }
			//~ }
		//~ }
	//~ return true;
	//~ }

//~ // Desencola un pedido de la cola principal de la zona que se pasa por parametro.
//~ // Devuelve el pedido desencolado.
//~ pedido_t* zona_sacar (zona_t** vector[], int zona){
	//~ if (cola_esta_vacia((*vector[zona-1])->cola_ppal)) return NULL;
	//~ pedido_t* pedido_sacado;
	//~ pedido_sacado = cola_desencolar((*vector[zona-1])->cola_ppal);
	//~ return pedido_sacado;	
	//~ }
