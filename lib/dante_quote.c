#include "dante_quote.h"

#include <stdlib.h>

DanteQuote dante_new_quote (Dante dante) {
	DanteQuote quote = malloc(sizeof(DanteQuote_t));
	return quote;
}

DanteQuote dante_delete_quote (Dante dante, DanteQuote quote) {
	free(quote);
	return NULL;
}


