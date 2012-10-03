#!/bin/bash
OPCIONES="-std=c99 -Wall -pedantic -g"


gcc $OPCIONES -c listaycola.c 

gcc $OPCIONES listaycola.o lista_con_iter.c -o lista_con_iter.bin
