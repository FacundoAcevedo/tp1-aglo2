#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "zonasymoto.h"
#include "tdas.h"
#include "pedidos.h"
#include "pantalla.h"


void zonas_destruir(lista_t* zonas, void destruir_pedido(void*)){
	lista_destruir(zonas, (*destruir_pedido));
	return;
	}

bool zona_preparar_pedidos(lista_t* zonas, lista_t* pedidos_entrantes){
	// Si pedidos_entrantes no existe
	if (!pedidos_entrantes) return false;
	// Si la lista de pedidos_entrantes esta vacia
	if (lista_esta_vacia(pedidos_entrantes)) return false;
	// Reparto entre las zonas
	while (lista_largo(pedidos_entrantes) > 0){
		pedido_t* pedido;
		pedido = pedidos_entrantes_sacar(pedidos_entrantes);
		lista_insertar_ultimo(zonas, pedido);
		}
	return true;
	}


// Recibe la zona a la cual se quiere enviar las pizzas. Devuelve una moto
// ordenada del tipo lista_t*.
lista_t* moto_cargar(lista_t* zonas, pila_t* salientes){
	// Si no hay pedidos para las zonas devuelvo NULL.
	if (lista_esta_vacia(zonas)) return false;

	// Creo la moto
	lista_t* moto = lista_crear();
	size_t cant_en_moto;
	cant_en_moto = lista_largo(moto);
	// Creo un iterador de zonas.
	lista_iter_t* iter;
	iter = lista_iter_crear(zonas);
	// Guardo su largo para usarlo como condicion de corte
	int num_iter;
	num_iter = 0;
	
	pedido_t* pedido;
	pedido = lista_iter_ver_actual(iter);
	
	// Determino la zona para la cual enviare la moto
	int zona;
	zona = pedido->zona;
	
	// Agrego este pedido en la moto y lo saco de la lista zonas
	lista_insertar_primero(moto, pedido);
	pila_apilar(salientes, pedido);

	lista_borrar(zonas, iter);
		
	cant_en_moto += pedido->cant_pizzas;

	while (cant_en_moto < 5){
		
		pedido_t* actual = lista_iter_ver_actual(iter);
		int suma;
		suma = cant_en_moto + actual->cant_pizzas;
		if ((suma <= 5) && (actual->zona == zona)){
			cant_en_moto += actual->cant_pizzas;
			lista_insertar_primero(moto, actual);
			lista_borrar(zonas, iter);
			// Apilo este pedido a pedidos_salientes
			pila_apilar(salientes, actual);

			// Si llegue a la capacidad maxima, ordeno la moto y la retorno 
			if ((cant_en_moto) == 5){
				lista_t* moto_ordenada= moto_ordenar(moto);
				return moto_ordenada;
			}
		}
		
		// el pedido actual no cumplio los requisitos de zona y/o pedido,
		// paso al siguiente. Condicion: no estar al final de la lista.
		// Si llegue al final, corto el while.
		num_iter += 1;
		if (num_iter <= (int)lista_largo(zonas)){
			lista_iter_avanzar(iter);
		}
		if (num_iter > (int)lista_largo(zonas)){
			break;
		}
	}
	lista_t* moto_ordenada = moto_ordenar(moto);
	return moto_ordenada;
}



// Algoritmo de ordenamiento para la moto segun la distancia de cada pedido

lista_t* moto_ordenar(lista_t* moto){
	lista_t* orden = lista_crear();
	while (!lista_esta_vacia(moto)){
		pedido_t* borrado = lista_borrar_primero(moto);
		// Si la lista ordenada esta vacia, inserto
		if (lista_esta_vacia(orden)) lista_insertar_primero(orden, borrado);
		// SI la lista ordenada tiene 1 elemento
		else if (lista_largo(orden) == 1){
			lista_iter_t* iter = lista_iter_crear(orden);
			pedido_t* pedido = lista_iter_ver_actual(iter);
			int dist = pedido->distancia;
			// Si el que tengo que insertar es mayor al elemento de la lista ordenada
			// lo inserto en el 2do lugar con insertar_ultimo
			if (borrado->distancia >= dist) 
				lista_insertar_ultimo(orden, borrado);
			// Si es menor, lo inserto en el primer lugar
			else if (borrado->distancia < dist) 
				lista_insertar_primero(orden, borrado);
			lista_iter_destruir(iter);
		}
			// Si la lista ordenada tiene mas de un elemento:
		else{
			// Recorro la lista buscando un valor mayor 
			int i = 0;
			while(i<lista_largo(moto)){
				lista_iter_t* iter_orden = lista_iter_crear(orden);
				pedido_t* actual = lista_iter_ver_actual(iter_orden);
				// si encuentro un valor mayor, inserto antes de el
				// y corto este while
				if (actual->distancia > borrado->distancia){
					lista_insertar(orden, iter_orden, borrado);
					lista_iter_destruir(iter_orden);
					break;
				}
				// Si llegue al final y no encontre mayor, inserto en ultimo lugar
				lista_insertar_ultimo(orden, borrado);
				lista_iter_avanzar(iter_orden);
				i +=1;
			}
		}
	}
	lista_destruir(moto, destruir_pedido);
	return orden;
}
	
