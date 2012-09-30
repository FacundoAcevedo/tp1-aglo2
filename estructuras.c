#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

//Este archivo define las estructuras a utilizar


struct lista_con_iter {
	lista_t* lista;
	lista_iter_t* iter;
} lista_con_iter_t;
	
struct pedido{
	int zona;
	int cant_pizzas;
	unsigned int id;
	} pedido_t;
