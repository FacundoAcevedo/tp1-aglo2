vector_dinamico.c#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/
typedef struct vector vector_t;

/* ******************************************************************
 *                    PRIMITIVAS DEL VECTOR
 * *****************************************************************/

// Crea un vector de tamaÃ±o tam
// Post: vector es una vector vacÃ­o de tamaÃ±o tam
vector_t* vector_crear(size_t tam);

// Destruye el vector
// Pre: el vector fue creado
// Post: se eliminaron todos los elementos del vector
void vector_destruir(vector_t *vector);

// Cambia el tamaÃ±o del vector
// Pre: el vector fue creado
// Post: el vector cambiÃ³ de tamaÃ±o a nuevo_tam y devuelve true
// o el vector queda intacto y devuelve false si no se pudo cambiar el tamaÃ±o
// a nuevo_tam
bool vector_redimensionar(vector_t *vector, size_t nuevo_tam);

// Almacena en valor el dato guardado en la posiciÃ³n pos del vector
// Pre: el vector fue creado
// Post: se almacenÃ³ en valor el dato en la posiciÃ³n pos. Devuelve false si la
// posiciÃ³n es invÃ¡lida (fuera del rango del vector, que va de 0 a tamaÃ±o-1)
bool vector_obtener(vector_t *vector, size_t pos, void** valor);

// Almacena el valor en la posiciÃ³n pos
// Pre: el vector fue creado
// Post: se almacenÃ³ el valor en la posiciÃ³n pos. Devuelve false si la posiciÃ³n
// es invÃ¡lida (fuera del rango del vector, que va de 0 a tamaÃ±o-1) y true si
// se guardÃ³ el valor con Ã©xito.
bool vector_guardar(vector_t *vector, size_t pos, void* valor);

// Devuelve el tamaÃ±o del vector
// Pre: el vector fue creado
size_t vector_obtener_tamanio(vector_t *vector);
