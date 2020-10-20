#include "dante_quote.h"

#include <stdlib.h>
#include <string.h>

DanteQuote dante_new_quote_s (Dante dante, char *text) {
	DanteQuote quote = malloc(sizeof(DanteQuote_t));
	quote->length = strlen(text);
	quote->buffer = malloc((quote->length + 1) * sizeof(char));
	strcpy(quote->buffer, text);
	quote->capacity = quote->length;
	return quote;
}

DanteQuote dante_new_quote_from_file (Dante dante, char *filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL){
		return NULL;
	}

	DanteQuote quote = malloc(sizeof(DanteQuote_t));

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

DanteQuote dante_delete_quote (Dante dante, DanteQuote quote) {
	if (quote != NULL) {
		free(quote->buffer);
		free(quote);
	}
	return NULL;
}


