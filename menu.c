#include <stdio.h>
#include <stdlib.h>
/*#include <ncurses.h> #Esto por si nos hacemos los grosos*/

/*El programa debe llevar un registro de los pedidos recibidos, permitiendo 
 * agregar un nuevo pedido, modificar la cantidad de pizzas de un pedido 
 * y cancelar un pedido.
	 * DISEÑO: una única lista llamada "pedidos" en la cual se agregan los nuevos,
	 * se modifican sus atributos y se cancelan. Propongo una lista porque ni
	 * la cola ni la pila me permiten acceder a elementos que se encuentran
	 * en el medio (ni principio ni fin). En la lista cobrará importancia
	 * el ORDEN de los elementos.
 
 
 
* Además debe contar con una opci ́on para preparar todos los pedidos, 
* agrupa ́ndolos segu ́n la zona de env ́ıo (los pedidos se preparan en 
* el orden que fueron registrados). Una vez que los pedidos son preparados
* no pueden ser modificados ni cancelados.
	* DISEÑO: 5 colas (una por zona) llamadas "zona1", "zona2"..., en la que se van encolando los pedidos
	* de acuerdo a su atributo "zona" y respetando su orden. Las características
	* de los pedidos no se pueden modificar por enunciado y porque la estructura
	* de cola no lo permite.



 
* Finalmente debe permitir enviar los pedidos a los clientes. Esto consiste
*  en sacar algunos de los pedidos preparados por zona, utilizando una 
* estrategia que permita optimizar los env ́ıos. Los pedidos que no 
* entren en la moto deber ́ıan postergarse para poder maximizar la cantidad
*  de pedidos a env ́ıar en cada viaje. El programa debe informar los 
* pedidos enviados.
	* DISEÑO: se cuenta con 1 moto capaz de llevar 5 pizzas a la vez. La moto
	* será una pila "moto" en la cual se apilan las pizzas de los pedidos. 
	* El máximo de pizzas por pedido es 5. La moto podrá llevar únicamente 
	* pedidos enteros, es decir :
	* 	- 1 pedido de 5 pizzas
	* 	- 2 pedidos de 1 y 4 pizzas c/1
	* 					2 y 3 pizzas c/1
	* 	- 3 pedidos de 1, 2 y 2 pizzas c/1 
	* 					3, 1 y 1 pizzas c/1
	* 	- 4 pedidos de 1, 1, 1 y 2 pizzas c/1
	* 	- 5 pedidos de 1, 1, 1, 1 y 1 pizzas c/1
	* IMPORTANTE: para que la moto se llene siempre de 5 pizzas, los pedidos
	* que queden "cortados" tienen que ser postergados. Es decir, el des-
	* encolamiento de los primeros pedidos en la cola deberá "saltearse"
	* al primero para apilar el segundo (o así sucesivamente hasta encontrar
	* un pedido que se ajuste a las cantidades de la moto). Sugerencia:
	* dado que el método desencolar no permite saltearse nodos, se crean
	* colas auxiliares con los pedidos postergados. Éstos serán los primeros
	* en intentar desencolar cuando se vaya a llenar una moto vacía (porque
	* llevan esperando más tiempo!). Si ninguno de los pedidos de la cola
	* auxiliar cumple los requerimientos de la moto, recién ahí se pasa a
	* intentar desencolar las colas "zonai". 



* El programa debe permitir observar el estado de la pizzer ́ıa incluyendo 
* los pedidos registrados hasta el momento, los pedidos preparados (por zona)
* y los u ́ltimos N pedidos enviados (desde el ma ́s reciente al más antiguo).
	* DISEÑO: básicamente es una posibilidad de printear la lista "pedidos",
	* las colas "zonai" y las últimas pila-moto que se se han creado. Para 
	* imprimir las motos pasadas, éstas deben ir apilándose en una pila 
	* "motos_enviadas" dentro de las funciones de la moto. "motos_enviadas" es
	* una pila porque al printearla se utilizará el método desapilar que devolverá
	* los pedidos desde el más reciente hasta el más antiguo.




* El programa debera ́ contar con una menu ́ de opciones para la funcionalidad 
* mencionada.

 *##################################################################################
 *##                                Menu                                          ##
 *##################################################################################
 */
