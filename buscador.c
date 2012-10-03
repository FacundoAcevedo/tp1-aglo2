
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
//~ #include "cola.h"
//~ #include "pila.h"
//~ #include "pedidos_entrantes.h"
//~ #include "zonas.h"
//~ #include "moto.h"
#include "lista_con_iter.h"

// PARCHE - BORRAR EN FUTURO
typedef struct pedido{
	int zona;
	int cant_pizzas;
	unsigned int id;
}pedido_t;


// PARCHE - BORRAR EN FUTURO
typedef struct nodo{
    void* valor;
    struct nodo* ref;
} nodo_t;
/*
 *Busca sobre una lista, y devuelve un pedido.
 *PRE: recibe una pedidos_entrates_t con la lista de pedidos, y un unsigned int con el
 *id a buscar
 *POST: mueve el iter hasta el nodo donde esta ese id, si no lo encuentra, 
 *devuelve false o true de caso contrario
 */
pedido_t*  buscar_id(lista_con_iter_t* pedidos, unsigned int id)
{
    //variables
    lista_t* lista = pedidos->lista;
    lista_iter_t* iter = pedidos->iter;
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
            return act->valor;
        else if (act->ref == NULL)
            break;

       lista_iter_avanzar(iter1);     
		}
    return NULL;
}
