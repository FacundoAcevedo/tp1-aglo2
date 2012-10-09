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
	//~ // Creo un pedido
	//~ pedido_t* pedido0;
	//~ pedido0 = pedido_crear(3, 150, 1, "Dul");
	//~ // Lo destruyo
	//~ pedido_destruir(pedido0); 
//~ 
	//~ // Creo una lista de pedidos
	//~ lista_t* pedidos_entrantes0 = lista_crear();
	//~ // La destruyo
	//~ lista_destruir(pedidos_entrantes0, NULL);
//~ 
//~ 
//~ 
//~ 
	//~ // Creo otro pedido
	//~ pedido_t* pedido1;
	//~ pedido1 = pedido_crear(3, 150, 1, "Dul");
		//~ 
	//~ // Creo una lista de pedidos
	//~ lista_t* pedidos_entrantes1 = lista_crear();
	//~ // Le agrego un pedido
	//~ pedidos_entrantes_agregar(pedidos_entrantes1, pedido1);
	//~ // Destruyo la lista
	//~ lista_destruir(pedidos_entrantes1, destruir_pedido);
	//~ 
	//~ /* El pedido pedido1 ha sido destruido al destruir lista_destruir. Por
	 //~ * eso, no puedo volver a usarlo.
	 //~ * Probemos destruir una lista con NULL. El pedido que contenga no
	 //~ * debera destruirse y podra ser reutilizado.*/
//~ 
	//~ // Creo otro pedido
	//~ pedido_t* pedido2;
	//~ pedido2 = pedido_crear(3, 150, 1, "Dul");
	//~ // Creo una lista de pedidos
	//~ lista_t* pedidos_entrantes2 = lista_crear();
	//~ // Le agrego UN NUEVO pedido
	//~ pedidos_entrantes_agregar(pedidos_entrantes2, pedido2);
	//~ // Destruyo la lista
	//~ lista_destruir(pedidos_entrantes2, NULL);
//~ 
	//~ lista_t* pedidos_entrantes3 = lista_crear();
	//~ pedidos_entrantes_agregar(pedidos_entrantes3, pedido2);
	//~ lista_destruir(pedidos_entrantes3, destruir_pedido);


/* ####################################################################*/

//~ 
	//~ // Creo una lista de pedidos con un pedido nuevo
	//~ pedido_t* pedido3 = pedido_crear(3, 150, 1, "Dul");
	//~ lista_t* pedidos_entrantes4 = lista_crear();
	//~ // Le agrego un pedido
	//~ pedidos_entrantes_agregar(pedidos_entrantes4, pedido3);
//~ 
	//~ // buscar_id
	//~ lista_iter_t* iter = buscar_id(pedidos_entrantes4, "Dul");
	//~ lista_iter_destruir(iter);
	//~ 
	//~ // Cancelo un pedido
	//~ pedidos_entrantes_cancelar(pedidos_entrantes4, "Dul");
	//~ /* Cancelar funciona bien, porque adentro de la funcion destruye el 
	 //~ * pedido con pedido_destruir.*/
	//~ 
	//~ //Creo un nuevo pedido
	//~ pedido_t* pedido4 = pedido_crear (3, 150, 1, "Dul");
	//~ // Lo agrego a pedidos_entrantes3
	//~ pedidos_entrantes_agregar(pedidos_entrantes4, pedido4);
	//~ 
	//~ 
	//~ // Pedidos_entrantes_sacar: no debe eliminar el pedido, solo sacarlo
	//~ // de la lista y retornarlo.
	//~ pedido_t* sacado = pedidos_entrantes_sacar(pedidos_entrantes4);
	//~ pedido_destruir(sacado);
	//~ 
	//~ 
	//~ // Destruyo la lista
	//~ lista_destruir(pedidos_entrantes4, destruir_pedido);
	//~ 
	//~ 
/* ####################################################################*/


	// Creo una moto
	lista_t* moto0 = lista_crear();
	// Le agrego pedidos a la moto desde lista_insertar_primero
	pedido_t* pedido5 = pedido_crear(1, 500, 3, "Facu");
	pedido_t* pedido6 = pedido_crear(1, 100, 3, "Pepe");
	pedido_t* pedido7 = pedido_crear(1, 150, 3, "Luis");
	
	lista_insertar_primero(moto0, pedido5);
	lista_insertar_primero(moto0, pedido6);
	lista_insertar_primero(moto0, pedido7);

	lista_t* ordenada = moto_ordenar(moto0);

	// Printeo las distancias de los pedidos en el orden que quedaron
	// los pedidos
	int i =0;
	lista_iter_t* iter = lista_iter_crear(ordenada);
	while (i < 3){
		pedido_t* actual = lista_iter_ver_actual(iter);
		printf("Distancia: %d\n", actual->distancia);
		lista_iter_avanzar(iter);
		i += 1;
	}
	lista_iter_destruir(iter);
	lista_destruir(ordenada, destruir_pedido);
	
	return 0;
}
