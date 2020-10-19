#include "dante_quote.h"

#include <stdlib.h>
#include <string.h>

DanteQuote dante_new_quote (Dante dante, char *text) {
	DanteQuote quote = malloc(sizeof(DanteQuote_t));
	quote->length = strlen(text);
	quote->buffer = malloc((quote->length + 1) * sizeof(char));
	strcpy(quote->buffer, text);
	quote->capacity = quote->length;
	return quote;
}

DanteQuote dante_delete_quote (Dante dante, DanteQuote quote) {
	free(quote->buffer);
	free(quote);
	return NULL;
}


