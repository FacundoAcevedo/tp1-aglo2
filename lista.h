#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#include <stddef.h>

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

/* La lista esta planteada como lista de punteros genericos. */
//~ 
//~ typedef struct nodo nodo_t;

typedef struct lista lista_t;

typedef struct lista_iter lista_iter_t;


/* ******************************************************************
 *                    PRIMITIVAS BASICAS DE LA LISTA
 * *****************************************************************/

// Crea una lista.
// Post: devuelve una nueva lista vacia.
lista_t* lista_crear();

// Destruye la lista. Si se recibe la funciÃ³n destruir_dato por parÃ¡metro,
	// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una funciÃ³n capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void destruir_dato(void *));


// Devuelve dato de tipo size_t expresando la cantidad de elementos que contiene
// la lista. Si la lista no contiene elementos, devuelve 0.
// Pre: la lista fue creada.
size_t lista_largo(const lista_t *lista);


// Devuelve verdadero o falso, segÃºn si la lista tiene o no elementos.
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista);

// Agrega un nuevo elemento a la lista en la primera posicion. Devuelve 
// falso en caso de error.
// Pre: la lista fue creada.
// Post: se agrego un nuevo elemento a la lista, valor se encuentra al principio
// de la lista.
bool lista_insertar_primero(lista_t *lista, void *dato);

// Agrega un nuevo elemento a la lista en la ultima posicion. Devuelve 
// falso en caso de error.
// Pre: la lista fue creada.
// Post: se agrego un nuevo elemento a la lista, valor se encuentra al final
// de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato);

// Obtiene el valor del primer elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del primero, si estÃ¡ vacÃ­a devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolviÃ³ el primer elemento de la lista, cuando no estÃ¡ vacÃ­a.
void *lista_ver_primero(const lista_t *lista);


// Saca el primer elemento de la lista. Si la lista tiene elementos, se quita el
// primero de la lista, y se devuelve su valor, si estÃ¡ vacÃ­a, devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolviÃ³ el valor del primer elemento anterior, la lista
// contiene un elemento menos, si la lista no estaba vacÃ­a.
void *lista_borrar_primero(lista_t *lista);

// Inserta un dato en la lista en la posicion que se pasa por parametro.
// Pre: la lista no es vacia.
// Post: se ha insertado el valor pasado por parametro en la posicion
// seÃ±alada por el iterador. Los elementos ubicados luego de esa posicion
// avanzan su posicion en uno.
bool lista_insertar(lista_t *lista, lista_iter_t *iter, void *dato);
	
// Eimina el dato en la lista ubicado en la posicion que se pasa por parametro.	
// Pre: la lista no es vacia.
// Post: se elimina de la lista el elemento seÃ±alado por el iterador.
void *lista_borrar(lista_t *lista, lista_iter_t *iter);




/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR
 * *****************************************************************/

// Pre: Recibe una lista como parametro y crea un iterador de ella.
// Post: devuelve un iterador de lista.
lista_iter_t *lista_iter_crear(const lista_t *lista);

// Avanza una posicion en la lista.
// Pre: el iterador fue creado.
// Post: se avanzo una posicion en la actual del iterador. Si la posicion
// actual era la ultima, se devuelve false.
bool lista_iter_avanzar(lista_iter_t *iter);

// Devuelve un puntero al valor de la posicion donde se encuentra el
// iterador. Si la lista esta vacia, devuelve NULL.
// Pre: el iterador fue creado.
void *lista_iter_ver_actual(const lista_iter_t *iter);

// Verifica si se encuentra al final de la lista.
// Pre: el iterador fue creado.
// Post: devuelve true si el iterador se encuentra al final de la lista
// o si esta vacia; false si no se encuentra al final de la lista.
bool lista_iter_al_final(const lista_iter_t *iter);

// Destruye el iterador.
// Pre: el iterador fue creado.
// Post: se elimina el iterador.
void lista_iter_destruir(lista_iter_t *iter);

#endif // LISTA_H
