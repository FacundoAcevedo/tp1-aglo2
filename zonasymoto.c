#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "zonasymoto.h"
#include "listaycolas.h"

//########################################################################
//				FUNCIONES DE ZONAS
//########################################################################


struct zona{
	cola_t* cola_ppal;
	lista_con_iter_t* lista_espera;
};

zona_t* zona_crear(){
	zona_t* zone;
	zone = malloc(sizeof(zona_t));
	if (zone == NULL) return NULL;
	cola_t* cola_ppal;
	cola_ppal = cola_crear();
	lista_con_iter_t* lista_espera;
	lista_espera = lista_con_iter_crear();
	zone->cola_ppal = cola_ppal;
	zone->lista_espera = lista_espera;

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
// Reparte todos los elementos de la lista de pedidos_entrantes entre las
// cinco zonas. 
bool zona_preparar_pedidos(zona_t** vector, lista_con_iter_t* pedidos_entrantes){
	// Si pedidos_entrantes no existe
	if (!pedidos_entrantes) return false;
	// Si la lista de pedidos_entrantes esta vacia
	if (pedidos_entrantes->lista == NULL) return false;
	int i;
	lista_t* lista = pedidos_entrantes->lista;
	// Reparto entre las zonas
	while (lista_largo(lista) >= 0){
		for (i=0; i<5; i++){
			if (lista_largo(lista) >= 0){
				pedido_t* pedido;
				pedido = pedidos_entrantes_sacar(pedidos_entrantes);
				cola_encolar(vector[i]->cola_ppal, pedido);
				}
			}
		}
	return true;
	}

// Desencola un pedido de la cola principal de la zona que se pasa por parametro.
// Devuelve el pedido desencolado.
pedido_t* zona_sacar (zona_t** vector[], int zona){
	if (cola_esta_vacia((*vector[zona-1])->cola_ppal)) return NULL;
	pedido_t* pedido_sacado;
	pedido_sacado = cola_desencolar((*vector[zona-1])->cola_ppal);
	return pedido_sacado;	
	}



//########################################################################
//				FUNCIONES DE MOTO
//########################################################################


pila_t* pedidos_salientes;

// Recibe la zona a la cual se quiere enviar las pizzas. Devuelve una moto
// tipo pila_t*.
pila_t* moto_cargar(zona_t* zona){
	// Creo la moto
	pila_t* moto = pila_crear();
	cola_t* cola_ppal;
	cola_ppal = zona->cola_ppal;
	if (cola_esta_vacia(cola_ppal)){
		// Si no hay pedidos para la zona (ni en la cola principal ni en 
		// la lista de espera), devuelvo NULL.
		if (lista_esta_vacia(zona->lista_espera->lista)) return NULL;
		
		// Llamo a intentar_lista_espera para llenar la moto con los pedidos
		// de lista_espera
		int pizzas_cargadas;
		pizzas_cargadas = intentar_lista_espera(zona, moto);
		// Si se cargaron 5 pizzas, el pedido esta listo para salir.########## VER ##########
		// Devuelvo la moto.########## VER ##########
		if (pizzas_cargadas == 5) return moto;########## VER ##########
		// Si se cargaron menos de 5 pizzas, la moto no sale. ########## VER ##########
		return NULL; //########## VER ##########
		
		// Permito salir a la moto aun si tiene menos de 5 pizzas. ########## VER ##########
		return moto;
		}
	intentar_cola_ppal(zona, moto);
	
	// Apilo esta moto en pedidos_salientes
	pila_apilar(pedidos_salientes, moto);
	return moto;
	
	}



// Recibe la lista de espera de una zona y un int "pizzas_cargadas con la cantidad de pizzas
// que ya tiene cargada la moto. Itera sobre la lista buscando un pedido
// cuyo valor de cant_pizzas sea (5 - pizzas_cargadas) o menor. Si lo encuentra,
// lo borra de la lista y lo devuelve. Si no lo encuentra, devuelve NULL. 
pedido_t* buscar_adecuado (lista_con_iter_t* lista_espera, int pizzas_cargadas) {
	
	// Reinicio el iter a la pos 0.
	lista_espera->iter->actual = lista_espera->lista->inicio;
	lista_espera->iter->siguiente = lista_espera->lista->inicio->siguiente;
	
	
	lista_iter_t* actual;
	actual = lista_iter_ver_actual(lista_espera->iter);
	if (actual->valor->cant_pizzas <= (5-pizzas_cargadas){
		pedido_t* sacado;
		sacado = lista_borrar(lista_espera->lista, lista_espera->iter);
		return sacado;
		}
	return NULL;
	}
// Intenta poner en la moto los pedidos de la lista de espera. Para elegir
// los pedidos adecuardos de la lista de espera, llama a buscar_adecuado.
// Recibe lista_con_iter_t* zona, devuelve nada si buscar_adecuado no
// encontro ningun pedido adecuado, devuelve un int cont con la cantidad de
// pizzas que se han cargado en la moto.
int intentar_lista_espera(lista_con_iter_t* zona, pila_t* moto){
	// Inicio el contador de pizzas que se cargan a la moto.
	int cont;
	cont = 0;
	pedido_t* pedido;
	while (true){
		// Guardo lo que devuelve buscar_adecuado
		pedido = buscar_adecuado(zona, cont);
		// Si buscar_adecuado devolvio NULL, significa que no hay pedidos 
		// en la lista de espera que puedan apilarse en la moto. Finalizo
		// la funcion.
		if (pedido==NULL) return;
		// Sino, apilo el pedido en la moto.
		pila_apilar(moto, pedido);
		// Le sumo al contador la cantidad de pizzas que tiene el pedido
		// recien apilado. No hay peligro de que el contador se pase de
		// 5 porque eso ya lo previo buscar_adecuado.
		cont += pedido->cant_pizzas;
		// El bucle se vuelve a ejecutar hasta que buscar_adecuado devuelva
		// NULL con el contador que le pasamos.
		}
	// Devuelvo el contador.
	return cont;
	}

// Intenta poner en la moto los pedidos de cola_ppal. Recibe la zona,
// y la moto (pila_t*).
int intentar_cola_ppal(lista_con_iter_t* zona, pila_t* moto){
	pedido_t* desencolado;
	pedido_t* primero;
	int cont;
	// Inicio el contador con la cantidad de pizzas que tiene la moto
	cont = moto->cantidad;
			
	while (true){
		// Miro el primer pedido de la cola_ppal
		primero = cola_ver_primero(zona->cola_ppal);
		// Estimo cuantas pizzas tendria en la moto si le agregara el pedido
		// "primero".
		cont = cont + primero->cant_pizzas;
		
		// Si agregando "primero" a la moto llegaria a tener 5 pizzas:
		if (cont == 5){
			// Desencolo el pedido "primero" de cola_ppal
			desencolado = cola_desencolar(zona->cola_ppal);
			// Lo apilo a la moto
			pila_apilar(moto, desencolado);
			// devuelvo cont (cont = 5)
			return cont;
			}
		// Si agregando "primero" a la moto me pasaria de las 5 pizzas:
		if (cont > 5){
			// Desencolo el pedido "primero" de cola_ppal
			desencolado = cola_desencolar(zona->cola_ppal);
			// Lo encolo en la lista de espera
			lista_insertar_ultimo(zona->lista_espera, desencolado);
			// Reviso la lista de espera.
			int i;
			i = intentar_lista_espera(zona, moto);
			// Si intentar_lista_espera me devolvio NULL, quiere decir que
			// puedo seguir mirando los pedidos de la cola_ppal.
			if (i == NULL) continue;
			// Si intentar_lista_espera me devolvio un numero distinto 
			// de NULL, quiere decir que pudo apilar en la moto al menos
			// un pedido de lista_espera. Actualizo el contador y si es
			// 5, return cont (finalizo esta funcion). Si todavia no 
			// llegue a 5, vuelvo a iniciar este while.
			if (i != NULL) {
				cont += i;
				if (cont == 5) return cont;
				}
			}
		}
	return cont;
	}
	

void moto_destruir (pila_t* moto, void destruir_pedido(void *)){
	pila_destruir(moto, (*destruir_pedido));
	return;
	}
