#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "cola.h"
#include "pila.h"


//Este archivo define las estructuras a utilizar


struct lista_con_iter{
	lista_t* lista;
	lista_iter_t* iter;
}lista_con_iter_t;
	
struct zona{
	cola_t* cola_ppal;
	lista_con_iter_t* lista_espera;
}zona_t;

struct pedido{
	int zona;
	int cant_pizzas;
	unsigned int id;
}pedido_t;

