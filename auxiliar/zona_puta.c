
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "zona_puta.h"
#include "listaycola.h"
#include "lista_con_iter.h"

// COMENTADO POR SU SEGURIDAD!!!
/*typedef struct zona{*/
	/*cola_t* cola_ppal;*/
    /*lista_con_iter_t* lista_espera;*/
	/*int num;*/
/*}zona_t;*/


zona_t* zona_crear(){
	zona_t* zone;
	zone = malloc(sizeof(zona_t));
	if (zone == NULL) return NULL;
	cola_t* cola_ppal;
	cola_ppal = cola_crear();
    lista_con_iter_t* lista_espera;
    lista_espera = lista_con_iter_crear();
	zone->cola_ppal = cola_ppal;
	zone->lista_espera = lista_espera;
	zone->num = 2;
	return zone;
}


int main (){
zona_t* zona1;
zona1 = zona_crear();
return 0;
}
