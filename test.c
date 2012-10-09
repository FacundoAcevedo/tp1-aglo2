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
	puts ("\nPruebas de crear y destruir pedido");
	// Creo un pedido
	pedido_t* pedido0;
	pedido0 = pedido_crear(3, 150, 1, "Dul");
	printf("Pedido creado: Nombre: %s - Cantidad de pizzas: %d - Zona: %d - Distancia: %d\n", 
		pedido0->id, pedido0->cant_pizzas, pedido0->zona, pedido0->distancia);
	// Lo destruyo
	pedido_destruir(pedido0); 

	// Creo una lista de pedidos
	lista_t* pedidos_entrantes0 = lista_crear();
	// La destruyo
	lista_destruir(pedidos_entrantes0, NULL);



	puts("\nPrueba de agregar pedido nuevo a pedidos entrantes");
	// Creo otro pedido
	pedido_t* pedido1;
	pedido1 = pedido_crear(3, 150, 1, "Dul");
		
	// Creo una lista de pedidos
	lista_t* pedidos_entrantes1 = lista_crear();
	puts("Lista de pedidos entrantes antes de agregar algo:");
	pedidos_lista_print(pedidos_entrantes1);
	// Le agrego un pedido
	pedidos_entrantes_agregar(pedidos_entrantes1, pedido1);
	puts("Lista de pedidos entrantes luego de agregar algo:");
	pedidos_lista_print(pedidos_entrantes1);
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
	pedidos_entrantes_agregar(pedidos_entrantes3, pedido2);
	lista_destruir(pedidos_entrantes3, destruir_pedido);


/* ####################################################################*/


	// Creo una lista de pedidos con un pedido nuevo
	pedido_t* pedido3 = pedido_crear(3, 150, 1, "Dul");
	lista_t* pedidos_entrantes4 = lista_crear();
	// Le agrego un pedido
	pedidos_entrantes_agregar(pedidos_entrantes4, pedido3);

	puts("\nPruebas de buscar_id");
	// buscar_id
	puts("Busco un nombre que se encuentra en la lista: ");
	lista_iter_t* iter0 = buscar_id(pedidos_entrantes4, "Dul");
	if (iter0 != NULL) puts ("OK"); // genera un alloc mas
	else puts("ERROR");
	lista_iter_destruir(iter0);
	puts("Busco un nombre que no se encuentra en la lista ");
	lista_iter_t* iter1 = buscar_id (pedidos_entrantes4, "Pepe");
	if (iter1 == NULL) puts ("OK"); // genera un alloc mas
	else puts("ERROR"); 
	lista_iter_destruir(iter1);
	
	puts("\nPruebas de calcelar pedido");
	// Cancelo un pedido
	if (pedidos_entrantes_cancelar(pedidos_entrantes4, "Dul")) puts("OK");
	puts("\nPrueba de calcelar pedido con un nombre incorrecto:");
	pedidos_entrantes_cancelar(pedidos_entrantes4, "Azul");
	/* Cancelar funciona bien, porque adentro de la funcion destruye el 
	 * pedido con pedido_destruir.*/
	
	//Creo un nuevo pedido
	pedido_t* pedido4 = pedido_crear (3, 150, 1, "Dul");
	// Lo agrego a pedidos_entrantes3
	pedidos_entrantes_agregar(pedidos_entrantes4, pedido4);
	
	
	// Pedidos_entrantes_sacar: no debe eliminar el pedido, solo sacarlo
	// de la lista y retornarlo.
	puts("\nPrueba de pedidos_entrantes_sacar");
	puts("Lista antes de sacar:");
	pedidos_lista_print(pedidos_entrantes4);
	pedido_t* sacado = pedidos_entrantes_sacar(pedidos_entrantes4);
	pedido_destruir(sacado);
	puts("Lista despues de sacar:");
	pedidos_lista_print(pedidos_entrantes4);
	
	// Destruyo la lista
	lista_destruir(pedidos_entrantes4, destruir_pedido);
	
	
/* ####################################################################*/

	// Pruebas de moto manuales
	puts("\nPruebas de moto manuales (No se respeta el cuenta el maximo de pizzas)");
	// Creo una moto manualmente
	lista_t* moto0 = lista_crear();
	// Le agrego pedidos a la moto desde lista_insertar_primero
	pedido_t* pedido5 = pedido_crear(1, 500, 3, "Facu");
	pedido_t* pedido6 = pedido_crear(1, 100, 3, "Pepe");
	pedido_t* pedido7 = pedido_crear(1, 150, 3, "Luis");
	
	lista_insertar_primero(moto0, pedido5);
	lista_insertar_primero(moto0, pedido6);
	lista_insertar_primero(moto0, pedido7);

	puts("Orden en el que se insertaron pedidos a la moto: ");
	pedidos_lista_print(moto0);
	
	lista_t* ordenada = moto_ordenar(moto0);
	puts("Orden de los pedidos una vez ordenados: ");
	pedidos_lista_print(ordenada);

	lista_destruir(ordenada, destruir_pedido);
	
