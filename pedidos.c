#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "tdas.h"
#include "pedidos.h"
/*##############################################################*/
/*SALIENTES*/
/*##############################################################*/

pila_t* salientes_crear(){
    pila_t* salientes;
    salientes = pila_crear();
    return salientes;
    }
	
int printeo_salientes(pila_t* salientes){
	int i;
	i = 0;
	pila_t* copia;
	copia = salientes;
	while (!pila_esta_vacia(copia)){
		pedido_t* desapilado;
		desapilado = pila_desapilar(copia);
		/*printf("Pedido nro: %u \n Cantidad de pizzas: %d \n Zona: %d \n\n",desapilado->id, desapilado->cant_pizzas, desapilado->zona);*/
		}
	pila_destruir(copia, NULL);
	
	
	}
	

void salientes_destruir(pila_t* salientes, void pedido_destruir (void*)){
	pila_destruir(salientes, pedido_destruir);
}



/*##############################################################*/
/*ENTRANTES*/
/*##############################################################*/



// Structs
/*typedef struct pedido{*/
	/*int zona;*/
	/*int cant_pizzas;*/
	/*unsigned int id;*/
/*}pedido_t;*/

// PARCHE - BORRAR EN FUTURO
typedef struct nodo{
    void* valor;
    struct nodo* ref;
} nodo_t;




// Funciones auxiliares
unsigned int get_id(pedido_t* pedido){
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
lista_iter_t*  buscar_id(lista_con_iter_t* pedidos_entrantes, unsigned int id)
{
    //variables
    lista_t* lista = (*pedidos_entrantes)->lista;
    lista_iter_t* iter = pedidos_entrantes->iter;
    nodo_t* act;
    unsigned int id_cmp;


    //reinicio el iter
    lista_iter_destruir(iter);
    lista_iter_t* iter1;
    iter1 = lista_iter_crear(lista);

    //Busco
    while(true){
        act = lista_iter_ver_actual(iter1);
        pedido_t* pedido;
        pedido = act->valor;
        id_cmp = pedido->id;
        
        if (id_cmp == id)
            return iter1;
        else if (act->ref == NULL)
            break;

       lista_iter_avanzar(iter1);     
		}
	pedidos_entrantes->iter = iter1;
    return NULL;
}



// Funciones de pedido 
pedido_t* pedido_crear( int zona, int cant_pizzas){
	pedido_t* pedido;
	pedido = malloc(sizeof(pedido_t));
	if (pedido == NULL) return NULL;
	pedido->zona = zona;
	pedido->cant_pizzas = cant_pizzas;
	pedido->id = get_id(pedido);	
	return pedido;
	}

void pedido_destruir(pedido_t* pedido){
	free(pedido);
	}

void (destruir_pedido)(void*dato){
	pedido_destruir((pedido_t*)dato);
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
lista_con_iter_t* pedidos_entrantes_crear(){
	lista_con_iter_t* pedidos_entrantes;
	pedidos_entrantes = lista_con_iter_crear();
	return pedidos_entrantes;
	}
	
// devuelve la cantidad de pedidos que contiene la lista pedidos_entrantes
size_t pedidos_entrantes_largo(const lista_con_iter_t* pedidos_entrantes){
	size_t largo;
	largo = lista_largo(pedidos_entrantes->lista);
	return largo;
	}
	
// Agrega pedido al final de la lista.
bool pedidos_entrantes_agregar (lista_con_iter_t* pedidos_entrantes, pedido_t* pedido){
	if (lista_insertar_ultimo(pedidos_entrantes->lista, pedido)) return true;
	return false;
	}

// Saca el primer pedido de la lista.
// Recibe: struct pedidos_entrantes.
// Devuelve el dato del tipo pedido_t* que fue sacado de la lista.
pedido_t* pedidos_entrantes_sacar (lista_con_iter_t* pedidos_entrantes){
	return (lista_borrar_primero(pedidos_entrantes->lista));
	}

// Modifica la zona de un pedido.
// Recibe: struct pedidos_entrantes, un int con la nueva zona
// y un unsigned int id que identifica al pedido a modificar.
bool pedidos_entrantes_zona (lista_con_iter_t* pedidos_entrantes, unsigned int id, int nueva_zona){
	if (lista_largo(pedidos_entrantes->lista) == 0) return false;
	lista_iter_t* iter_pedido_a_modif;
	iter_pedido_a_modif = buscar_id(pedidos_entrantes, id);
	pedido_t* pedido_a_modif;
	pedido_a_modif = lista_iter_ver_actual(iter_pedido_a_modif);
	pedido_cambiar_zona(pedido_a_modif, nueva_zona);
	return true;
	}

// Modifica cant_pizzas de un pedido
// Recibe: struct pedidos_entrantes, un int con la nueva cantidad
// y un unsigned int id que identifica al pedido a modificar.
bool pedidos_entrantes_cant_pizzas (lista_con_iter_t* pedidos_entrantes, unsigned int id, int nueva_cant){
	if (lista_largo(pedidos_entrantes->lista) == 0) return false;
	lista_iter_t* iter_pedido_a_modif;
	iter_pedido_a_modif = buscar_id(pedidos_entrantes, id);
	pedido_t* pedido_a_modif;
	pedido_a_modif = lista_iter_ver_actual(iter_pedido_a_modif);
	pedido_cambiar_zona(pedido_a_modif, nueva_cant);
	return true;
	}
	
// Saca el pedido de la lista de pedidos_entrantes y lo destruye.
// Recibe: struct pedidos_entrantes, un unsigned int con el id del pedido
// a cancelar.
bool pedidos_entrantes_cancelar (lista_con_iter_t* pedidos_entrantes, unsigned int id){
	if (lista_largo(pedidos_entrantes->lista) == 0) return false;
	lista_iter_t* iter_pedido_a_cancelar;
	iter_pedido_a_cancelar = buscar_id(pedidos_entrantes, id);
	pedido_t* pedido_a_cancelar;
	pedido_a_cancelar = lista_borrar(pedidos_entrantes->lista, iter_pedido_a_cancelar);
	pedido_destruir(pedido_a_cancelar);
	return true;
	}

// Destruyo el struct pedidos_entrantes
// Recibe: struct pedidos_entrantes
void pedidos_entrantes_destruir (lista_con_iter_t* pedidos_entrantes){
	lista_con_iter_destruir(pedidos_entrantes, (*destruir_pedido));
	
    return;
 }
 

bool pedidos_entrantes_print (lista_con_iter_t* pedidos_entrantes){
	if (!pedidos_entrantes) return false;
	lista_t* lista;
	lista = pedidos_entrantes->lista;
	if (lista_largo(lista) == 0){
		puts ("No hay pedidos entrantes por preparar.\n");
		return true;
		}
	
	// Reinicio el iter
	lista_iter_destruir(pedidos_entrantes->iter);
    lista_iter_t* iter1;
    iter1 = lista_iter_crear(lista);
	
	while (lista_iter_avanzar(iter1)){
		pedido_t* pedido;
		pedido = lista_iter_ver_actual(iter1);
		printf("Pedido nro: %u \n Cantidad de pizzas: %d \n Zona: %d \n\n",pedido->id, pedido->cant_pizzas, pedido->zona);
		lista_iter_avanzar(iter1);
		}
		
	pedidos_entrantes->iter = iter1;
	return true;
	}
