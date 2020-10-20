#include "dante_dante.h"

#include <stdio.h>
#include <stdlib.h>

void dante_print_struct_sizes () {
	printf("Dante is %ld bytes.\n", sizeof(Dante_t));
	printf("DanteCanto is %ld bytes.\n", sizeof(DanteCanto_t));
	printf("DanteQuote is %ld bytes.\n", sizeof(DanteQuote_t));
}


void dante_print_quote_details (DanteQuote quote) {
	printf("DanteQuote details:\n");
	printf(" content: %s\n", quote->buffer);
	printf("  length: %d\n", quote->length);
	printf("capacity: %d\n", quote->capacity);
}

void dante_print_canto_details (DanteCanto canto) {
	printf("DanteCanto (%d quotes, %d capacity)\n", canto->quote_count, canto->quote_capacity);
}

void dante_print_dante_details (Dante dante) {
	printf("Dante (%d quotes, %d cantos)\n", dante->quote_count, dante->canto_count);
}


Dante dante_new_dante () {
	Dante dante = malloc(sizeof(Dante_t));
	return dante;
}

Dante dante_delete_dante (Dante dante) {
	free(dante);
	return NULL;
}



