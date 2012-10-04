#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define LARGO 25
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
