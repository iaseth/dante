#include "dante/quote.h"

#include "dante/book.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

DanteQuote
dante_new_quote (DanteBook book)
{
	return dante_new_quote_n(book, DANTE_MINIMUM_CHARS);
}

DanteQuote
dante_new_quote_n (DanteBook book, size_t length)
{
	DanteQuote quote = malloc(sizeof(struct DanteQuote));
	dante_add_quote_to_book(book, quote);
	quote->buffer = malloc((length + 1) * sizeof(char));
	quote->buffer[0] = '\0';
	quote->length = 0;
	quote->capacity = length;
	return quote;
}

DanteQuote
dante_new_quote_s (DanteBook book, char *text)
{
	DanteQuote quote = malloc(sizeof(struct DanteQuote));
	dante_add_quote_to_book(book, quote);
	quote->length = strlen(text);
	quote->buffer = malloc((quote->length + 1) * sizeof(char));
	strcpy(quote->buffer, text);
	quote->capacity = quote->length;
	return quote;
}

DanteQuote
dante_new_quote_q (DanteQuote source_quote)
{
	DanteQuote quote = malloc(sizeof(struct DanteQuote));
	dante_add_quote_to_book(source_quote->book, quote);
	quote->buffer = malloc((source_quote->length + 1) * sizeof(char));
	strcpy(quote->buffer, source_quote->buffer);
	quote->length = source_quote->length;
	quote->capacity = source_quote->capacity;
	return quote;
}

DanteQuote
dante_duplicate_quote (DanteQuote source_quote)
{
	return dante_new_quote_q(source_quote);
}

DanteQuote
dante_new_quote_from_file (DanteBook book, char *filename)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL){
		return NULL;
	}

	DanteQuote quote = malloc(sizeof(struct DanteQuote));
	dante_add_quote_to_book(book, quote);

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


DanteQuote
dante_append_quote (DanteQuote q1, DanteQuote q2)
{
	DanteQuote quote = malloc(sizeof(struct DanteQuote));
	dante_add_quote_to_book(q1->book, quote);
	quote->length = q1->length + q2->length;
	quote->buffer = malloc((quote->length + 1) * sizeof(char));
	strcpy(quote->buffer, q1->buffer);
	strcpy(quote->buffer + (q1->length), q2->buffer);
	quote->capacity = quote->length;
	return quote;
}


DanteQuote
dante_delete_quote (DanteQuote quote)
{
	if (quote != NULL) {
		free(quote->buffer);
		free(quote);
	}
	return NULL;
}


