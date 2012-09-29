#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "estructuras.h"

/*
 *Busca sobre una lista, y devuelve un nodo.
 *PRE: recibe una pedidos_entrates_t con la lista de pedidos, y un unsigned int con el
 *id a buscar
 *POST: mueve el iter hasta el nodo donde esta ese id, si no lo encuentra, 
 *devuelve false o true de caso contrario
 */
lista_iter_t* buscar_id(pedidos_entrantes_t* pedidos, unisigned int id)
{
    //variables
    lista_t* lista = pedidos->lista;
    lista_iter_t* iter = pedidos->iter;
    nodo_t* nodo;
    unsigned int id_cmp;


    //reinicio la posicion del iter
    iter->actual = lista->inicio;
    iter->siguiente = (iter->actual)->siguiente;

    //Busco
    while(true)
    {
        nodo = iter->actual;
        id_cmp = (nodo->datos)->id;
        
        if (id_cmp == id)
            return true;
        else if (nodo->siguiente == NULL)
            break

       iter_avanzar(iter);     
    }
    return false;
    
        

    
}
