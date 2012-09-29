#!/bin/bash

OPCIONES="-std=c99 -Wall -pedantic -g"
ARCHIVOS_O="lista.o  cola.o  pila.o  pedidos_entrantes.o  pedidos_salientes.o  buscador.o  moto.o  zonas.o"
ARCHIVOS_C="lista.c  cola.c  pila.c  pedidos_entrantes.c  pedidos_salientes.c  buscador.c  moto.c  zonas.c"



gcc $OPCIONES -c $ARCHIVOS_C
gcc $OPCIONES $ARCHIVOS_O -o prurebas.bin
