#!/bin/bash

OPCIONES="-std=c99 -Wall -pedantic -g"

#~ # todo
#~ 
O="preparadosymoto.o pedidos.o  tdas.o pantalla.o interaccion.o" 
C="preparadosymoto.c pedidos.c  tdas.c pantalla.c interaccion.c" 


echo "MAIN:::::::::::::::::::::::::::::::::::::::::::::";
gcc $OPCIONES -c $C;
gcc $OPCIONES  $O main.c -o main.bin;
echo "TEST:::::::::::::::::::::::::::::::::::::::::::::";
gcc $OPCIONES  $O test.c -o test.bin;

