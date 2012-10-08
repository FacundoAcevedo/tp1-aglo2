#!/bin/bash

OPCIONES="-std=c99 -Wall -pedantic -g"

#~ # todo
#~ 
O="preparadosymoto.o pedidos.o  tdas.o pantalla.o" 
C="preparadosymoto.c pedidos.c  tdas.c pantalla.c" 


gcc $OPCIONES -c $C;
echo "TEST PEDIDOS:::::::::::::::::::::::::::::::::::::::::::::";
gcc $OPCIONES  $O testpedidos.c -o testpedidos.bin;
