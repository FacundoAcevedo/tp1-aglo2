#!/bin/bash

OPCIONES="-std=c99 -Wall -pedantic -g"

#~ # todo
#~ 
O="zonasymoto.o pedidos.o  tdas.o pantalla.o" 
C="zonasymoto.c pedidos.c  tdas.c pantalla.c" 


gcc $OPCIONES -c $C;
gcc $OPCIONES  $O main.c -o main.bin;

#~ # solo pedidos

#~ gcc $OPCIONES -c tdas.c;
#~ gcc $OPCIONES tdas.o pedidos.c -o pedidos.bin;

# zonasymoto y pedidos

#~ gcc $OPCIONES -c $C;
#~ gcc $OPCIONES tdas.o pedidos.c -o pedidos.bin;
