#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "tdas.h"


typedef struct nodo{
    void* valor;
    struct nodo* ref;
}nodo_t;


struct lista{
	nodo_t* inicio;
    nodo_t* fin;
	size_t largo;
};


struct lista_iter{
	nodo_t* anterior;
	nodo_t* actual;
};

struct lista_con_iter{
	lista_t* lista;
	lista_iter_t* iter;
};


//FUNCION AUXILIAR: creacion de un nodo
//Recibe un valor. Devuelve el nodo.
 nodo_t* nodo_crear(void* valor){
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if (nodo == NULL) return NULL;
    nodo->valor = valor;
    nodo->ref = NULL;
    return nodo;
}

/* ******************************************************************
 *                    FUNCIONES BASICAS DE LA LISTA
 * *****************************************************************/



// Crea una lista.
// Post: devuelve una nueva lista vacia.
lista_t* lista_crear(){
	lista_t* lista;
	lista = malloc(sizeof(lista_t));
	if (lista == NULL) return NULL;
	lista->inicio = NULL;
	lista->fin = NULL;
	lista->largo = 0;	
	return lista;

}
 
 
// Destruye la lista. Si se recibe la funciÃÂ³n destruir_dato por parÃÂ¡metro,
// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una funciÃÂ³n capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void destruir_dato(void *)){
	if (lista==NULL) return;
	void* borrado;
	while (!lista_esta_vacia(lista)){
		borrado = lista_borrar_primero(lista);
		if (destruir_dato!= NULL){
			destruir_dato(borrado);	
			}
		}
    free(lista);
 }


// Devuelve dato de tipo size_t expresando la cantidad de elementos que contiene
// la lista. Si la lista no contiene elementos, devuelve 0.
// Pre: la lista fue creada.
size_t lista_largo(const lista_t *lista){
	return lista->largo;
	}


// Devuelve verdadero o falso, segÃÂºn si la lista tiene o no elementos.
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista){
	if (lista->largo == 0) return true;
	return false;
}

// Agrega un nuevo elemento a la lista en la primera posicion. Devuelve 
// falso en caso de error.
// Pre: la lista fue creada.
// Post: se agrego un nuevo elemento a la lista, valor se encuentra al principio
// de la lista.

bool lista_insertar_primero(lista_t *lista, void *dato){
	
	nodo_t* nuevo_nodo = nodo_crear(dato);
    if (nuevo_nodo == NULL) return false;
    if (lista_esta_vacia(lista)){
        lista->inicio = nuevo_nodo;
		lista->fin = nuevo_nodo;
		}
    else{
	    nuevo_nodo->ref = lista->inicio;
        lista->inicio = nuevo_nodo;
		}
	lista->largo += 1;
	return true; 
}
	

// Agrega un nuevo elemento a la lista en la ultima posicion. Devuelve 
// falso en caso de error.
// Pre: la lista fue creada.
// Post: se agrego un nuevo elemento a la lista, valor se encuentra al final
// de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato){
	nodo_t* nuevo_nodo = nodo_crear(dato);
    if (nuevo_nodo == NULL) return false;
    else if (lista->largo == 0){
        lista->inicio = nuevo_nodo;
        lista->fin = nuevo_nodo;
		}
    else{
        (lista->fin)->ref = nuevo_nodo;
        lista->fin= nuevo_nodo;
		}
	lista->largo += 1;
	return true; 
 }


// Obtiene el valor del primer elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del primero, si estÃÂ¡ vacÃÂ­a devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolviÃÂ³ el primer elemento de la lista, cuando no estÃÂ¡ vacÃÂ­a.
void *lista_ver_primero(const lista_t *lista){
	if (lista_esta_vacia(lista)) return NULL;
	return (lista->inicio)->valor;
	}

