lista_con_iter* lista_con_iter_crear(){
	lista_con_iter_t* lista_con_iter;
	lista_con_iter = malloc (sizeof(lista_con_iter_t));
	if (!lista_con_iter) return NULL;
	lista_t* lista;
	lista = lista_crear();
	lista_con_iter->lista = lista;
	lista_iter_t* iter;
	iter = lista_iter_crear(lista);
	lista_con_iter->iter = iter;
	return lista_con_iter;
	}

void lista_con_iter_destruir(lista_con_iter_t* lista_con_iter, (*destruir)){
	// Si lista_con_iter no existe, termina la funcion
	if (!lista_con_iter) return;

	// Se destruye el iterador de lista_con_iter
	lista_iter_destruir(lista_con_iter->iter);
	
	// Se destruye la lista con lista_destruir, pasándole la funcion destruir()
	lista_destruir(lista_con_iter->lista, (*destruir));
	// Se libera la estructura lista_con_iter
    free(lista_con_iter);
    return;
 }
