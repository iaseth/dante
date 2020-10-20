#include "dante_book.h"

#include "dante_quote.h"
#include "dante_canto.h"

#include <stdio.h>
#include <stdlib.h>


DanteBook
dante_new_book ()
{
	DanteBook book = malloc(sizeof(DanteBook_t));
	book->cantos = malloc(DANTE_MINIMUM_CANTOS * sizeof(DanteCanto_t));
	book->canto_count = 0;
	book->canto_capacity = DANTE_MINIMUM_CANTOS;

	book->quotes = malloc(DANTE_MINIMUM_QUOTES * sizeof(DanteQuote_t));
	book->quote_count = 0;
	book->quote_capacity = DANTE_MINIMUM_QUOTES;
	return book;
}


void
dante_add_quote_to_book (DanteBook book, DanteQuote quote)
{
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

void
dante_add_canto_to_book (DanteBook book, DanteCanto canto)
{
	canto->book = book;
	if (book->canto_count == book->canto_capacity) {
		// expand book->cantos
	}
	book->cantos[book->canto_count] = canto;
	book->canto_count++;
}


DanteBook
dante_delete_book (DanteBook book)
{
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



