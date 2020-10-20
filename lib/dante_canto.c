#include "dante_canto.h"

#include <stdlib.h>

DanteCanto dante_new_canto (Dante dante) {
	DanteCanto canto = malloc(sizeof(DanteCanto_t));
	canto->quotes = NULL;
	canto->quote_count = 0;
	canto->quote_capacity = 0;
	return canto;
}

DanteCanto dante_delete_canto (Dante dante, DanteCanto canto) {
	free(canto->quotes);
	free(canto);
	return NULL;
}


