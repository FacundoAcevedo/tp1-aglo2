#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "tdas.h"
#include "pedidos.h"
#include <string.h>

pila_t* salientes_crear(){
    pila_t* salientes;
    salientes = pila_crear();
    return salientes;
}

void pedido_destruir(pedido_t* pedido){
	free(pedido);
}

void (destruir_pedido)(void* dato) {
	pedido_destruir((pedido_t*)dato);
}

int printeo_salientes(pila_t* salientes, int n){
	if (pila_esta_vacia(salientes)){
		puts ("Aun no se han enviado pedidos.");
		return 1;
	}
	int i = 0;
	pila_t* auxiliar = pila_crear();
	
	while ((i<n)&&(!pila_esta_vacia(salientes))){
		pedido_t* desapilado = pila_desapilar(salientes);
        printf("Cliente: %s - Cantidad de pizzas: %d - Zona: %d - Distancia a la pizzeria: %d \n", 
			desapilado->id, desapilado->cant_pizzas, desapilado->zona, desapilado->distancia);
		pila_apilar(auxiliar, desapilado);
		i += 1;
	}
	while(!pila_esta_vacia(auxiliar))
		pila_apilar(salientes, pila_desapilar(auxiliar));
	
	pila_destruir(auxiliar, destruir_pedido);

	return 0;
}
	

lista_iter_t*  buscar_id(lista_t* pedidos_entrantes, char* id){
    //variables
    pedido_t* act;
    char id_cmp[MAX];
    // Creo un iter
    lista_iter_t* iter;
    iter = lista_iter_crear(pedidos_entrantes);
    //Busco
    int i = 1;
    while(i <= lista_largo(pedidos_entrantes)){
        act = lista_iter_ver_actual(iter);
		strcpy(id_cmp, act->id);
	    if (strcmp(id_cmp, id)==0)
			return iter;
       lista_iter_avanzar(iter);
       i +=1;
       }
    lista_iter_destruir(iter);
    return NULL;
}


pedido_t* pedido_crear( int zona, int distancia, int cant_pizzas, char* id){
	pedido_t* pedido;
	pedido = malloc(sizeof(pedido_t));
	if (pedido == NULL) return NULL;
	pedido->zona = zona;
	pedido->distancia = distancia;
	pedido->cant_pizzas = cant_pizzas;
	strcpy(pedido->id, id);
	return pedido;
}


bool pedido_cambiar_zona (pedido_t* pedido, int nueva_zona, int nueva_distancia){
	if (!pedido) return false;
	pedido->zona = nueva_zona;
	pedido->distancia = nueva_distancia;
	return true;
}
	
bool pedido_cambiar_cant (pedido_t* pedido, int nueva_cant){
	if (!pedido) return false;
	pedido->cant_pizzas = nueva_cant;
	return true;
}


lista_t* pedidos_entrantes_crear(){
	lista_t* pedidos_entrantes;
	pedidos_entrantes = lista_crear();
	return pedidos_entrantes;
}
	

size_t pedidos_entrantes_largo(const lista_t* pedidos_entrantes){
	size_t largo;
	largo = lista_largo(pedidos_entrantes);
	return largo;
}
	

bool pedidos_entrantes_agregar (lista_t* pedidos_entrantes, pedido_t* pedido){
	if (lista_insertar_ultimo(pedidos_entrantes, pedido))
		return true;
	return false;
}


pedido_t* pedidos_entrantes_sacar (lista_t* pedidos_entrantes){
	return (lista_borrar_primero(pedidos_entrantes));
}


bool pedidos_entrantes_zona (lista_t* pedidos_entrantes, char* id, int nueva_zona, int nueva_distancia){
	if (lista_largo(pedidos_entrantes) == 0) return false;
	lista_iter_t* iter_pedido_a_modif;
	iter_pedido_a_modif = buscar_id(pedidos_entrantes, id);
	pedido_t* pedido_a_modif;
	pedido_a_modif = lista_iter_ver_actual(iter_pedido_a_modif);
	pedido_cambiar_zona(pedido_a_modif, nueva_zona, nueva_distancia);
	lista_iter_destruir(iter_pedido_a_modif);
	return true;
}


bool pedidos_entrantes_cant_pizzas (lista_t* pedidos_entrantes, char* id, int nueva_cant){
	if (lista_largo(pedidos_entrantes) == 0) return false;
	lista_iter_t* iter_pedido_a_modif;
	iter_pedido_a_modif = buscar_id(pedidos_entrantes, id);
	pedido_t* pedido_a_modif;
	pedido_a_modif = lista_iter_ver_actual(iter_pedido_a_modif);
	pedido_cambiar_cant(pedido_a_modif, nueva_cant);
	lista_iter_destruir(iter_pedido_a_modif);
	return true;
}
	

bool pedidos_entrantes_cancelar (lista_t* pedidos_entrantes, char* id){
	if (lista_largo(pedidos_entrantes) == 0) return false;
	lista_iter_t* iter_pedido_a_cancelar;
	iter_pedido_a_cancelar = buscar_id(pedidos_entrantes, id);
	pedido_t* pedido_a_cancelar;
	pedido_a_cancelar = lista_borrar(pedidos_entrantes, iter_pedido_a_cancelar);
	pedido_destruir(pedido_a_cancelar);
	lista_iter_destruir(iter_pedido_a_cancelar);
	return true;
}


