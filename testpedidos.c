#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "tdas.h"
#include "pedidos.h"
#include "preparadosymoto.h"
#include "pantalla.h"

int main(int argc, char**argv)
{
	// Creo un pedido
	pedido_t* pedido0;
	pedido0 = pedido_crear(3, 150, 1, "Dul");
	// Lo destruyo
	pedido_destruir(pedido0); 

	// Creo una lista de pedidos
	lista_t* pedidos_entrantes0 = lista_crear();
	// La destruyo
	lista_destruir(pedidos_entrantes0, NULL);




	// Creo otro pedido
	pedido_t* pedido1;
	pedido1 = pedido_crear(3, 150, 1, "Dul");
		
	// Creo una lista de pedidos
	lista_t* pedidos_entrantes1 = lista_crear();
	// Le agrego un pedido
	pedidos_entrantes_agregar(pedidos_entrantes1, pedido1);
	// Destruyo la lista
	lista_destruir(pedidos_entrantes1, destruir_pedido);
	
	/* El pedido pedido1 ha sido destruido al destruir lista_destruir. Por
	 * eso, no puedo volver a usarlo.
	 * Probemos destruir una lista con NULL. El pedido que contenga no
	 * debera destruirse y podra ser reutilizado.*/

	// Creo otro pedido
	pedido_t* pedido2;
	pedido2 = pedido_crear(3, 150, 1, "Dul");
	// Creo una lista de pedidos
	lista_t* pedidos_entrantes2 = lista_crear();
	// Le agrego UN NUEVO pedido
	pedidos_entrantes_agregar(pedidos_entrantes2, pedido2);
	// Destruyo la lista
	lista_destruir(pedidos_entrantes2, NULL);

	lista_t* pedidos_entrantes3 = lista_crear();
	pedidos_entrantes_agregar(pedido2);
	lista_destruir(pedidos_entrantes3, destruir_pedido);






	// Creo una lista de pedidos con un pedido nuevo
	pedido_t* pedido3 = pedido_crear(3, 150, 1, "Dul");
	lista_t* pedidos_entrantes4 = lista_crear();
	// Le agrego un pedido
	pedidos_entrantes_agregar(pedidos_entrantes4, pedido3);

	// buscar_id
	lista_iter_t* iter = buscar_id(pedidos_entrantes4, "Dul");
	lista_iter_destruir(iter);
	// Destruyo la lista
	lista_destruir(pedidos_entrantes3, destruir_pedido);
	
	
	
	
	
	
	// Creo una lista de pedidos
	//~ lista_t* pedidos_entrantes3 = lista_crear();
	// Le agrego un pedido
	//~ pedidos_entrantes_agregar(pedidos_entrantes3, pedido1);
	// Cancelo un pedido
	//~ pedidos_entrantes_cancelar(pedidos_entrantes3, "Dul");
	//~ 


	
	return 0;
}
