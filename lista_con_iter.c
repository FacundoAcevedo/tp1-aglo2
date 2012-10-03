#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "listaycola.h"
#include "lista_con_iter.h"

struct lista_con_iter{
	lista_t* lista;
	lista_iter_t* iter;
};


lista_con_iter_t* lista_con_iter_crear(){
	lista_con_iter_t* lista_con_iter;
	lista_con_iter = malloc (sizeof(lista_con_iter_t));
	if (!lista_con_iter) return NULL;
	lista_t* lista;
	lista = lista_crear();
	lista_con_iter->lista = lista;
	lista_iter_t* iter;
	iter = lista_iter_crear(lista);
	lista_con_iter->iter = iter;
	return lista_con_iter;
	}

void lista_con_iter_destruir(lista_con_iter_t* lista_con_iter, void destruir(void *)){
	// Si lista_con_iter no existe, termina la funcion
	if (!lista_con_iter) return;

	// Se destruye el iterador de lista_con_iter
	lista_iter_destruir(lista_con_iter->iter);
	
	// Se destruye la lista con lista_destruir, pasándole la funcion destruir()
	lista_destruir(lista_con_iter->lista, (*destruir));
	// Se libera la estructura lista_con_iter
    free(lista_con_iter);
    return;
 }
 
//~ <<<<<<< HEAD
//~ =======
 
 
 /*// SACAR*/
/*int main(){*/
	/*return 0;*/
/*}*/
//~ >>>>>>> fd4f0e2a01bb3b27d04f7ba19caf0a6b3d810f9e
