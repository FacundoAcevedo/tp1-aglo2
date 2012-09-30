#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "pila.h"
#include "pedidos_entrantes.c"
#include "zonas.c"


pila_t* moto = pila_crear();

// Recibe la zona a la cual se quiere enviar las pizzas
bool moto_cargar(zona_t* zona){
	int cont;
	cont = 0;
	pedido_t* desencolado;
	pedido_t* primero;
			
	while (true){
		primero = cola_ver_primero(zona);
		cont = cont + primero->cant_pizzas;
		if (cont == 5){
			desencolado = cola_desencolar(zona);
			pila_apilar(moto, desencolado);
			return moto;
			}
		if (cont < 5){
			desencolado = cola_desencolar(zona);
			cola_encolar(cola_auz, desencolado);
			}
		}

// Recibe la lista de espera de una zona y un int "pizzas_cargadas con la cantidad de pizzas
// que ya tiene cargada la moto. Itera sobre la lista buscando un pedido
// cuyo valor de cant_pizzas sea (5 - pizzas_cargadas) o menor. Si lo encuentra,
// lo borra de la lista y lo devuelve. Si no lo encuentra, devuelve NULL. 
pedido_t* buscar_adecuado (lista_con_iter_t* lista_espera, int pizzas_cargadas) {
	
	
	
	}
/* PSEUDO CÓDIGO:
 * 
	contador = 0
	
	Si zona->lista_espera == NULL o "no encontré pedido matcheable en zona->lista_espera":
		miro el primer pedido
		contador += pedido->cant_pizzas
			if contador == 5, termino
			if contador > 5:
				contador -= pedido->cant_pizzas
				desencolo ese pedido de zona->cola_ppal
				encolo ese pedido a zona->lista_espera
				sigo

	Sino:
	if contador ==5, termino
	if contador
		apilo pedido a la moto
		contador = contador + pedido->cant_pizzas
*/


		
