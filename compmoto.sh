#!/bin/bash
OPCIONES="-std=c99 -Wall -pedantic -g"

gcc $OPCIONES -c listaycola.c lista_con_iter.c pedidos_entrantes.c pila.c zonas.c 

gcc $OPCIONES listaycola.o lista_con_iter.o pedidos_entrantes.o pila.o zonas.o moto.c -o moto.bin
