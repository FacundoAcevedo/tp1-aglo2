#ifndef PEDIDOS_H
#define PEDIDOS_H
#define MAX 50
#include "tdas.h"


typedef struct pedido{
    int zona;
    int distancia;
    int cant_pizzas;
    char id[MAX];
}pedido_t;

/*##############################################################*/
/*						PEDIDO*/
/*##############################################################*/
// Crea un elemento del tipo pedido_t*.
// Recibe: tres entero (indicando zona, distancia y cantidad de pizzas) y
// un char* con el nombre del cliente.
// Pre: el nombre de el cliente no debe contener espacios ni superar los
// 49 caracteres.
// Post: se devuelve un pedido con los atributos pasados por parametro.
pedido_t* pedido_crear( int zona, int distancia, int cant_pizzas, char* id);


// Cambia el atributo zona y el atributo distancia de un pedido.
// Recibe dos enteros con la nueva informaciÃ³n.
// Devuelve false si el pedido no existe, true si se ha hecho el cambio.
bool pedido_cambiar_zona (pedido_t* pedido, int nueva_zona, int nueva_distancia);


// Cambia el atributo cant_pizzas de un pedido.
// Recibe un entero con la nueva informaciÃÂ³n.
// Devuelve false si el pedido no existe, true si se ha hecho el cambio.	
bool pedido_cambiar_cant (pedido_t* pedido, int nueva_cant);


// Destruye un elemento del tipo pedido_t*
void pedido_destruir(pedido_t* pedido);


// Wrap de pedido_destruir
void (destruir_pedido)(void* dato);


/*##############################################################*/
/*							SALIENTES*/
/*##############################################################*/


// Imprime los ultimos n pedidos entregados
// Recibe: dato de tipo pila_t* y entero.
// Post devuelve 1 si la pila esta vacia, 0 si se realiza todo con exito.
int printeo_salientes(pila_t* salientes, int n);
	

/*##############################################################*/
/*						ENTRANTES*/
/*##############################################################*/
// Busca sobre una lista, y devuelve un iterador donde hay un pedido.
// PRE: recibe una lista_t* de pedidos_t*, y un char* con el
// id a buscar
// POST: mueve el iter hasta el nodo donde esta ese id, si no lo encuentra, 
// devuelve NULL o el iter de caso contrario
lista_iter_t*  buscar_id(lista_t* pedidos_entrantes, char* id);


// Crea un elemento del tipo lista_t* y lo devuelve vacio.
lista_t* pedidos_entrantes_crear();
	
	
// Agrega elemento del tipo pedido_t* al final de la lista.
// Recibe: lista_t* con elementos del tipo pedido_t* y un pedido_t*.
// Devuelve true o false si la insercion no pudo realizarse.
bool pedidos_entrantes_agregar (lista_t* pedidos_entrantes, pedido_t* pedido);


// Saca el primer pedido de la lista.
// Recibe: lista_t* con elementos del tipo pedido_t*.
// Devuelve el dato del tipo pedido_t* que fue sacado de la lista.
pedido_t* pedidos_entrantes_sacar (lista_t* pedidos_entrantes);


// Modifica los atributos zona y distancia de un elemento del tipo pedido_t*
// Recibe: lista enlazada con elementos del tipo pedido_t*, un char* con
// el nombre del cliente cuyo pedido se quiere modificar, un entero con
// la nueva zona y un entero con la nueva distancia.
// Post: el dato de tipo pedido_t* coincideente ha sido con los nuevos
// valores en los atributos zona y distancia o devuelve false si 
// no hay ningun pedido en la lista o si el pedido no se encuentra.
bool pedidos_entrantes_zona (lista_t* pedidos_entrantes, char* id, int nueva_zona, int nueva_distancia);


// Modifica el atributo cant_pizzas de un elemento del tipo pedido_t*
// Recibe: lista enlazada con elementos del tipo pedido_t*, un char* con
// el nombre del cliente cuyo pedido se quiere modificar y un entero con
// la nueva cantidad.
// Post: el dato de tipo pedido_t* coincideente ha sido con el nuevo
// valor del atributo cant_pizzao devuelve false si no hay ningun pedido
// en la lista o si el pedido no se encuentra.
bool pedidos_entrantes_cant_pizzas (lista_t* pedidos_entrantes, char* id, int nueva_cant);
	

// Saca el pedido de la lista de pedidos_entrantes y lo destruye.
// Recibe: lista enlazada con elementos del tipo pedido_t* y un char* con
// el nombre del cliente cuyo pedido se quiere eliminar.
// Post: el dato de tipo pedido_t* coincideente ha sido destruido.
// o devuelve false si no hay ningun pedido en la lista o si el pedido no se encuentra.
bool pedidos_entrantes_cancelar (lista_t* pedidos_entrantes, char* id);


// Destruyo la lista pedidos_entrantes
// Recibe: lista enlazada con elementos del tipo pedido_t*
// Pre: la lista fue creada.
// Post: la lista y sus datos han sido destruidos.
void pedidos_entrantes_destruir (lista_t* pedidos_entrantes);


// Printea el historial de los pedidos entrantes. Recibe una lista enlazada
// con elementos del tipo pedido_t*. Devuelve true o false si la lista
// no existe o esta vacia.
bool pedidos_lista_print (lista_t* lista_pedidos);


#endif
