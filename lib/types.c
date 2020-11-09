#include "dante/types.h"

#include <stdio.h>


void
dante_print_struct_sizes ()
{
	printf("DanteBook is %ld bytes.\n", sizeof(DanteBook_t));
	printf("DanteCanto is %ld bytes.\n", sizeof(DanteCanto_t));
	printf("DanteQuote is %ld bytes.\n", sizeof(DanteQuote_t));
}


void
dante_print_quote_details (DanteQuote quote)
{
	printf("DanteQuote (\"%s\", %ld/%ld)\n", quote->buffer, quote->length, quote->capacity);
}

void
dante_print_canto_details (DanteCanto canto)
{
	printf("DanteCanto (%ld/%ld quotes)\n", canto->quote_count, canto->quote_capacity);
}

void
dante_print_dante_details (DanteBook book)
{
	printf("DanteBook (%ld/%ld quotes, %ld/%ld cantos)\n",
		book->quote_count, book->quote_capacity,
		book->canto_count, book->canto_capacity
	);
}


