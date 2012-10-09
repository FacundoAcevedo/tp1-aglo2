#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "preparadosymoto.h"
#include "tdas.h"
#include "pedidos.h"
#include "pantalla.h"



bool pedidos_preparar(lista_t* preparados, lista_t* pedidos_entrantes){
	// Si pedidos_entrantes no existe
	if (!pedidos_entrantes) return false;
	// Si la lista de pedidos_entrantes esta vacia
	if (lista_esta_vacia(pedidos_entrantes)) return false;
	// Reparto entre las preparados
	while (lista_largo(pedidos_entrantes) > 0){
		pedido_t* pedido;
		pedido = pedidos_entrantes_sacar(pedidos_entrantes);
		lista_insertar_ultimo(preparados, pedido);
		}
	return true;
	}


lista_t* moto_cargar(lista_t* preparados, pila_t* salientes){
	// Si no hay pedidos para las preparados devuelvo NULL.
	if (lista_esta_vacia(preparados)) return false;

	// Creo la moto
	lista_t* moto = lista_crear();
	size_t cant_en_moto;
	cant_en_moto = lista_largo(moto);
	// Creo un iterador de preparados.
	lista_iter_t* iter;
	iter = lista_iter_crear(preparados);
	// Guardo su largo para usarlo como condicion de corte
	int num_iter;
	num_iter = 0;
	
	pedido_t* pedido;
	pedido = lista_iter_ver_actual(iter);
	
	// Determino la zona para la cual enviare la moto
	int zona;
	zona = pedido->zona;
	
	// Agrego este pedido en la moto y lo saco de la lista preparados
	lista_insertar_primero(moto, pedido);
	pila_apilar(salientes, pedido);

	lista_borrar(preparados, iter);
		
	cant_en_moto += pedido->cant_pizzas;

	while (cant_en_moto < 5){
		
		pedido_t* actual = lista_iter_ver_actual(iter);
		int suma;
		suma = cant_en_moto + actual->cant_pizzas;
		if ((suma <= 5) && (actual->zona == zona)){
			cant_en_moto += actual->cant_pizzas;
			lista_insertar_primero(moto, actual);
			lista_borrar(preparados, iter);
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
		if (num_iter <= (int)lista_largo(preparados)){
			lista_iter_avanzar(iter);
		}
		if (num_iter > (int)lista_largo(preparados)){
			break;
		}
	}
	lista_t* moto_ordenada = moto_ordenar(moto);
	return moto_ordenada;
}


lista_t* moto_ordenar(lista_t* moto){
	lista_t* orden = lista_crear();
	int c = 0;
    int largo_1 = lista_largo(moto);
	/*while (c< lista_largo(moto)){*/
        
	while (c< largo_1){
         printf("#### LARGO %d\n",largo_1);
		pedido_t* borrado = lista_borrar_primero(moto);
		// Si la lista ordenada esta vacia, inserto
		if (lista_esta_vacia(orden)) {
            lista_insertar_primero(orden, borrado);
		    puts("a insert");
		}
		// SI la lista ordenada tiene 1 elemento
		else if (lista_largo(orden) == 1){
			lista_iter_t* iter = lista_iter_crear(orden);
			pedido_t* pedido = lista_iter_ver_actual(iter);
			int dist = pedido->distancia;
			// Si el que tengo que insertar es mayor al elemento de la lista ordenada
			// lo inserto en el 2do lugar con insertar_ultimo
			if (borrado->distancia >= dist) {
				lista_insertar_ultimo(orden, borrado);
				puts("b insert");
			}
			// Si es menor, lo inserto en el primer lugar
			/*else if (borrado->distancia < dist) {*/
			else  {
				lista_insertar_primero(orden, borrado);
				puts ("c insert");
			}
			lista_iter_destruir(iter);
		}
			// Si la lista ordenada tiene mas de un elemento:
	if (lista_largo(orden)>1){
			// Recorro la lista buscando un valor mayor 
			int i = 0;
			/*while(i<lista_largo(moto)){*/
			while(i<largo_1){
				lista_iter_t* iter_orden = lista_iter_crear(orden);
				pedido_t* actual = lista_iter_ver_actual(iter_orden);
				// si encuentro un valor mayor, inserto antes de el
				// y corto este while
				if (actual->distancia > borrado->distancia){
					lista_insertar(orden, iter_orden, borrado);
							puts("d insert");
					lista_iter_destruir(iter_orden);
					break;
				}
				// Si llegue al final y no encontre mayor, inserto en ultimo lugar
				lista_insertar_ultimo(orden, borrado);
						puts("e insert");
				lista_iter_avanzar(iter_orden);
				i +=1;
			}//while
		}//if
		c += 1;
	}//while
	lista_destruir(moto, NULL);
	return orden;
}
	
