#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

//Estructura de la pila
struct _pila 
{
    //apunto datos a NULL, para que no apunte a cualquier lado
    void** datos ;
    size_t tamanio;
    size_t cantidad;
};

// Crea una pila.
// Post: devuelve una nueva pila vacÃ­a.
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

// Devuelve verdadero o falso, segÃºn si la pila tiene o no elementos apilados.
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
// Post: se agregÃ³ un nuevo elemento a la pila, valor es el nuevo tope.
bool pila_apilar(pila_t *pila, void* valor )
{
    //es una pre-condicion, pero igual, verifico que la pila haya sido creada
    if (pila == NULL) return false;
    
    //le reasigno memoria a pila.dato si llegue paso un multiplo de 10 en cantidad 
    if ((pila->tamanio - pila->cantidad) == 0){
	    pila->datos = realloc(pila->datos, 10* sizeof(void*));
	    //~ puts("hice un realloc");
	    pila->tamanio += 10;
	    printf("tamanio: %zu\n", pila->tamanio);
		}    
    //verifico que todo haya funcionado
    if (pila->datos == NULL) return false;
	//~ printf("cantidad %zu\n", pila->cantidad);
	//~ printf("direccion de datos %p\n", pila->datos);
	//~ printf("direccion de datos + pila->cantidad (antes de agregar valor) %p\n", pila->datos + pila->cantidad);
    pila->cantidad += 1;
	*(pila->datos + pila->cantidad) = valor;
    //~ printf("direccion de datos + pila->cantidad (despues de agregar valor) %p\n", pila->datos + pila->cantidad);
	return true;
}

// Obtiene el valor del tope de la pila. Si la pila tiene elementos,
// se devuelve el valor del tope. Si estÃ¡ vacÃ­a devuelve NULL.
// Pre: la pila fue creada.
// Post: se devolviÃ³ el valor del tope de la pila, cuando la pila no estÃ¡
// vacÃ­a, NULL en caso contrario.
void* pila_ver_tope(const pila_t *pila){
    //~ printf("tam - cant: %zu ###### ", (pila->tamanio -pila->cantidad));
    void* tope;
    /*tope = (pila->datos + (pila->cantidad));    */
    tope = *(pila->datos + (pila->cantidad));    
    //~ printf("tope: %p \n", tope);  
    if (pila->cantidad == 0) return NULL;
    return tope;
	}
   
    
// Saca el elemento tope de la pila. Si la pila tiene elementos, se quita el
// tope de la pila, y se devuelve ese valor. Si la pila estÃ¡ vacÃ­a, devuelve 
// NULL.
// Pre: la pila fue creada.
// Post: si la pila no estaba vacÃ­a, se devuelve el valor del tope anterior 
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
		printf("tamanio SAQUE REALLOC: %zu // cantiad: %zu \n", pila->tamanio, pila->cantidad);
		}
    pila->cantidad -=1;
    // Devuelvo la referencia al valor desapilado
    printf("cantidad = %zu", pila->cantidad);
    return desapilado;
}
