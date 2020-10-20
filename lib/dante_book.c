#include "dante_book.h"

#include "dante_quote.h"
#include "dante_canto.h"

#include <stdio.h>
#include <stdlib.h>

void dante_print_struct_sizes () {
	printf("DanteBook is %ld bytes.\n", sizeof(DanteBook_t));
	printf("DanteCanto is %ld bytes.\n", sizeof(DanteCanto_t));
	printf("DanteQuote is %ld bytes.\n", sizeof(DanteQuote_t));
}


void dante_print_quote_details (DanteQuote quote) {
	printf("DanteQuote (\"%s\", %d/%d)\n", quote->buffer, quote->length, quote->capacity);
}

void dante_print_canto_details (DanteCanto canto) {
	printf("DanteCanto (%d/%d quotes)\n", canto->quote_count, canto->quote_capacity);
}

void dante_print_dante_details (DanteBook book) {
	printf("DanteBook (%d/%d quotes, %d/%d cantos)\n",
		book->quote_count, book->quote_capacity,
		book->canto_count, book->canto_capacity
	);
}


DanteBook dante_new_dante () {
	DanteBook book = malloc(sizeof(DanteBook_t));
	book->cantos = malloc(DANTE_MINIMUM_CANTOS * sizeof(DanteCanto_t));
	book->canto_count = 0;
	book->canto_capacity = DANTE_MINIMUM_CANTOS;

	book->quotes = malloc(DANTE_MINIMUM_QUOTES * sizeof(DanteQuote_t));
	book->quote_count = 0;
	book->quote_capacity = DANTE_MINIMUM_QUOTES;
	return book;
}


void dante_add_quote_to_book (DanteBook book, DanteQuote quote) {
	quote->book = book;
	if (book == NULL) {
		return;
	}
	if (book->quote_count == book->quote_capacity) {
		// expand book->quotes
	}
	book->quotes[book->quote_count] = quote;
	book->quote_count++;
}

void dante_add_canto_to_book (DanteBook book, DanteCanto canto) {
	canto->book = book;
	if (book->canto_count == book->canto_capacity) {
		// expand book->cantos
	}
	book->cantos[book->canto_count] = canto;
	book->canto_count++;
}


DanteBook dante_delete_dante (DanteBook book) {
	for (int i = 0; i < book->quote_count; ++i) {
		dante_delete_quote(book->quotes[i]);
	}
	free(book->quotes);

	for (int i = 0; i < book->canto_count; ++i) {
		dante_delete_canto(book->cantos[i]);
	}
	free(book->cantos);

	free(book);
	return NULL;
}



