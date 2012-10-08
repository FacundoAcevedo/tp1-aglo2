#!/bin/bash

OPCIONES="-std=c99 -Wall -pedantic -g"

#~ # todo
#~ 
O="preparadosymoto.o pedidos.o  tdas.o pantalla.o" 
C="preparadosymoto.c pedidos.c  tdas.c pantalla.c" 


#~ echo "MAIN:::::::::::::::::::::::::::::::::::::::::::::";
#~ gcc $OPCIONES -c $C;
#~ gcc $OPCIONES  $O main.c -o main.bin;
#~ echo "TEST:::::::::::::::::::::::::::::::::::::::::::::";
#~ gcc $OPCIONES  $O test.c -o test.bin;

#~ # solo pedidos

#~ gcc $OPCIONES -c tdas.c;
#~ gcc $OPCIONES tdas.o pedidos.c -o pedidos.bin;

# preparadosymoto y pedidos

#~ gcc $OPCIONES -c $C;
#~ gcc $OPCIONES tdas.o pedidos.c -o pedidos.bin;

#solo tdas

gcc $OPCIONES tdas.c -o tdas.bin;