void pedidos_entrantes_destruir (lista_t* pedidos_entrantes){
	lista_destruir(pedidos_entrantes, destruir_pedido);
}
 

bool pedidos_lista_print (lista_t* lista_pedidos){
	if (!lista_pedidos) return false;
	if (lista_largo(lista_pedidos) == 0) return false;
	
	// Inicializo las listas por zona
	lista_t* zona1 = lista_crear();
	lista_t* zona2 = lista_crear();
	lista_t* zona3 = lista_crear();
	lista_t* zona4 = lista_crear();
	lista_t* zona5 = lista_crear();
	
	// inicio el iter
	lista_iter_t* iter;
    iter = lista_iter_crear(lista_pedidos);
	pedido_t* pedido;
	int i;
	i =0;
	
	// Separo los pedidos por zona
	while (i<lista_largo(lista_pedidos)){
		pedido = lista_iter_ver_actual(iter);
		if (pedido->zona == 1){
			lista_insertar_ultimo(zona1, pedido);
			i +=1;
			}
		else if (pedido->zona == 2){
			lista_insertar_ultimo(zona2, pedido);
			i +=1;
			}
		else if (pedido->zona == 3){
			lista_insertar_ultimo(zona3, pedido);
			i +=1;
			}
		else if (pedido->zona == 4){
			lista_insertar_ultimo(zona4, pedido);
			i +=1;
			}
		else if (pedido->zona == 5){
			lista_insertar_ultimo(zona5, pedido);
			i +=1;
			}
		if (lista_iter_al_final(iter)) break;
		lista_iter_avanzar(iter);
		}
	// Elimino el iter de lista_pedidos
	lista_iter_destruir(iter);
		
	// Printeo las listas.
	puts("=======================================================");
	puts("	Zona 1:");
	if (lista_esta_vacia(zona1)){
		lista_destruir(zona1,NULL);
		puts ("	0");
	}
	else{
		lista_iter_t* iter1;
		iter1 = lista_iter_crear(zona1);
		pedido_t* actual;

		while (true){
			actual = lista_iter_ver_actual(iter1);
			printf("Cliente: %s - Cantidad de pizzas: %d - Distancia a la pizzeria: %d \n",
				actual->id, actual->cant_pizzas, actual->distancia);
			if (lista_iter_al_final(iter1)){
				lista_iter_destruir(iter1);
				free(zona1);
				break;
				}
			lista_iter_avanzar(iter1);
			}
		}
	
	puts("	Zona 2:");
	if (lista_esta_vacia(zona2)){
		lista_destruir(zona2,NULL);
		puts ("	0");
	}
	else{
		lista_iter_t* iter2;
		iter2 = lista_iter_crear(zona2);
		pedido_t* actual;

		while (true){
			actual = lista_iter_ver_actual(iter2);
			printf("Cliente: %s - Cantidad de pizzas: %d - Distancia a la pizzeria: %d \n",
				actual->id, actual->cant_pizzas, actual->distancia);
			if (lista_iter_al_final(iter2)){
				lista_iter_destruir(iter2);
				free(zona2);
				break;
				}
			lista_iter_avanzar(iter2);
			}
		}
	
	puts("	Zona 3:");
	if (lista_esta_vacia(zona3)){
		lista_destruir(zona3, NULL);
		puts ("	0");
	 }
	else{
		lista_iter_t* iter3;
		iter3 = lista_iter_crear(zona3);
		pedido_t* actual;

		while (true){
			actual = lista_iter_ver_actual(iter3);
			printf("Cliente: %s - Cantidad de pizzas: %d - Distancia a la pizzeria: %d \n",
				actual->id, actual->cant_pizzas, actual->distancia);
			if (lista_iter_al_final(iter3)){
				lista_iter_destruir(iter3);
				free(zona3);
				break;
				}
			lista_iter_avanzar(iter3);
			}
		}
	
	puts("	Zona 4:");
	if (lista_esta_vacia(zona4)){
		lista_destruir(zona4, NULL);
		puts ("	0");
	}
	else{
		lista_iter_t* iter4;
		iter4 = lista_iter_crear(zona4);
		pedido_t* actual;

		while (true){
			actual = lista_iter_ver_actual(iter4);
			printf("Cliente: %s - Cantidad de pizzas: %d - Distancia a la pizzeria: %d \n",
				actual->id, actual->cant_pizzas, actual->distancia);
			if (lista_iter_al_final(iter4)){
				lista_iter_destruir(iter4);
				free(zona4);
				break;
				}
			lista_iter_avanzar(iter4);
			}
		}
	puts("	Zona 5:");
	if (lista_esta_vacia(zona5)){
		lista_destruir(zona5,NULL);
		puts ("	0");
	}
	else{
		lista_iter_t* iter5;
		iter5 = lista_iter_crear(zona5);
		pedido_t* actual;

		while (true){
			actual = lista_iter_ver_actual(iter5);
			printf("Cliente: %s - Cantidad de pizzas: %d - Distancia a la pizzeria: %d \n",
				actual->id, actual->cant_pizzas, actual->distancia);
			if (lista_iter_al_final(iter5)){
				lista_iter_destruir(iter5);
				free(zona5);
				break;
				}
			lista_iter_avanzar(iter5);
			}
		}
	puts("=======================================================");
	return true;
}
