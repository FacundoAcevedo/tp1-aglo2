#include <stdbool.h>
#include <ctype.h> 
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tdas.h"
#include "pedidos.h"
#include "preparadosymoto.h"
#include "pantalla.h"
#include "interaccion.h"

int cantidad_digitos(int num)
{
    int x = 0;
    while(num!=0)
    {
        num = num/10;
        x+=1;
    }
    return x;
}

// Imprime el menu principal
void print_menu(){
	lp(); //limpio la pantalla
	barra0('%');
	printf("Elija una opcion : \n \
	1) Ingresar pedido \n \
	2) Modificar pedido \n \
	3) Cancelar pedido \n \
	4) Preparar pedidos \n \
	5) Mostrar pedidos preparados \n \
	6) Cargar y despachar moto \n \
	7) Ver historial de motos enviadas \n \
	8) Ver lista de pedidos entrantes \n \
	0) Salir\n");
	barra0('#');
	fflush(NULL);
	return;
}
// Destruye datos creados al arrancar el programa
void destruir (lista_t* pedidos_entrantes, pila_t* pedidos_salientes, lista_t* preparados){
	pedidos_entrantes_destruir(pedidos_entrantes);
	pila_destruir(pedidos_salientes,  destruir_pedido);
	lista_destruir(preparados, destruir_pedido);
	return;
}

// Imprime los detalles de un pedido
void print_detalles (pedido_t* pedido, char* id){
	printf("El pedido se ha ingresado/modificado con exito. Los detalles del pedido de %s son:\n", id);
	printf("Cliente: %s - Cantidad de pizzas: %d - Zona: %d - Distancia a la pizzeria: %d metros. \n",
	pedido->id, pedido->cant_pizzas, pedido->zona, pedido->distancia);
}

// Ingresa los datos cantidad de pizzas, zona y distnacia, crea un pedido
// nuevo con ellos y lo retorna.
pedido_t* tomar_datos (char* id){
	puts(" Cantidad de pizzas: ");
	int cant_pizzas = leer_numero();
	puts(" Zona: ");
	int zona = leer_numero();
	puts(" Distancia a la pizzeria (metros): ");
	int distancia = leer_numero();
         			
	if ((zona < 1) || (zona>5) || (cant_pizzas<1) || (cant_pizzas>5)){
		puts("Cantidad de pizzas o zona invalidas");
		return NULL;
	}
	pedido_t* pedido = pedido_crear(zona, distancia, cant_pizzas, id);
	return pedido;
}

// OPCION UNO
// Pide el nombre de un cliente, si ya se encuentra registrado, lo rechaza
// sino, registra el pedido y lo agrega a pedidos_entrantes.
pedido_t* opcion_uno(lista_t* pedidos_entrantes, char* id, int cant_pizzas, int zona, int distancia){
	lp(); //limpio la pantalla
	barra1('-');
	puts("#Ingresar pedido:\n");
	puts(" Nombre del cliente: ");
	id = leer_texto();
	lista_iter_t* id_bus = buscar_id(pedidos_entrantes,id);
	if (id_bus!= NULL){
		puts("Ya se encuentra registrado un pedido con ese nombre.");
		lista_iter_destruir(id_bus);
        free(id);
		return NULL;
	} 
	pedido_t* pedido = tomar_datos(id);
	lista_iter_destruir(id_bus);
	if(pedido && pedidos_entrantes_agregar(pedidos_entrantes, pedido)) print_detalles(pedido, id);
	else puts ("El pedido no se ha podido ingresar. Intente nuevamente.");
    free(id);    
    return pedido;
}

// Modifica cantidad de pizzas de un pedido 
void modificar_cantidad (lista_t* pedidos_entrantes, char* id, pedido_t* pedido){
	int nueva_cant;
	printf("Ingrese la nueva cantidad de pizzas: " );
	nueva_cant = leer_numero();
	if ((nueva_cant<1) || (nueva_cant>5)){
		puts("Cantidad de pizzas invalida");
		return;
	}

	if (pedidos_entrantes_cant_pizzas(pedidos_entrantes, id, nueva_cant))
		print_detalles(pedido, id);
	return;
}

