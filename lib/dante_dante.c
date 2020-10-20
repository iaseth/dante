#include "dante_dante.h"

#include <stdio.h>
#include <stdlib.h>

void dante_print_struct_sizes () {
	printf("Dante is %ld bytes.\n", sizeof(Dante_t));
	printf("DanteCanto is %ld bytes.\n", sizeof(DanteCanto_t));
	printf("DanteQuote is %ld bytes.\n", sizeof(DanteQuote_t));
}


void dante_print_quote_details (DanteQuote quote) {
	printf("DanteQuote (\"%s\", %d/%d)\n", quote->buffer, quote->length, quote->capacity);
}

void dante_print_canto_details (DanteCanto canto) {
	printf("DanteCanto (%d quotes, %d capacity)\n", canto->quote_count, canto->quote_capacity);
}

void dante_print_dante_details (Dante dante) {
	printf("Dante (%d quotes, %d cantos)\n", dante->quote_count, dante->canto_count);
}


Dante dante_new_dante () {
	Dante dante = malloc(sizeof(Dante_t));
	dante->cantos = NULL;
	dante->canto_count = 0;
	dante->canto_capacity = 0;

	dante->quotes = NULL;
	dante->quote_count = 0;
	dante->quote_capacity = 0;
	return dante;
}

Dante dante_delete_dante (Dante dante) {
	free(dante);
	return NULL;
}



