#!/bin/bash

OPCIONES="-std=c99 -Wall -pedantic -g"



O="zonasymoto.o vect_din.o  pedidos.o  tdas.o" 
C="zonasymoto.c vect_din.c  pedidos.c  tdas.c" 


gcc $OPCIONES -c $C;
gcc $OPCIONES $O main.c -o main.bin;