// Modifica zona y distancia de un pedido
void modificar_zona (lista_t* pedidos_entrantes, char* id, pedido_t* pedido){
	int nueva_zona;
	int nueva_distancia;
	puts("Ingrese la nueva zona " );
	nueva_zona = leer_numero();
	puts("Ingrese la nueva distancia a la pizzeria (metros) " );
	nueva_distancia = leer_numero();

	if ((nueva_zona<1) || (nueva_zona>5)){
		puts("Zona invalida");
		return;
	}

	if (pedidos_entrantes_zona(pedidos_entrantes, id, nueva_zona, nueva_distancia))
		print_detalles(pedido, id);
	return;
}
// OPCION 2
void opcion_dos (char* id, lista_t* pedidos_entrantes, pedido_t* pedido){
	printf("Ingrese el nombre del cliente del pedido a modificar: ");
	id = leer_texto();
	if (!buscar_id(pedidos_entrantes, id)){
		puts("Ese pedido no se encuentra registrado");
        free(id);
		return;
	} 

	puts("Elija lo que desea hacer:\n");  
	printf("		1) Modificar cantidad de pizzas \n		2) Modificar zona \n");
	
	int eleccion = leer_numero();
	
	if (eleccion == 1)
		modificar_cantidad(pedidos_entrantes, id, pedido);
	else if (eleccion == 2)
		modificar_zona(pedidos_entrantes, id, pedido);
	else{
		puts("Eleccion invalida");
        free(id);
		return;
	}
    free(id);

	return;
}

// OPCION CUATRO
// Prepara pedidos
void opcion_cuatro(lista_t* preparados, lista_t* pedidos_entrantes){
	if (pedidos_preparar(preparados, pedidos_entrantes)){
		puts("Los pedidos se han preparado con exito");
		return;
	}
	else{
		puts("No hay pedidos para preparar");
        return;
    }
}



/* MAIN */

int main(){

	
    /*Declaro los pedidos*/
	lista_t* pedidos_entrantes = lista_crear();
	pila_t* pedidos_salientes = pila_crear();
	/* Creo la lista "preparados */
	lista_t* preparados = lista_crear();
	lista_t* moto;
	pedido_t* pedido;
	
    /*Declaro las variables estaticas*/
    int cant_pizzas=0;
    int zona=0;
    int distancia=0;
    int n=0;
    int opc=0;
    /*char* opc;*/
    char* id;
         while (true)
            {
			print_menu();
			opc = leer_numero();
             /*Switch del menu*/
         	switch (opc){	

                 case 0:
                 /*0) SALIR*/
				destruir(pedidos_entrantes, pedidos_salientes, preparados);
				exit(0);

         		// 1) INGRESAR PEDIDO

         	   case 1:
					pedido = opcion_uno(pedidos_entrantes, id, cant_pizzas, zona, distancia);
					break;

         		// 2) MODIFICAR PEDIDO
         
         	   case 2 :
					opcion_dos (id, pedidos_entrantes, pedido);
                    break;
         		   
         
         		// 3) CANCELAR PEDIDO
         
         	   case 3:
         		   printf("Ingrese el nombre del cliente del pedido a cancelar \n" );
         		    id = leer_texto();
         		    bool rta = pedidos_entrantes_cancelar(pedidos_entrantes, id);
         		    if (rta == false)
         		    	printf("No se encuentra registrado el pedido de %s.\n", id);
         		    else
						puts("Pedido cancelado con exito.");
                    free(id);
					break;
         		   
         	   
         	   // 4) PREPARAR PEDIDOS
         	   
         	   case 4:
					opcion_cuatro(preparados, pedidos_entrantes);
					break;
					
         	    // 5) IMPRIMIR PEDIDOS PREPARADOS
         	   case  5:
         			pedidos_lista_print(preparados);
        		   break;
         			
         	   
         	   // 6) CARGAR Y DESPACHAR MOTO
         	   
         	   case 6: 
					moto = moto_cargar(preparados, pedidos_salientes);
         			if (moto){
         				puts("La moto se ha cargado y despachado con exito.");
						pedidos_lista_print(moto);
						// Una vez impresa, la moto ya no me sirve: se destruye
						lista_destruir(moto, NULL);
					}
					else 
						puts("No hay pedidos para cargar.");
					break;
         		
         		// 7) HISTORIAL MOTOS DESPACHADAS
         
         	   case  7:
         	        printf("Ingrese cantidad de pedidos que desea ver del historial: \n" );
                    n = leer_numero();
                    printeo_salientes(pedidos_salientes, n);
                    break;
         		   
         	   // 8) PRINTEO PEDIDOS ENTRANTES
         	   
         	   case 8:
                    pedidos_lista_print(pedidos_entrantes);
                    break;



               default:
                     lp();
                     puts(" Senor pizzero, la opcion es invalida");
                     fflush(NULL);
                     break;
         
                     
         	} //case
            //~ puts("SALI DEL CASE");
            getch();
         } // while
    /*}//while*/
	// Destruyo lo que cree al principio
	destruir(pedidos_entrantes, pedidos_salientes, preparados);
	return 0;
}
