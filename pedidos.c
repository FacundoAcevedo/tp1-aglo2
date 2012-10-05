#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "tdas.h"
#include "pedidos.h"
/*##############################################################*/
/*							SALIENTES*/
/*##############################################################*/

/*
 *#REVISAR DESTRUIR PEIDO, SU STRUCT NO TIENE MALLOC NI NADA
 */

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

// Imprime los ultimos n pedidos entregados
int printeo_salientes(pila_t* salientes, int n){
	if (pila_esta_vacia(salientes)){
		return 1;
	}
	int i = 0;
	pila_t* auxiliar = pila_crear();
	
	while ((i<n)&&(!pila_esta_vacia(salientes))){
		pedido_t* desapilado = pila_desapilar(salientes);
        printf("Pedido nro: %u \n Cantidad de pizzas: %d \n Zona: %d \n\n", 
			desapilado->id, desapilado->cant_pizzas, desapilado->zona);
		pila_apilar(auxiliar, desapilado);
		i += 1;
	}
	while(!pila_esta_vacia(auxiliar))
		pila_apilar(salientes, pila_desapilar(auxiliar));
	
	pila_destruir(auxiliar, destruir_pedido);

	return 0;
}
	



/*##############################################################*/
/*						ENTRANTES*/
/*##############################################################*/



// Structs
/*typedef struct pedido{*/
	/*int zona;*/
	/*int cant_pizzas;*/
	/*unsigned int id;*/
/*}pedido_t;*/

//~ // PARCHE - BORRAR EN FUTURO
//~ typedef struct nodo{
    //~ void* valor;
    //~ struct nodo* ref;
//~ } nodo_t;




// Funciones auxiliares
unsigned int get_random_id(void){
	unsigned int id	;
	id = rand() % (10001);
	return id;
}
/*
 *Busca sobre una lista, y devuelve un iterador donde hay un pedido.
 *PRE: recibe una pedidos_entrates_t con la lista de pedidos, y un unsigned int con el
 *id a buscar
 *POST: mueve el iter hasta el nodo donde esta ese id, si no lo encuentra, 
 *devuelve false o el iter de caso contrario
 */
lista_iter_t*  buscar_id(lista_t* pedidos_entrantes, unsigned int id){
    //variables
    pedido_t* act;
    unsigned int id_cmp;
    // Creo un iter
    lista_iter_t* iter;
    iter = lista_iter_crear(pedidos_entrantes);
    //Busco
    while(true){
        act = lista_iter_ver_actual(iter);
        id_cmp = act->id;
        if (id_cmp == id) return iter;
       lista_iter_avanzar(iter);     
		}
    return NULL;
}



