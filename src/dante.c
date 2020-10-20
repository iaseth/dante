#include <stdio.h>

#include "dante.h"

int main (int argc, char const *argv[]) {
	DanteBook book = dante_new();
	DanteQuote quote = dante_new_quote_s(book, "Hello, Dante!");

	quote = dante_append_quote(quote, quote);

	DanteQuote license = dante_new_quote_from_file(book, "LICENSE");
	DanteCanto canto = dante_split_lines(license);

	for (int i = 0; i < canto->quote_count; ++i) {
		printf("%3d. '%s'\n", i, canto->quotes[i]->buffer);
	}

	DanteQuote empty = dante_duplicate_quote(quote);
	//dante_print_quote_details(empty);

	//dante_print_struct_sizes();

	dante_print_quote_details(quote);
	dante_print_canto_details(canto);
	dante_print_dante_details(book);

	book = dante_delete(book);
}
