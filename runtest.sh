#!/bin/bash

OPCIONES="-std=c99 -Wall -pedantic -g"

O="preparadosymoto.o pedidos.o  tdas.o pantalla.o" 
C="preparadosymoto.c pedidos.c  tdas.c pantalla.c" 


gcc $OPCIONES -c $C;
gcc $OPCIONES  $O test.c -o test.bin;
