#!/bin/bash
OPCIONES="-std=c99 -Wall -pedantic -g"

#~ gcc $OPCIONES -c listaycola.c lista_con_iter.c pedidos_entrantes.c pila.c
gcc $OPCIONES -c lista_cola.c lista_con_iter.c
#gcc $OPCIONES listaycola.o lista_con_iter.o zona_puta.c -o zona_puta.bin