// Funciones de pedido 
pedido_t* pedido_crear( int zona, int cant_pizzas){
	pedido_t* pedido;
	pedido = malloc(sizeof(pedido_t));
	if (pedido == NULL) return NULL;
	pedido->zona = zona;
	pedido->cant_pizzas = cant_pizzas;
	pedido->id = get_random_id();	
	return pedido;
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
lista_t* pedidos_entrantes_crear(){
	lista_t* pedidos_entrantes;
	pedidos_entrantes = lista_crear();
	return pedidos_entrantes;
	}
	
// devuelve la cantidad de pedidos que contiene la lista pedidos_entrantes
size_t pedidos_entrantes_largo(const lista_t* pedidos_entrantes){
	size_t largo;
	largo = lista_largo(pedidos_entrantes);
	return largo;
	}
	
// Agrega pedido al final de la lista.
bool pedidos_entrantes_agregar (lista_t* pedidos_entrantes, pedido_t* pedido){
	if (lista_insertar_ultimo(pedidos_entrantes, pedido)) return true;
	return false;
	}

// Saca el primer pedido de la lista.
// Recibe: struct pedidos_entrantes.
// Devuelve el dato del tipo pedido_t* que fue sacado de la lista.
pedido_t* pedidos_entrantes_sacar (lista_t* pedidos_entrantes){
	return (lista_borrar_primero(pedidos_entrantes));
	}

// Modifica la zona de un pedido.
// Recibe: struct pedidos_entrantes, un int con la nueva zona
// y un unsigned int id que identifica al pedido a modificar.
bool pedidos_entrantes_zona (lista_t* pedidos_entrantes, unsigned int id, int nueva_zona){
	if (lista_largo(pedidos_entrantes) == 0) return false;
	lista_iter_t* iter_pedido_a_modif;
	iter_pedido_a_modif = buscar_id(pedidos_entrantes, id);
	pedido_t* pedido_a_modif;
	pedido_a_modif = lista_iter_ver_actual(iter_pedido_a_modif);
	pedido_cambiar_zona(pedido_a_modif, nueva_zona);
	lista_iter_destruir(iter_pedido_a_modif);
	return true;
	}

// Modifica cant_pizzas de un pedido
// Recibe: struct pedidos_entrantes, un int con la nueva cantidad
// y un unsigned int id que identifica al pedido a modificar.
bool pedidos_entrantes_cant_pizzas (lista_t* pedidos_entrantes, unsigned int id, int nueva_cant){
	if (lista_largo(pedidos_entrantes) == 0) return false;
	lista_iter_t* iter_pedido_a_modif;
	iter_pedido_a_modif = buscar_id(pedidos_entrantes, id);
	pedido_t* pedido_a_modif;
	pedido_a_modif = lista_iter_ver_actual(iter_pedido_a_modif);
	pedido_cambiar_zona(pedido_a_modif, nueva_cant);
	lista_iter_destruir(iter_pedido_a_modif);
	return true;
	}
	
// Saca el pedido de la lista de pedidos_entrantes y lo destruye.
// Recibe: struct pedidos_entrantes, un unsigned int con el id del pedido
// a cancelar.
bool pedidos_entrantes_cancelar (lista_t* pedidos_entrantes, unsigned int id){
	if (lista_largo(pedidos_entrantes) == 0) return false;
	lista_iter_t* iter_pedido_a_cancelar;
	iter_pedido_a_cancelar = buscar_id(pedidos_entrantes, id);
	pedido_t* pedido_a_cancelar;
	pedido_a_cancelar = lista_borrar(pedidos_entrantes, iter_pedido_a_cancelar);
	pedido_destruir(pedido_a_cancelar);
	lista_iter_destruir(iter_pedido_a_cancelar);
	return true;
	}

// Destruyo la lista pedidos_entrantes
// Recibe: lista pedidos_entrantes
void pedidos_entrantes_destruir (lista_t* pedidos_entrantes){
	lista_destruir(pedidos_entrantes, destruir_pedido);
}
 
// Printea el historial de los pedidos entrantes
bool pedidos_lista_print (lista_t* lista_pedidos){
	if (!lista_pedidos) return false;
	if (lista_largo(lista_pedidos) == 0) return false;
	
	// Inicializo las listas por zona
	lista_t* zona1 = lista_crear(zona1);
	lista_t* zona2 = lista_crear(zona2);
	lista_t* zona3 = lista_crear(zona3);
	lista_t* zona4 = lista_crear(zona4);
	lista_t* zona5 = lista_crear(zona5);
	
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
		
	// Printeo las listas.
	puts("####################################################");
	puts("			Zona 1: \n");
	if (lista_esta_vacia(zona1)) puts ("0");
	else{
		lista_iter_t* iter1;
		iter1 = lista_iter_crear(zona1);
		pedido_t* actual;

		while (true){
			actual = lista_iter_ver_actual(iter1);
			printf("Pedido nro: %u \n Cantidad de pizzas: %d \n ",actual->id, actual->cant_pizzas);
			if (lista_iter_al_final(iter1)){
				lista_iter_destruir(iter1);
				break;
				}
			lista_iter_avanzar(iter1);
			}
		}
	
	puts("####################################################");
	puts("			Zona 2: \n");
	if (lista_esta_vacia(zona2)) puts ("0");
	else{
		lista_iter_t* iter2;
		iter2 = lista_iter_crear(zona2);
		pedido_t* actual;

		while (true){
			actual = lista_iter_ver_actual(iter2);
			printf("Pedido nro: %u \n Cantidad de pizzas: %d \n",actual->id, actual->cant_pizzas);
			if (lista_iter_al_final(iter2)){
				lista_iter_destruir(iter2);
				break;
				}
			lista_iter_avanzar(iter2);
			}
		}
	
	puts("####################################################");
	puts("			Zona 3: \n");
	if (lista_esta_vacia(zona3)) puts ("0");
	else{
		lista_iter_t* iter3;
		iter3 = lista_iter_crear(zona3);
		pedido_t* actual;

		while (true){
			actual = lista_iter_ver_actual(iter3);
			printf("Pedido nro: %u \n Cantidad de pizzas: %d \n",actual->id, actual->cant_pizzas);
			if (lista_iter_al_final(iter3)){
				lista_iter_destruir(iter3);
				break;
				}
			lista_iter_avanzar(iter3);
			}
		}
	
	puts("####################################################");
	puts("			Zona 4: \n");
	if (lista_esta_vacia(zona4)) puts ("0");
	else{
		lista_iter_t* iter4;
		iter4 = lista_iter_crear(zona4);
		pedido_t* actual;

		while (true){
			actual = lista_iter_ver_actual(iter4);
			printf("Pedido nro: %u \n Cantidad de pizzas: %d \n",actual->id, actual->cant_pizzas);
			if (lista_iter_al_final(iter4)){
				lista_iter_destruir(iter4);
				break;
				}
			lista_iter_avanzar(iter4);
			}
		}
	
	puts("####################################################");
	puts("			Zona 5: \n");
	if (lista_esta_vacia(zona5)) puts ("0");
	else{
		lista_iter_t* iter5;
		iter5 = lista_iter_crear(zona5);
		pedido_t* actual;

		while (true){
			actual = lista_iter_ver_actual(iter5);
			printf("Pedido nro: %u \n Cantidad de pizzas: %d \n",actual->id, actual->cant_pizzas);
			if (lista_iter_al_final(iter5)){
				lista_iter_destruir(iter5);
				break;
				}
			lista_iter_avanzar(iter5);
			}
		}
	
	return true;
	}
