#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

//Este archivo define las estructuras a utilizar


struct pedidos_entrantes {
	lista_t* lista_pedidos;
	lista_iter_t* iter;
} pedidos_entrantes_t;
	
struct pedido{
	int zona;
	int cant_pizzas;
	unsigned int id;
	} pedido_t;
