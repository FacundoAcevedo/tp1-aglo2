#!/bin/bash
OPCIONES="-std=c99 -Wall -pedantic -g"


gcc $OPCIONES -c lista.c lista_con_iter.c

gcc $OPCIONES lista.o lista_con_iter.o pedidos_entrantes.c -o entrantes.bin