// Saca el primer elemento de la lista. Si la lista tiene elementos, se quita el
// primero de la lista, y se devuelve su valor, si estÃÂ¡ vacÃÂ­a, devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolviÃÂ³ el valor del primer elemento anterior, la lista
// contiene un elemento menos, si la lista no estaba vacÃÂ­a.
void *lista_borrar_primero(lista_t *lista){
    if (lista_esta_vacia(lista)) return NULL;

    nodo_t *nodo_a_borrar = lista->inicio;
    void *valor = nodo_a_borrar->valor;
    lista->inicio= (nodo_a_borrar)->ref;
    
    free(nodo_a_borrar);
    lista->largo -=1;
    if (lista->largo == 0) lista->fin = NULL;
    return valor;
    }

// Inserta un dato en la lista en la posicion que se pasa por parametro.
// Pre: la lista no es vacia.
// Post: se ha insertado el valor pasado por parametro en la posicion
// señalada por el iterador. Los elementos ubicados luego de esa posicion
// avanzan su posicion en uno.
bool lista_insertar(lista_t *lista, lista_iter_t *iter, void *dato){
	if (iter->anterior == NULL && iter->actual != NULL){ // o sea si iter = posicion inicial
        //Estoy en el primer nodo
        lista_insertar_primero(lista, dato);
        //Actualizo el iterador
        iter->actual = lista->inicio;
        iter->anterior = NULL;
        lista->largo +=1;
        return true;
        }
        //if
    nodo_t* nodo_nuevo = nodo_crear(dato); 
    if (nodo_nuevo == NULL) return false;
    (iter->anterior)->ref = nodo_nuevo;
    nodo_nuevo->ref = iter->actual;
    lista->largo +=1;
    //Actualizo el iterador
    iter->actual = nodo_nuevo;
    return true;
    }
        
	
// Elimina el dato en la lista ubicado en la posicion que se pasa por parametro.	
// Pre: la lista no es vacia.
// Post: se elimina de la lista el elemento señalado por el iterador.
void *lista_borrar(lista_t *lista, lista_iter_t *iter){
    nodo_t *nodo_a_borrar = iter->actual;
	void* borrado = (iter->actual)->valor;
	iter->actual = (iter->actual)->ref;
    free(nodo_a_borrar);
	lista->largo -=1;
	return borrado;
	}


/* ******************************************************************
 *                    FUNCIONES DEL ITERADOR
 * *****************************************************************/

// Pre: Recibe una lista como parametro y crea un iterador de ella.
// Post: devuelve un iterador de lista posicionado en el primer elemento.
// Si la lista esta vacia devuelve NULL.
lista_iter_t *lista_iter_crear(const lista_t *lista)
{
    if (lista_esta_vacia(lista)) return NULL;
    lista_iter_t* iter = malloc(sizeof(lista_iter_t));
    iter->anterior = NULL;
    iter->actual = lista->inicio;
    return iter;
}

// Avanza una posicion en la lista.
// Pre: el iterador fue creado.
// Post: se avanzo una posicion en la actual del iterador. Si la posicion
// actual era la ultima, se devuelve false.
bool lista_iter_avanzar(lista_iter_t *iter){
	if (lista_iter_al_final(iter)) return false;
	if (iter->actual == NULL) return false;
	iter->anterior = iter->actual;
	iter->actual = (iter->actual)->ref;
	return true;
}

// Devuelve un puntero al valor de la posicion donde se encuentra el
// iterador. Si la lista esta vacia, devuelve NULL.
// Pre: el iterador fue creado.
void *lista_iter_ver_actual(const lista_iter_t *iter){
	void* valor = (iter->actual)->valor;
	return valor;
}

// Verifica si se encuentra al final de la lista.
// Pre: el iterador fue creado.
// Post: devuelve true si el iterador se encuentra al final de la lista
// false si no se encuentra al final de la lista.
bool lista_iter_al_final(const lista_iter_t *iter){
	if ((iter->actual)->ref== NULL) return true;
	return false;
}
//~ 
// Destruye el iterador.
// Pre: el iterador fue creado.
// Post: se elimina el iterador.
void lista_iter_destruir(lista_iter_t *iter){
    free(iter);

} 


/* ******************************************************************
 *                    FUNCIONES LISTA CON ITER
 * *****************************************************************/


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
	
	// Se destruye la lista con lista_destruir, pasÃ¡ndole la funcion destruir()
	lista_destruir(lista_con_iter->lista, (*destruir));
	// Se libera la estructura lista_con_iter
    free(lista_con_iter);
    return;
 }




