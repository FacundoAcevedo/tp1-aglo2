#include <stdbool.h>
#include <ctype.h> 
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tdas.h"
#include "pedidos.h"
#include "zonasymoto.h"
#include "pantalla.h"


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


int main(){

	
    /*Declaro los pedidos*/
	lista_t* pedidos_entrantes = lista_crear();
	pila_t* pedidos_salientes = pila_crear();
	/* Creo la lista "zonas */
	lista_t* zonas = lista_crear();
	lista_t* moto;
	
    /*Declaro las variables estaticas*/
    int cant_pizzas;
    int eleccion;
    int zona;
    int distancia;
    int n;
    int opc;
    /*char* opc;*/
    char id[MAX];

         while (true)
            {
            lp(); //limpio la pantalla
            barra0('%');
         	printf("Elija una opcion : \n \
         			  1) Ingresar pedido \n \
         			  2) Modificar pedido \n \
         			  3) Cancelar pedido \n \
         			  4) Preparar pedidos \n \
         			  5) Mostrar pedidos preparados \n \
         			  6) Cargar y despachar* moto \n \
         			  7) Ver historial de motos enviadas \n \
         			  8) Ver lista de pedidos entrantes \n \
                       0) Salir\n");
            barra0('#');
            fflush(NULL);
         	scanf("%d", &opc);
            /*if ( cantidad_digitos(opc) != 1){*/
                /*puts("CULOOOOOOOOOOOOOOOOOO!!!!");*/
                /*getch();*/
                /*}*/

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
                     printf(" Nombre del cliente (sin espacios): ");
         			scanf("%s", id);
					if (strlen(id)>50){
						puts("El nombre no debe superar los 50 caracteres.");
						getch();
						break;
						}

         			lista_iter_t* rta= buscar_id(pedidos_entrantes, id);
                     if (rta){
         				puts("Ya se encuentra registrado un pedido con ese nombre.");
         				lista_iter_destruir(rta);
                         getch();
                         break;
						} 
                     printf(" Cantidad de pizzas: ");
         			scanf("%d", &cant_pizzas);
                    
                     printf(" Zona: ");
         			scanf("%d", &zona);
                    
                     printf(" Distancia a la pizzeria (metros): ");
         			scanf("%d", &distancia);
                    
         			if ((zona < 1) || (zona>5) || (cant_pizzas<1) || (cant_pizzas>5)){
         				puts("Cantidad de pizzas o zona inválidas");
                         getch();
         				break;
         				}
         		   pedido_t* pedido;
         		   pedido = pedido_crear(zona, distancia, cant_pizzas, id);
         		   if(pedidos_entrantes_agregar(pedidos_entrantes, pedido)){
						puts("El pedido se ha ingresado con exito. Detalles del pedido:");
						printf("Cliente: %s - Cantidad de pizzas: %d - Zona: %d - Distancia a la pizzeria: %d metros. \n",
							pedido->id, pedido->cant_pizzas, pedido->zona, pedido->distancia);
					}
					else puts ("El pedido no se ha podido ingresar. Intente nuevamente.");
                   break;
         
         		// 2) MODIFICAR PEDIDO
         
         	   case 2 :
         	      printf("Ingrese el nombre del cliente del pedido a modificar: \n");
         		   scanf("%s", id);
         			if (!buscar_id(pedidos_entrantes, id)){
         				puts("Ese pedido no se encuentra registrado");
                         getch();
                         break;
         				} 
         			printf("Los detalles del pedido de %s son:\n", id);
         			printf("Cantidad de pizzas: %d - Zona: %d - Distancia a la pizzeria: %d \n", pedido->cant_pizzas, pedido->zona, pedido->distancia);
         			puts("Elija lo que desea hacer:\n");  
         		   printf("		1) Modificar cantidad de pizzas \n		2) Modificar zona \n");
         		   scanf("%d", &eleccion);
         		   if (eleccion == 1){
         			   int nueva_cant;
         				printf("Ingrese la nueva cantidad de pizzas: \n" );
         				scanf("%d", &nueva_cant);
         				if ((nueva_cant<1) || (nueva_cant>5)){
         					puts("Cantidad de pizzas invalida");
                            getch();
         					break;
         					}
         				if (pedidos_entrantes_cant_pizzas(pedidos_entrantes, id, nueva_cant)){
         				puts("Cantidad de pizzas modificada con exito. ");
         				printf("Los detalles del pedido de %s ahora son:\n", id);
         				printf("Cantidad de pizzas: %d - Zona: %d - Distancia a la pizzeria: %d metros \n ", pedido->cant_pizzas, pedido->zona, pedido->distancia);
						}

         			}
         			else if (eleccion == 2){
         			   int nueva_zona;
         			   int nueva_distancia;
         				printf("Ingrese la nueva zona \n" );
         				scanf("%d", &nueva_zona);
         				if ((nueva_zona<1) || (nueva_zona>5)){
         					puts("Zona invalidas");
                            getch();
         					break;
						printf("Ingrese la nueva distancia a la pizzeria (metros) \n" );
         				scanf("%d", &nueva_distancia);
         				}
         				if (pedidos_entrantes_zona(pedidos_entrantes, id, nueva_zona, nueva_distancia)){
         				puts ("Zona modificada con exito");
         				printf("Los detalles del pedido de %s ahora son:\n", id);
         				printf("Cantidad de pizzas: %d - Zona: %d - Distancia a la pizzeria: %d metros \n ", pedido->cant_pizzas, pedido->zona, pedido->distancia);
						}

         			}
         			else{
         				puts("Eleccion invalida");
                        getch();
         				break;
         				}
                    
                    break;
         		   
         
         		// 3) CANCELAR PEDIDO
         
         	   case 3:
         		   printf("Ingrese el nombre del cliente del pedido a cancelar \n" );
         		    scanf("%s", id);
         			if (!buscar_id(pedidos_entrantes, id)){
         				puts("Ese pedido no se encuentra registrado");
                        getch();
                        break;
         			}
         			pedidos_entrantes_cancelar(pedidos_entrantes, id);
         			puts ("Pedido cancelado con exito.");	
                     break;
         		   
         	   
         	   // 4) PREPARAR PEDIDOS
         	   
         	   case 4:
         			if (zona_preparar_pedidos(zonas, pedidos_entrantes)){
         				puts("Los pedidos se han preparado con exito");
         		        getch();
         				break;
         				}
                     else{
         				puts("No hay pedidos para preparar");
         				getch();
         				break;
         				}
         	    
         	    // 5) IMPRIMIR PEDIDOS PREPARADOS
         	   case  5:
         			if (pedidos_lista_print(zonas)){
         		        getch();
         				break;
         				}
                     else{
         				puts("No hay pedidos preparados.");
         				getch();
         				break;
         				}
         	   

         	   
         	   // 6) CARGAR Y DESPAchar* MOTO
         	   
         	   case 6: 
					moto = moto_cargar(zonas, pedidos_salientes);
         			if (moto != NULL){
         				puts("La moto se ha cargado y despachado con exito.");
						pedidos_lista_print(moto);
         		        getch();
         				break;
         				}
                     else{
         				puts("No hay pedidos para cargar en la moto.");
         				getch();
         				break;
         				}
         	   
         		
         		// 7) HISTORIAL MOTOS DESPACHADAS
         
         	   case  7:
         	        printf("Ingrese cantidad de pedidos que desea ver del historial: \n" );
                     scanf("%i", &n);
         		
                     printeo_salientes(pedidos_salientes, n);
                     getch();
                     break;
         		   
         	   // 8) PRINTEO PEDIDOS ENTRANTES
         	   
         	   case 8:
                    if (!pedidos_lista_print(pedidos_entrantes)) 
                    puts ("La lista de pedidos entrantes no existe o esta vacia");
                    getch();
                    break;



                default:
                     lp();
                     puts(" Senor pizzero, la opcion es invalida");
                     /*getch();*/
                     fflush(NULL);
                     break;
         
                     
         	} //case
            //~ puts("SALI DEL CASE");
            getch();
         } // while
    /*}//while*/
// Destruyo lo que cree al principio
pedidos_entrantes_destruir(pedidos_entrantes);
pila_destruir(pedidos_salientes,  destruir_pedido);
zonas_destruir(zonas, destruir_pedido);
return 0;
}
