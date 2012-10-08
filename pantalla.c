#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LARGO 25
#define MAX_CADENA LARGO-2

void lp(void){
    system( "clear" );
}


void barra0(char caracter){
    for (int n =0; n < LARGO; n++) printf("%c  ", caracter);
    puts("");
    for (int n =0; n < LARGO; n++) printf("  %c", caracter);
    puts("");
}


void barra1(char caracter){
    for (int n =0; n < LARGO; n++) printf("%c  ", caracter);
    puts("");
}


void getch(void){
    system( "read");
}
