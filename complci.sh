#!/bin/bash
OPCIONES="-std=c99 -Wall -pedantic -g"


gcc $OPCIONES -c lista.c 

gcc $OPCIONES lista.o lista_con_iter.c -o lista_con_iter.bin