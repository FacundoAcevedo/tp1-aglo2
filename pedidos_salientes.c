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
	
int printeo_salientes(pila_t* salientes){
	int i;
	i = 0;
	pila_t* copia;
	copia = salientes;
	while (!pila_esta_vacia(copia)){
		pedido_t* desapilado;
		desapilado = pila_desapilar(copia);
		printf("Pedido nro: %u \n Cantidad de pizzas: %d \n Zona: %d \n\n",desapilado->id, desapilado->cant_pizzas, desapilado->zona);
		}
	pila_destruir(copia);
	
	
	}
	

void salientes_destruir(pila_t* salientes, (*pedido_destruir)){
	pila_destrurir(salientes, *pedido_destruir);
	return;
	}
