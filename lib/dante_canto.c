#include "dante_canto.h"

#include <stdlib.h>

DanteCanto dante_new_canto (Dante dante) {
	DanteCanto canto = malloc(sizeof(DanteCanto_t));
	dante_add_canto_to_dante(dante, canto);
	canto->quotes = malloc(DANTE_MINIMUM_QUOTES * sizeof(DanteQuote_t));
	canto->quote_count = 0;
	canto->quote_capacity = DANTE_MINIMUM_QUOTES;
	return canto;
}

DanteCanto dante_delete_canto (DanteCanto canto) {
	free(canto->quotes);
	free(canto);
	return NULL;
}


