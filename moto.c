#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "pila.h"
#include "pedidos_entrantes.c"

pila_t* moto = pila_crear();
cola_t* cola_aux = cola_crear();

// Recibe la zona a la cual se quiere enviar las pizzas
bool moto_cargar(cola_t* zona){
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
/* PSEUDO CÓDIGO:
 * 
	contador = 0
	miro el primer pedido
	contador += pedido->cant_pizzas
		if contador == 5:
			desencolo ese pedido de zonaX
			apilo ese pedido a la moto
			termino

	miro el segundo pedido
	contador += pedido->cant_pizzas
		if contador == 5, termino
		if contador > 5:
			contador -= pedido->cant_pizzas
			desencolo ese pedido de zonaX
			apilo ese pedido a cola_aux
			sigo
	miro el tercer pedido...
*/


		
