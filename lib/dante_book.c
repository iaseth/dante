#include "dante_book.h"

#include "dante_quote.h"
#include "dante_canto.h"

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
	printf("DanteCanto (%d/%d quotes)\n", canto->quote_count, canto->quote_capacity);
}

void dante_print_dante_details (Dante dante) {
	printf("Dante (%d/%d quotes, %d/%d cantos)\n",
		dante->quote_count, dante->quote_capacity,
		dante->canto_count, dante->canto_capacity
	);
}


Dante dante_new_dante () {
	Dante dante = malloc(sizeof(Dante_t));
	dante->cantos = malloc(DANTE_MINIMUM_CANTOS * sizeof(DanteCanto_t));
	dante->canto_count = 0;
	dante->canto_capacity = DANTE_MINIMUM_CANTOS;

	dante->quotes = malloc(DANTE_MINIMUM_QUOTES * sizeof(DanteQuote_t));
	dante->quote_count = 0;
	dante->quote_capacity = DANTE_MINIMUM_QUOTES;
	return dante;
}


void dante_add_quote_to_dante (Dante dante, DanteQuote quote) {
	quote->owner = dante;
	if (dante->quote_count == dante->quote_capacity) {
		// expand dante->quotes
	}
	dante->quotes[dante->quote_count] = quote;
	dante->quote_count++;
}

void dante_add_canto_to_dante (Dante dante, DanteCanto canto) {
	canto->owner = dante;
	if (dante->canto_count == dante->canto_capacity) {
		// expand dante->cantos
	}
	dante->cantos[dante->canto_count] = canto;
	dante->canto_count++;
}


Dante dante_delete_dante (Dante dante) {
	for (int i = 0; i < dante->quote_count; ++i) {
		dante_delete_quote(dante->quotes[i]);
	}
	free(dante->quotes);

	for (int i = 0; i < dante->canto_count; ++i) {
		dante_delete_canto(dante->cantos[i]);
	}
	free(dante->cantos);

	free(dante);
	return NULL;
}



