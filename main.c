#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "listaycola.h"
#include "pila.h"
#include "pedidos_entrantes.h"
#include "pedidos_salientes.h"
#include "zonas.h"
#include "moto.h"
#include "lista_con_iter.h"


int main(){
	zona_t* zona1 = zona_crear();
	zona_t* zona2 = zona_crear();
	zona_t* zona3 = zona_crear();
	zona_t* zona4 = zona_crear();
	zona_t* zona5 = zona_crear();
	
	lista_con_iter_t* pedidos_entrantes = lista_con_iter_crear();
	pila_t* pedidos_salientes = pila_crear();
	
	
	int choice;
	do {
	   printf("Please make a choice: \n"
			  "1) Ingresar pedido \n"
			  "2) Modificar pedido \n"
			  "3) Cancelar pedido \n"
			  "4) Preparar pedidos \n"
			  "5) Cargar moto \n"
			  "6) Ver historial de motos enviadas \n");
	   scanf("%d", &choice);


		// INGRESAR PEDIDO
		
	   if (choice == 1) {
		   int cant_pizzas;
		   int zona;
			scanf(" Cantidad de pizzas: %d \n", &cant_pizzas);
			scanf(" Zona: %d \n", &zona);
			if ((zona < 1) || (zona>5) || (cant_pizzas<1) || (cant_pizzas>5)){
				puts("Cantidad de pizzas o zona inválidas");
				break;
				}
		   pedido_t* pedido;
		   pedido = pedido_crear(zona, cant_pizzas);
		   pedidos_entrantes_agregar(pedidos_entrantes, pedido);
		   }

		// MODIFICAR PEDIDO

	   else if (choice == 2) {
			int eleccion;
		   printf("1) Modificar cantidad de pizzas \n" "2) Modificar zona \n");
		   scanf("d", &eleccion);
		   if (eleccion == 1){
			   int nueva_cant;
				printf("Ingrese la nueva cantidad de pizzas \n" );
				scanf("d", &nueva_cant);
				if ((nueva_cant<1) || (nueva_cant>5)){
					puts("Cantidad de pizzas o zona invÃ¡lidas");
					break;
					}
				pedidos_entrantes_cant_pizzas(pedidos_entrantes, pedido->id, nueva_cant);
			   }
			else if (eleccion == 2){
			   int nueva_zona;
				printf("Ingrese la nueva zona \n" );
				scanf("d", &nueva_zona);
				if ((nueva_zona<1) || (nueva_zona>5)){
					puts("Cantidad de pizzas o zona invÃÂ¡lidas");
					break;
					}
				pedidos_entrantes_zona(pedidos_entrantes, pedido->id, nueva_zona);

				}
			else{
				puts("Eleccion invalida");
				break;
				}
		   }

		// CANCELAR PEDIDO

	   else if (choice == 3) {
		   unsigned int id;
		   printf("Ingrese numero identificador del pedido a cancelar \n" );
				scanf("u", &id);
			pedidos_entrantes_cancelar(pedidos_entrantes, id);	
		   }
	   
	   // PREPARAR PEDIDOS
	   
	   else if (choice == 4) {
		   
		   }
	   
	   
	   else if (choice == 5) {}
	   else if (choice == 6) {
		   printeo_salientes(pedidos_salientes);
		   }
	   else {
			printf("Invalid Choice");
			}
	} while (choice != 5);

}
