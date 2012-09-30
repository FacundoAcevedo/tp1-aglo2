/* This file was automatically generated.  Do not edit! */
void pedidos_entrantes_destruir(lista_con_iter_t *pedidos_entrantes);
bool pedidos_entrantes_cancelar(lista_con_iter_t *pedidos_entrantes,unsigned int id);
bool pedidos_entrantes_cant_pizzas(lista_con_iter_t *pedidos_entrantes,unsigned int id,int nueva_cant);
bool pedidos_entrantes_zona(lista_con_iter_t *pedidos_entrantes,unsigned int id,int nueva_zona);
pedido_t *pedidos_entrantes_sacar(lista_con_iter_t *pedidos_entrantes);
bool pedidos_entrantes_agregar(lista_con_iter_t *pedidos_entrantes,pedido_t *pedido);
size_t pedidos_entrantes_largo(const lista_con_iter_t *pedidos_entrantes);
lista_con_iter *pedidos_entrantes_crear();
bool pedido_cambiar_cant(pedido_t *pedido,int nueva_cant);
bool pedido_cambiar_zona(pedido_t *pedido,int nueva_zona);
void(destruir_pedido)(void *dato);
void pedido_destruir(pedido_t *pedido);
pedido_t *pedido_crear(int zona,int cant_pizzas);
unsigned int get_id();
