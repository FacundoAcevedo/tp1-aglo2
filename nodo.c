#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "nodo.h"

struct nodo
{
    void* valor;
    struct nodo_t * ref;
};

//FUNCION AUXILIAR: creacion de un nodo
//Recibe un valor. Devuelve el nodo.
 nodo_t* nodo_crear(void* valor){
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if (nodo == NULL) return NULL;
    nodo->valor = valor;
    /*nodo_t* ref = NULL;*/
    /*nodo->ref = ref;*/
    nodo->ref = NULL;
    return nodo;
}


