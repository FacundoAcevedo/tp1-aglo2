#include "pila.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

pila_t* salientes_crear(){
	pila_t* salientes;
	salientes = pila_crear();
	return salientes;
	}

void salientes_destruir(pila_t* salientes, void pedido_destruir (void*)){
	pila_destrurir(salientes, pedido_destruir);
	return;
	}
