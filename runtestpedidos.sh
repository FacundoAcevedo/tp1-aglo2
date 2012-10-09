#!/bin/bash

OPCIONES="-std=c99 -Wall -pedantic -g"

#~ # todo
#~ 
O="preparadosymotoBACKUP.o pedidos.o  tdas.o pantalla.o" 
C="preparadosymotoBACKUP.c pedidos.c  tdas.c pantalla.c" 


gcc $OPCIONES -c $C;
echo "TEST PEDIDOS:::::::::::::::::::::::::::::::::::::::::::::";
gcc $OPCIONES  $O testpedidos.c -o testpedidos.bin;
