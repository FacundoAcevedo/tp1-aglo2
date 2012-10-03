#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "pila.h"
#include "estructuras.h"

pila_t* salientes_crear(){
	pila_t* salientes;
	salientes = pila_crear();
	return salientes;
	}

void salientes_destruir(pila_t* salientes, (*pedido_destruir)){
	pila_destrurir(salientes, *pedido_destruir);
	return;
	}