/* ******************************************************************
 *                    FUNCIONES BASICAS DE LA COLA
 * *****************************************************************/


struct cola
{
    nodo_t* prim;
    nodo_t* ultimo;
    long int tamanio;
};


cola_t* cola_crear()
{
    cola_t* cola = malloc(sizeof(cola_t));
    if (cola == NULL) return NULL;
    nodo_t* nodo1 = NULL;
    nodo_t* nodo2 = NULL;
    cola->prim = nodo1;
    cola->ultimo= nodo2;
    cola->tamanio =0;
    return cola;
}


// Destruye la cola. Si se recibe la funciÃÂ³n destruir_dato por parÃÂ¡metro,
// para cada uno de los elementos de la cola llama a destruir_dato.
// Pre: la cola fue creada. destruir_dato es una funciÃÂ³n capaz de destruir
// los datos de la cola, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la cola.

 void cola_destruir(cola_t *cola, void destruir_dato(void *)){
	if (cola==NULL) return;
	if (cola->prim == NULL){
		 free(cola);
		 return;
		}
	void* borrado;
	int i;
	for (i=0; i<cola->tamanio; i++){
		borrado = cola_desencolar(cola);
		if (destruir_dato!= NULL){
			destruir_dato(borrado);	
			}
		}
    free(cola);
 }

// Devuelve verdadero o falso, segÃÂºn si la cola tiene o no elementos encolados.
// Pre: la cola fue creada.
bool cola_esta_vacia(const cola_t *cola)
{
    if (!cola) return false;
    else if(cola->tamanio == 0) return true;
    return false;
}



// Agrega un nuevo elemento a la cola. Devuelve falso en caso de error.
// Pre: la cola fue creada.
// Post: se agregÃÂ³ un nuevo elemento a la cola, valor se encuentra al final
// de la cola.
bool cola_encolar(cola_t *cola, void* valor)
{
	if (!cola) return false;
    //Construyo el nuevo nodo que quiero encolar. nuevo_nodo->valor = valor
    // y nuevo_nodo->referencia = NULL porque esta al final de la cola
    nodo_t* nuevo_nodo = nodo_crear(valor);
    
    //Si la cola estÃ¡ vacÃ­a, nuevo_nodo es el primer y el Ãºltimo nodo de la cola
    if (cola->tamanio == 0){
		cola->prim = nuevo_nodo;
		cola->ultimo = nuevo_nodo;
	}
    else {
		cola->ultimo->ref = nuevo_nodo;
		cola->ultimo = nuevo_nodo; 
		}
	cola->tamanio += 1;
	return true;
}


// Obtiene el valor del primer elemento de la cola. Si la cola tiene
// elementos, se devuelve el valor del primero, si estÃÂ¡ vacÃÂ­a devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolviÃÂ³ el primer elemento de la cola, cuando no estÃÂ¡ vacÃÂ­a.
void* cola_ver_primero(const cola_t *cola)
{
    if (cola_esta_vacia(cola)==true) return NULL;
    void* primero = (cola->prim)->valor;
    return primero;
}

// Saca el primer elemento de la cola. Si la cola tiene elementos, se quita el
// primero de la cola, y se devuelve su valor, si estÃÂ¡ vacÃÂ­a, devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolviÃÂ³ el valor del primer elemento anterior, la cola
// contiene un elemento menos, si la cola no estaba vacÃÂ­a.
void* cola_desencolar(cola_t *cola)
{
    if (cola_esta_vacia(cola) == true) return NULL;
    nodo_t* nodo_aux = NULL;
    
    //Guardo el valor a desencolar
    void* desencolado = (cola->prim)->valor;
    // Cambio la referencia de prim. Ahora vale la referencia al segundo nodo.
    nodo_aux = cola->prim;

    cola->prim = (cola->prim)->ref;
    // Destruyo el nodo desencolado? Â¿Â¿??
    free(nodo_aux);

    // Disminuyo el tamanio
    cola->tamanio -= 1;
    // Devuelvo el valor del desencolado
    return desencolado;
}    



