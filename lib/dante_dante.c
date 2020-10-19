#include "dante_dante.h"

#include <stdlib.h>

Dante dante_new_dante () {
	Dante dante = malloc(sizeof(Dante_t));
	return dante;
}

Dante dante_delete_dante (Dante dante) {
	free(dante);
	return NULL;
}



