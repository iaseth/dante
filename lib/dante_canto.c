#include "dante_canto.h"

#include "dante_quote.h"
#include "dante_book.h"

#include <stdlib.h>
#include <string.h>

DanteCanto
dante_new_canto (DanteBook book)
{
	DanteCanto canto = malloc(sizeof(DanteCanto_t));
	dante_add_canto_to_book(book, canto);
	canto->quotes = malloc(DANTE_MINIMUM_QUOTES * sizeof(DanteQuote));
	canto->quote_count = 0;
	canto->quote_capacity = DANTE_MINIMUM_QUOTES;
	return canto;
}

DanteCanto
dante_delete_canto (DanteCanto canto)
{
	for (int i = 0; i < canto->quote_count; ++i) {
		dante_delete_quote(canto->quotes[i]);
	}
	free(canto->quotes);
	free(canto);
	return NULL;
}


void
dante_canto_double_capacity (DanteCanto canto)
{
	if (canto == NULL) return;
	int new_capacity = canto->quote_capacity * 2;
	int size = new_capacity * sizeof(DanteQuote);
	canto->quotes = realloc(canto->quotes, size);
	canto->quote_capacity = new_capacity;
}

void
dante_add_quote_to_canto (DanteCanto canto, DanteQuote quote)
{
	if (canto == NULL) return;
	if (quote == NULL) return;
	if (canto->quote_count == canto->quote_capacity) {
		dante_canto_double_capacity(canto);
	}
	canto->quotes[canto->quote_count] = quote;
	canto->quote_count++;
}


DanteCanto
dante_split_words (DanteQuote quote)
{
	return dante_split_c(quote, ' ');
}

DanteCanto
dante_split_lines (DanteQuote quote)
{
	return dante_split_c(quote, '\n');
}

DanteCanto
dante_split_c (DanteQuote quote, char c)
{
	DanteCanto canto = dante_new_canto(quote->book);
	DanteQuote current_quote = NULL;
	char current_string[quote->length + 1];

	int start_index = 0;
	int end_index = 0;
	int length = 0;

	for (int i = 0; i <= quote->length; i++) {
		char current_char = quote->buffer[i];
		if (current_char == c || current_char == '\0') {
			length = end_index - start_index;
			current_string[length] = '\0';
			current_quote = dante_new_quote_n(NULL, length);
			strcpy(current_quote->buffer, current_string);
			current_quote->length = length;
			dante_add_quote_to_canto(canto, current_quote);
			start_index = i;
			end_index = i;
		} else {
			current_string[end_index - start_index] = current_char;
			end_index++;
		}
	}
	return canto;
}

DanteCanto
dante_split_s (DanteQuote quote, char *s)
{
	//
	return NULL;
}

DanteCanto
dante_split_q (DanteQuote quote, DanteQuote q)
{
	//
	return NULL;
}