/* *****************************************************************
 *                    FUNCIONES DE LA PILA
 * *****************************************************************/

//Estructura de la pila
struct _pila 
{
    //apunto datos a NULL, para que no apunte a cualquier lado
    void** datos ;
    size_t tamanio;
    size_t cantidad;
};

// Crea una pila.
// Post: devuelve una nueva pila vacÃÂ­a.
pila_t* pila_crear()
{
    pila_t* pila = malloc(sizeof(pila_t));
    if (pila == NULL) return NULL;
    pila->tamanio = 0;
    pila->cantidad = 0;
    pila->datos = malloc(sizeof(void*));
    if (!pila->datos){
		free(pila);
		return NULL;
		}
    return pila;
}

// Destruye la pila.
// Pre: la pila fue creada.
// Post: se eliminaron todos los elementos de la pila.
void pila_destruir(pila_t *pila , void destruir_dato(void *))
{
    if (pila->cantidad != 0 ||  pila->datos != NULL)
        if (destruir_dato)
                destruir_dato(pila->datos);
        free(pila->datos);
    if (pila != NULL) free(pila);
}

// Devuelve verdadero o falso, segÃÂºn si la pila tiene o no elementos apilados.
// Pre: la pila fue creada.
bool pila_esta_vacia(const pila_t *pila)
{
	//Verifico que fue creada.
	if (pila == NULL) return false;
    if (pila->cantidad == 0) return true;
    
    return false;
}

// Agrega un nuevo elemento a la pila. Devuelve falso en caso de error.
// Pre: la pila fue creada.
// Post: se agregÃÂ³ un nuevo elemento a la pila, valor es el nuevo tope.
bool pila_apilar(pila_t *pila, void* valor )
{
    //es una pre-condicion, pero igual, verifico que la pila haya sido creada
    if (pila == NULL) return false;
    
    //le reasigno memoria a pila.dato si llegue paso un multiplo de 10 en cantidad 
    if ((pila->tamanio - pila->cantidad) == 0){
	    pila->datos = realloc(pila->datos, 10* sizeof(void*));
	    pila->tamanio += 10;
		}    
    //verifico que todo haya funcionado
    if (pila->datos == NULL) return false;
    pila->cantidad += 1;
	*(pila->datos + pila->cantidad) = valor;
	return true;
}

// Obtiene el valor del tope de la pila. Si la pila tiene elementos,
// se devuelve el valor del tope. Si estÃÂ¡ vacÃÂ­a devuelve NULL.
// Pre: la pila fue creada.
// Post: se devolviÃÂ³ el valor del tope de la pila, cuando la pila no estÃÂ¡
// vacÃÂ­a, NULL en caso contrario.
void* pila_ver_tope(const pila_t *pila){
    void* tope;
    tope = *(pila->datos + (pila->cantidad));    
    if (pila->cantidad == 0) return NULL;
    return tope;
	}
   
    
// Saca el elemento tope de la pila. Si la pila tiene elementos, se quita el
// tope de la pila, y se devuelve ese valor. Si la pila estÃÂ¡ vacÃÂ­a, devuelve 
// NULL.
// Pre: la pila fue creada.
// Post: si la pila no estaba vacÃÂ­a, se devuelve el valor del tope anterior 
// y la pila contiene un elemento menos.
void* pila_desapilar(pila_t *pila)
{
    if (pila_ver_tope(pila) == NULL) return NULL;
    // Guardo un puntero al valor que voy a desapilar
    void* desapilado;
    desapilado = pila_ver_tope(pila);
	if ((pila->tamanio - pila->cantidad) == 10){
		pila->tamanio -= 10;
		void** nuevo_datos;
		nuevo_datos= realloc(pila->datos, pila->tamanio*sizeof(void*));
		if (nuevo_datos == NULL) return NULL;
		pila->datos = nuevo_datos;
		}
    pila->cantidad -=1;
    // Devuelvo la referencia al valor desapilado
    return desapilado;
}