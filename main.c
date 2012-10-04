#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "tdas.h"
#include "pedidos.h"
#include "zonasymoto.h"
#include "pantalla.h"


int main(){

    /*Declaro las zonas*/
	zona_t* zona1 = zona_crear();
	zona_t* zona2 = zona_crear();
	zona_t* zona3 = zona_crear();
	zona_t* zona4 = zona_crear();
	zona_t* zona5 = zona_crear();
	
    /*Declaro los pedidos*/
	lista_t* pedidos_entrantes = lista_crear();
	pila_t* pedidos_salientes = pila_crear();
	
    /*Declaro las variables estaticas*/
    int cant_pizzas;
    int eleccion;
    int zona;
    int n;
    bool rta;
    int opc;
    unsigned int id;

    /*Bucle del menu*/
    while (true)
        {
        lp(); //limpio la pantalla
        barra0('#');
    	printf("Elija una opcion : \n \
    			  1) Ingresar pedido \n \
    			  2) Modificar pedido \n \
    			  3) Cancelar pedido \n \
    			  4) Preparar pedidos \n \
    			  5) Cargar y despachar moto \n \
    			  6) Ver historial de motos enviadas \n \
    			  7) Ver lista de pedidos entrantes \n \
                  0) Salir\n");
    	scanf("%i", &opc);

        /*Switch del menu*/
    	switch (opc){	

            case 0:
            /*0) SALIR*/
                exit(0);

    		// 1) INGRESAR PEDIDO

    	   case 1:
                lp(); //limpio la pantalla
                barra1('-');
                puts("#Ingresar pedido:\n");
                printf(" Cantidad de pizzas: ");
    			scanf("%d", &cant_pizzas);
                printf(" Zona: ");
    			scanf("%d", &zona);
    			if ((zona < 1) || (zona>5) || (cant_pizzas<1) || (cant_pizzas>5)){
    				puts("Cantidad de pizzas o zona inválidas");
                    getch();
    				break;
    				}
    		   pedido_t* pedido;
    		   pedido = pedido_crear(zona, cant_pizzas);
    		   pedidos_entrantes_agregar(pedidos_entrantes, pedido);
               break;
    
    		// 2) MODIFICAR PEDIDO
    
    	   case 2 :
    	      printf("Ingrese el número identificador del pedido a modificar: \n");
    		   scanf("%u", &id);
				if (!buscar_id(pedidos_entrantes, id)){
					puts("Ese pedido no se encuentra registrado");
                    getch();
    				break;
					}
    		   printf("		1) Modificar cantidad de pizzas \n		2) Modificar zona \n");
    		   scanf("%d", &eleccion);
    		   if (eleccion == 1){
    			   int nueva_cant;
    				printf("Ingrese la nueva cantidad de pizzas: \n" );
    				scanf("%d", &nueva_cant);
    				if ((nueva_cant<1) || (nueva_cant>5)){
    					puts("Cantidad de pizzas o zona invalidas");
                        getch();
    					break;
						}

    				pedidos_entrantes_cant_pizzas(pedidos_entrantes, id, nueva_cant);
    			   }
    			else if (eleccion == 2){
    			   int nueva_zona;
    				printf("Ingrese la nueva zona \n" );
    				scanf("%d", &nueva_zona);
    				if ((nueva_zona<1) || (nueva_zona>5)){
    					puts("Cantidad de pizzas o zona invalidas");
                        getch();
    					break;
    					}
    				
    				pedidos_entrantes_zona(pedidos_entrantes, id, nueva_zona);
    
    				}
    			else{
    				puts("Eleccion invalida");
                    getch();
    				break;
    				}
               break;
    		   
    
    		// 3) CANCELAR PEDIDO
    
    	   case 3:
    		   printf("Ingrese numero identificador del pedido a cancelar \n" );
    		    scanf("%u", &id);
    			pedidos_entrantes_cancelar(pedidos_entrantes, id);	
                break;
    		   
    	   
    	   // 4) PREPARAR PEDIDOS
    	   
    	   case 4:
				rta = zona_preparar_pedidos(zona1, zona2, zona3, zona4, zona5, pedidos_entrantes);
				if (!rta) puts("Ha ocurrido un error");
                getch();
    			break;    		   
    	   
    	   // 5) CARGAR Y DESPACHAR MOTO
    	   
    	   case 5: 
    	   
    			break;
    
    		
    		// 6) HISTORIAL MOTOS DESPACHADAS
    
    	   case  6:
    	        printf("Ingrese cantidad de pedidos que desea ver del historial: \n" );
                scanf("%i", &n);
    		
                printeo_salientes(pedidos_salientes, n);
                break;
    		   
    	   // 7) PRINTEO PEDIDOS ENTRANTES
    	   
    	   case 7:
               pedidos_entrantes_print(pedidos_entrantes);
               getch();
               break;
           default:
                //  no cipayeees que las opciones van es espa;ol
                //  MALDITO TECALDO YANQUI!!! NO TIENE ENIE XD
    			/*printf("Invalid Choice");*/
                puts(" Senor pizzero, la opcion es invalida");
                getch();
                break;
    
                
    	} //case
    } // while

return 0;
}
