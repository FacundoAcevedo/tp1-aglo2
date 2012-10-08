#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "tdas.h"
#include "pedidos.h"
#include "zonasymoto.h"
#include "pantalla.h"

int main(int argc, char**argv)
{
    /*Declaro los pedidos*/
	lista_t* pedidos_entrantes = lista_crear();
	pila_t* pedidos_salientes = pila_crear();
	/* Creo la lista "zonas */
	lista_t* zonas = lista_crear();

	pedido_t* pedido1;
	pedido1 = pedido_crear(3, 150, 1, "Dul");
	pedidos_entrantes_agregar(pedidos_entrantes, pedido1);
	puts("Agregue un pedido (Cliente: Dul, zona 3, distancia 150, 1 pizza)");
	
	// Pruebas de buscar_id
	lista_iter_t* rta1= buscar_id(pedidos_entrantes, "Dul");
    if (rta1){
		puts("Busqueda exitosa del cliente.");
		lista_iter_destruir(rta1);
	}
	else puts("ERROR");

	lista_iter_t* rta2= buscar_id(pedidos_entrantes, "Facu");	
	if(rta2){ 
		lista_iter_destruir(rta2);
		puts("ERROR");
	}
	else puts("El cliente no se encuentra en el resgistro (Facu).");
	
	pedido_t* pedido2;
	pedido2 = pedido_crear(3, 300, 2, "Pepe");
	pedidos_entrantes_agregar(pedidos_entrantes, pedido2);
	puts("Agregue otro pedido (Cliente: Pepe, zona 3, distnacia 300, 2 pizzas)");
	pedido_t* pedido3;
	pedido3 = pedido_crear(3, 600, 3, "Lolita");
    pedidos_entrantes_agregar(pedidos_entrantes, pedido3);
    puts("Agregue otro pedido (Cliente: Lolita, zona3, distancia 600, 3 pizzas)\n");
	puts("Lista de pedidos entrantes:\n");
	pedidos_lista_print(pedidos_entrantes);
    zona_preparar_pedidos(zonas, pedidos_entrantes);
	puts("Prepare pedidos\n");
	puts("Lista de pedidos preparados:\n");
	pedidos_lista_print(zonas);

	puts("Cargo moto\n");
	lista_t* moto0 = moto_cargar(zonas, pedidos_salientes);
	puts("Pedidos entregados por la moto, en orden de entrega:");
	pedidos_lista_print(moto0);
	//~ lista_destruir(moto0, destruir_pedido);	
	
	puts("Lista de pedidos salientes:\n");
    printeo_salientes(pedidos_salientes, 2);

	puts("Lista de pedidos que quedan en preparados:\n");
	pedidos_lista_print(zonas);
	
	pedido_t* pedido4;
	pedido4 = pedido_crear(4, 650, 5, "Ranita");
	pedidos_entrantes_agregar(pedidos_entrantes, pedido4);
	puts("Agregue otro pedido (Cliente: Ranita, zona 4, distancai 650, 5 pizzas)");
	
	pedido_t* pedido5;
	pedido5 = pedido_crear(3, 90, 2, "Jose");
	pedidos_entrantes_agregar(pedidos_entrantes, pedido5);
	puts("Agregue otro pedido (Cliente: Jose, zona 3, distancia 90, 2 pizzas)");	
	
	puts("Lista de pedidos entrantes:\n");
	pedidos_lista_print(pedidos_entrantes);
    zona_preparar_pedidos(zonas, pedidos_entrantes);
	puts("Prepare pedidos\n");
	puts("Lista de pedidos preparados:\n");
	pedidos_lista_print(zonas);

	puts("Cargo moto\n");
	lista_t* moto1 = moto_cargar(zonas, pedidos_salientes);
	puts("Pedidos entregados por la moto, en orden de entrega:");
	pedidos_lista_print(moto1);
	//~ lista_destruir(moto1, destruir_pedido);
	
	puts("Lista de pedidos salientes (los 5 ultimos):\n");
    printeo_salientes(pedidos_salientes, 5);
    
	puts("Cargo moto\n");
	lista_t* moto2 = moto_cargar(zonas, pedidos_salientes);
	puts("Pedidos entregados por la moto, en orden de entrega:");
	pedidos_lista_print(moto2);
	//~ lista_destruir(moto2, destruir_pedido);
	
	puts("Lista de pedidos salientes (los 10 ultimos):\n");
    printeo_salientes(pedidos_salientes, 10);
    
    pedido_t* pedido6;
	pedido6 = pedido_crear(3, 400, 2, "Josefina");
	pedidos_entrantes_agregar(pedidos_entrantes, pedido6);
	puts("Agregue otro pedido (Cliente: Josefina, zona 3, 2 pizzas)");	
	puts ("Estado actual de lista de pedidos entrantes:");
	pedidos_lista_print(pedidos_entrantes);

	// Pruebas de cancelar
    puts("\n Pruebas de cancelar");
    if (!buscar_id(pedidos_entrantes, "Romina")) puts ("No se encuentra el pedido (Romina).");
    lista_iter_t* rta3 =buscar_id(pedidos_entrantes, "Josefina");
	if (rta3){
		pedidos_entrantes_cancelar(pedidos_entrantes, "Josefina");
		lista_iter_destruir(rta3);
		}

	puts("Se ha eliminado el pedido de Josefina:");
	if(!pedidos_lista_print(pedidos_entrantes)) puts ("La lista de pedidos entrantes se encuentra vacia.");
	
	// Pruebas de que moto carga en orden
    puts("\n Pruebas de que moto carga en orden");
	pedido_t* pedido7;
	pedido7 = pedido_crear(1, 200, 2, "Jo");
	pedidos_entrantes_agregar(pedidos_entrantes, pedido7);
	pedido_t* pedido8;
	pedido8 = pedido_crear(1, 100, 2, "Manu");
	pedidos_entrantes_agregar(pedidos_entrantes, pedido8);	
	pedido_t* pedido9;
	pedido9 = pedido_crear(1, 300, 1, "Ernesto");
	pedidos_entrantes_agregar(pedidos_entrantes, pedido9);

	
	zona_preparar_pedidos(zonas, pedidos_entrantes);
	pedidos_lista_print(zonas);
	lista_t* moto3 = moto_cargar(zonas, pedidos_salientes);
	puts("Pedidos entregados por la moto, en orden de entrega:");
	pedidos_lista_print(moto3);
	//~ lista_destruir(moto3, destruir_pedido);



	// Destruyo lo que cree al principio
	pedidos_entrantes_destruir(pedidos_entrantes);
	pila_destruir(pedidos_salientes,  destruir_pedido);
	zonas_destruir(zonas, destruir_pedido);

	return 0;
}

