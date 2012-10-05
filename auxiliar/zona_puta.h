#ifndef ZONA_H
#define ZONA_H

//typedef zona zona_t;
typedef struct zona{
    cola_t* cola_ppal;
    lista_con_iter_t* lista_espera;
    int num;
}zona_t;
 zona_t* zona_crear();

#endif
