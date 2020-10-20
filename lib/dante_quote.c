#include "dante_quote.h"

#include <stdlib.h>
#include <string.h>

DanteQuote dante_new_quote (Dante dante) {
	return dante_new_quote_n(dante, DANTE_MINIMUM_CHARS);
}

DanteQuote dante_new_quote_n (Dante dante, uint32_t length) {
	DanteQuote quote = malloc(sizeof(DanteQuote_t));
	dante_add_quote_to_dante(dante, quote);
	quote->buffer = malloc((length + 1) * sizeof(char));
	quote->buffer[0] = '\0';
	quote->length = 0;
	quote->capacity = length;
	return quote;
}

DanteQuote dante_new_quote_s (Dante dante, char *text) {
	DanteQuote quote = malloc(sizeof(DanteQuote_t));
	dante_add_quote_to_dante(dante, quote);
	quote->length = strlen(text);
	quote->buffer = malloc((quote->length + 1) * sizeof(char));
	strcpy(quote->buffer, text);
	quote->capacity = quote->length;
	return quote;
}

DanteQuote dante_new_quote_q (DanteQuote source_quote) {
	DanteQuote quote = malloc(sizeof(DanteQuote_t));
	dante_add_quote_to_dante(source_quote->dante, quote);
	quote->buffer = malloc((source_quote->length + 1) * sizeof(char));
	strcpy(quote->buffer, source_quote->buffer);
	quote->length = source_quote->length;
	quote->capacity = source_quote->capacity;
	return quote;
}

DanteQuote dante_duplicate_quote (DanteQuote source_quote) {
	return dante_new_quote_q(source_quote);
}

DanteQuote dante_new_quote_from_file (Dante dante, char *filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL){
		return NULL;
	}

	DanteQuote quote = malloc(sizeof(DanteQuote_t));
	dante_add_quote_to_dante(dante, quote);

	long p1 = ftell(fp);
	fseek(fp, p1, SEEK_END);
	long p2 = ftell(fp);
	fseek(fp, p1, SEEK_SET);

	quote->length = p2 - p1;
	quote->buffer = malloc((quote->length + 1) * sizeof(char));
	fread(quote->buffer, sizeof(char), quote->length, fp);
	fclose(fp);
	quote->buffer[quote->length] = '\0';
	quote->capacity = quote->length;
	return quote;
}

DanteQuote dante_delete_quote (DanteQuote quote) {
	if (quote != NULL) {
		free(quote->buffer);
		free(quote);
	}
	return NULL;
}