/* ####################################################################*/

	// Pruebas de preparar
	puts("\nPruebas de preparar pedidos");
	// Creo preparados
	lista_t* preparados0 = lista_crear();
	
	// Creo pedidos entrantes vacia
	lista_t* pedidos_entrantes5 = lista_crear();

	// Intento preparar con pedidos entrantes vacia
	puts("Intento de preparar con lista de pedidos entrantes vacia: ");
	if (!pedidos_preparar(preparados0, pedidos_entrantes5)) puts ("OK");
	else puts ("ERROR");
	
	pedido_t* pedido8 = pedido_crear(1, 200, 2, "Herny");
	pedidos_entrantes_agregar(pedidos_entrantes5, pedido8);
	
	puts("Preparado con lista de pedidos entrantes no vacia (1 elementos): ");
	if (pedidos_preparar(preparados0, pedidos_entrantes5)) puts ("OK");
	else puts("ERROR");

	puts("Impresion de la lista de preparados: ");

	pedidos_lista_print(preparados0);
	// Pruebas de cargar desde preparados
	puts("\nPruebas de cargar la moto y ver lista de salientes: ");
	// Creo pila salientes
	pila_t* salientes0 = pila_crear();
	
	// Pruebas de printeo_salientes y pedidos_lista_print
	// Print de lista vacia
	puts("Print de salientes, n = 5 (lista esta vacia):");
	printeo_salientes(salientes0, 5);	

	lista_t* moto1 = moto_cargar(preparados0, salientes0);
	if (moto1 != NULL) puts("OK");
	else puts("ERROR");
	// Destruyo la moto, ya no me sirve
	lista_destruir(moto1, NULL);

	
	// Creo 4 pedidos y los agrego
	pedido_t* pedido9 = pedido_crear(2, 202, 3, "Juan");
	pedido_t* pedido10 = pedido_crear(1, 333, 1, "Harry");
	pedido_t* pedido11 = pedido_crear(3, 2000, 5, "Hermione");
	pedido_t* pedido12 = pedido_crear(3, 200, 1, "Ron");
	pedidos_entrantes_agregar(pedidos_entrantes5, pedido9);
	pedidos_entrantes_agregar(pedidos_entrantes5, pedido10);
	pedidos_entrantes_agregar(pedidos_entrantes5, pedido11);
	pedidos_entrantes_agregar(pedidos_entrantes5, pedido12);

	puts("Preparado con lista de pedidos entrantes no vacia (4 elementos): ");
	if (pedidos_preparar(preparados0, pedidos_entrantes5)) puts ("OK");
	else puts("ERROR");

	puts("Impresion de la lista de preparados: ");
	pedidos_lista_print(preparados0);

	lista_t* moto2 = moto_cargar(preparados0, salientes0);
	if (moto2 != NULL) puts("OK");
	else puts("ERROR");
	// Destruyo la moto, ya no me sirve
	lista_destruir(moto2, NULL);

	
	// con un n menor a la cantidad de la pila
	puts("Print de salientes, n = 1:");
	printeo_salientes(salientes0, 1);
	// con un n mayor a la cantida de la pila
	puts("Print de salientes, n = 10:");
	printeo_salientes(salientes0, 10);
	
	// print de pedidos_entrantes5. Esta vacia
	puts("Pedidos entrantes esta vacia:");
	pedidos_lista_print(pedidos_entrantes5);
	
	// Creo y agrego pedidos
	pedido_t* pedido13 = pedido_crear(3, 34, 2, "Myrtle");
	pedido_t* pedido14 = pedido_crear(4, 2300, 5, "Albus");
	pedido_t* pedido15 = pedido_crear(5, 300, 1, "Minerva");
	pedidos_entrantes_agregar(pedidos_entrantes5, pedido13);
	pedidos_entrantes_agregar(pedidos_entrantes5, pedido14);
	pedidos_entrantes_agregar(pedidos_entrantes5, pedido15);
	
	// print de pedidos_entrantes5. No eta vacia
	puts("Pedidos entrantes :");
	pedidos_lista_print(pedidos_entrantes5);
	
	

	
	// Pruebas de modificar cantidad de pizzas
	puts("\nPruebas de modificar cantidad de pizzas");
	printf("Los detalles del pedido de %s eran:\n", "Minerva");
    printf("Cantidad de pizzas: %d - Zona: %d - Distancia a la pizzeria: %d metros \n ", 
		pedido15->cant_pizzas, pedido15->zona, pedido15->distancia);
	// Cambio la cantidad de 5 a 2
	if (pedidos_entrantes_cant_pizzas(pedidos_entrantes5, "Minerva", 2)){
    	puts("Cantidad de pizzas modificada con exito. ");
    	printf("Los detalles del pedido de %s ahora son:\n", "Minerva");
     	printf("Cantidad de pizzas: %d - Zona: %d - Distancia a la pizzeria: %d metros \n ", 
			pedido15->cant_pizzas, pedido15->zona, pedido15->distancia);
		}
	else puts ("ERROR");
	
	puts("\nPruebas de modificar zona y distancia");
	printf("Los detalles del pedido de %s eran:\n", "Albus");
    printf("Cantidad de pizzas: %d - Zona: %d - Distancia a la pizzeria: %d metros \n ", 
		pedido14->cant_pizzas, pedido14->zona, pedido14->distancia);
	// Cambio la zona de 4 a 2, distancia pasa a 1000
	if (pedidos_entrantes_zona(pedidos_entrantes5, "Albus", 2, 1000)){
    	puts("Zona y distancia modificadas con exito. ");
    	printf("Los detalles del pedido de %s ahora son:\n", "Albus");
     	printf("Cantidad de pizzas: %d - Zona: %d - Distancia a la pizzeria: %d metros \n ", 
			pedido14->cant_pizzas, pedido14->zona, pedido14->distancia);
		}
	else puts ("ERROR");
	
	// Prueba modificar pedido inexistente
	puts("\nPrueba de modificar pedido inexistente");
	if (!pedidos_entrantes_zona(pedidos_entrantes5, "Severus", 3, 10)) puts ("OK");



	lista_destruir(preparados0, destruir_pedido);
	lista_destruir(pedidos_entrantes5, destruir_pedido);
	pila_destruir(salientes0, destruir_pedido);
	
	return 0;
}
