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
	if (lista_esta_vacia(preparados))
		return false;
	
	// Creo la moto
	lista_t* moto = lista_crear();
	size_t cant_en_moto;
	cant_en_moto = lista_largo(moto);
	// Creo un iterador de preparados.
	lista_iter_t* iter = lista_iter_crear(preparados);
	// Guardo su largo para usarlo como condicion de corte
	int num_iter = 0;
	pedido_t* pedido = lista_iter_ver_actual(iter);
	// Determino la zona para la cual enviare la moto
	int zona = pedido->zona;
	
	// Agrego este pedido en la moto y lo saco de la lista preparados
	lista_insertar_primero(moto, pedido);
	pila_apilar(salientes, pedido);

	lista_borrar(preparados, iter);
		
	cant_en_moto += pedido->cant_pizzas;

	while (cant_en_moto < 5){
		
		pedido_t* actual = lista_iter_ver_actual(iter);
		if(actual == NULL) break;
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
			//~ printf("largo preparados: %d", lista_largo(preparados));
			lista_iter_avanzar(iter);
		}
		if (num_iter > (int)lista_largo(preparados)){
			break;
		}
	}
	lista_t* moto_ordenada = moto_ordenar(moto);
	lista_iter_destruir(iter);
	return moto_ordenada;
}


lista_t* moto_ordenar(lista_t* lista){
	lista_t* ordenada = lista_crear();
	pedido_t* actual;
	
	while (lista_largo(lista) > 0 ){
	//~ puts("entre al primer while");
	//~ printf("Largo de lista: %d", lista_largo(lista));
		pedido_t* pedido = lista_borrar_primero(lista);
	
		if (lista_largo(ordenada) == 0){
			lista_insertar_ultimo(ordenada, pedido);
		}

		else if (lista_largo(ordenada) == 1){
			//~ puts("entre al primer elseif");
			actual = lista_ver_primero(ordenada);
			if (pedido->distancia >= actual->distancia){
				lista_insertar_ultimo(ordenada, pedido);
				}
			else {
			lista_insertar_primero(ordenada, pedido);
			}
			//~ puts("termine el primer elseif");
		}

		else if (lista_largo(ordenada) > 1){
			//~ puts("Entre largo ordenada >1");
			lista_iter_t* iter_ord = lista_iter_crear(ordenada);
			int largo_ord = lista_largo(ordenada); //puts ("creo un iter");
			int i = 0;
			while ((i < largo_ord)&&(lista_largo(lista)>0)){
				pedido_t* actual = lista_iter_ver_actual(iter_ord);
				//~ printf("actual = %p", actual);
				pedido_t* pedido = lista_borrar_primero(lista);
				if (pedido->distancia > actual->distancia){
					lista_insertar(ordenada, iter_ord, pedido);
					lista_iter_destruir(iter_ord); //puts("destruyo un iter");
					break;
					}
			i += 1;
			
			}
			lista_insertar_ultimo(ordenada, pedido);
			lista_iter_destruir(iter_ord); //puts("destruyo un iter");
		}
	}

	lista_destruir(lista, NULL);
	return ordenada;
}
	
