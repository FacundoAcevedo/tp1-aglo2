#Makefile - TP1 (Pizzeria de gerli)
#Integrantes:
	#Maria Dulce Lauria
	#Facundo M. Acevedo

#Corrector:
	#Martín Buchwald

#Variables:
EXEC=main
CFLAGS= -std=c99 -g -Wall -pedantic 
CC=gcc
OBJ=preparadosymoto.o pedidos.o  tdas.o pantalla.o interaccion.o
.PHONY : clean install

all: $(EXEC)

interaccion.o: interaccion.c interaccion.h
	$(CC) $(CFLAGS) -c interaccion.c

tdas.o: tdas.c tdas.h
	$(CC) $(CFLAGS) -c tdas.c
	
pantalla.o: pantalla.c pantalla.h
	$(CC) $(CFLAGS) -c pantalla.c
	
pedidos.o: pedidos.c pedidos.h
	$(CC) $(CFLAGS) -c pedidos.c


preparardosymoto.o: preparardosymoto.c preparardosymoto.h
	$(CC) $(CFLAGS) -c preparardosymoto.c

$(EXEC): $(OBJ) $(EXEC).c
	$(CC) $(CFLAGS) $(OBJ) $(EXEC).c -o $(EXEC).bin

test: $(OBJ) test.c
	$(CC) $(CFLAGS) $(OBJ) test.c -o test.bin

clean: 
	rm -f  $(OBJ) $(EXEC).bin test.bin
