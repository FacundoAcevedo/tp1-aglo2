#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "tdas.h"
#include "pedidos.h"
#include "zonasymoto.h"


int main(){
	zona_t* zona1 = zona_crear();
	zona_t* zona2 = zona_crear();
	zona_t* zona3 = zona_crear();
	zona_t* zona4 = zona_crear();
	zona_t* zona5 = zona_crear();
	
	lista_t* pedidos_entrantes = lista_crear();
	pila_t* pedidos_salientes = pila_crear();
	
   	int opc;
   int cant_pizzas;
    int eleccion;
   int zona;

   unsigned int id;


    while ( true)
        {
    	   printf("Elija una opcion (0 para salir): \n"
    			  "1) Ingresar pedido \n"
    			  "2) Modificar pedido \n"
    			  "3) Cancelar pedido \n"
    			  "4) Preparar pedidos \n"
    			  "5) Cargar y despachar moto \n"
    			  "6) Ver historial de motos enviadas \n"
    			  "7) Ver lista de pedidos entrantes \n");
    	   scanf("%d", &opc);
    
    		// 1) INGRESAR PEDIDO
    	switch (opc){	
    	   case 1 :

    			scanf(" Cantidad de pizzas: %d \n", &cant_pizzas);
    			scanf(" Zona: %d \n", &zona);
    			if ((zona < 1) || (zona>5) || (cant_pizzas<1) || (cant_pizzas>5)){
    				puts("Cantidad de pizzas o zona inválidas");
    				break;
    				}
    		   pedido_t* pedido;
    		   pedido = pedido_crear(zona, cant_pizzas);
    		   pedidos_entrantes_agregar(pedidos_entrantes, pedido);
               break;
    
    		// 2) MODIFICAR PEDIDO
    
    	   case 2 :
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
               break;
    		   
    
    		// 3) CANCELAR PEDIDO
    
    	   case 3:
    		   printf("Ingrese numero identificador del pedido a cancelar \n" );
    		    scanf("u", &id);
    			pedidos_entrantes_cancelar(pedidos_entrantes, id);	
               break;
    		   
    	   
    	   // 4) PREPARAR PEDIDOS
    	   
    	   case 4:
    		   
    	   
    	   // 5) CARGAR Y DESPACHAR MOTO
    	   
    	   case 5: {}
    
    		
    		// 6) HISTORIAL MOTOS DESPACHADAS
    
    	   case  6:
               /*printeo_salientes(pedidos_salientes);*/
               break;
    		   
    	   // 7) PRINTEO PEDIDOS ENTRANTES
    	   
    	   case 7:
               /*pedidos_entrantes_print(pedidos_entrantes);*/
               break;
           default:
               //  no cipayeees que las opciones van es espa;ol
               //  MALDITO TECALDO YANQUI!!! NO TIENE ENIE XD
    			/*printf("Invalid Choice");*/
                puts(" Senor pizzero, la opcion es invalida");
                break;
                
    	} //case
    } // while
return 0;
}
