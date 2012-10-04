#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LARGO 25
#define MAX_CADENA LARGO-2
/*Todas las funciones que trabajan con la pantalla*/

void lp(void)
{
    /*Limpia la pantalla*/
    /*Esta funcion solo es compatible con *bsd, *linux, macos, y algunos mas*/
    system( "clear" );

}


/*Printea una barra incleiblemente cool.*/
/*nos tenes envidia ncurses?*/
void barra0(char caracter)
{
    for (int n =0; n < LARGO; n++)
    {
        printf("%c  ", caracter);
    }
    puts("");
    
    for (int n =0; n < LARGO; n++)
    {
        printf("  %c", caracter);
    }
    puts("");
}

/*Printea una barra no tan cool como la anterior pero sigue siendo cool*/
void barra1(char  caracter)
{
    for (int n =0; n < LARGO; n++)
    {
        printf("%c  ", caracter);
    }
    puts("");
}

/*Espera un caracter para continua*/
void getch(void)
{
    system( "read");
}

/*[>Decorador ultra sexy<]*/
/*void decorar_sexy( char cadena, char caracter )*/
/*{*/
    /*int cad_largo = strlen(*cadena);*/
    /*int val_aux = 0;*/
    /*char cad_aux[100];*/
    /*barra1(caracter);*/
    /*// corto la cadena y la printeo*/
    /*if (cad_largo == MAX_CADENA)*/
    /*{*/
        /*printf("%c%s%c",caracter,cadena,caracter);*/
        /*return;*/
    /*}*/
    /*else if (cad_largo < MAX_CADENA)*/
    /*{*/
        /*val_aux = MAX_CADENA - cad_largo;*/

        /*strcpy(cad_aux,caracter);*/
        /*[>Relleno con espacios el principio<]*/
        /*for (int i =0, int <= (val_aux/2), i ++)*/
            /*strcpy(cad_aux," ");*/

        /*[>Copio la cadena<]*/
        /*strcpy(cad_aux, cadena);*/
        
        /*[>Relleno con espacios el final<]*/
        /*for (int i =0, int <= (val_aux/2)-1 , i ++)*/
            /*strcpy(cad_aux, " ");*/

        /*strcpy(cad_aux,caracter);*/

        /*printf("%s\n",cad_aux);*/


    /*}*/

/*}*/




