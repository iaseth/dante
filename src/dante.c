#include <stdio.h>

#include "dante.h"

int main (int argc, char const *argv[]) {
	Dante dante = dante_new();
	DanteQuote quote = dante_new_quote_s(dante, "Hello, Dante!");
	DanteCanto canto = dante_new_canto(dante);

	quote = dante_append_quote(quote, quote);

	DanteQuote license = dante_new_quote_from_file(dante, "LICENSE");
	if (license != NULL) {
		//dante_print_quote_details(license);
	}

	DanteQuote empty = dante_duplicate_quote(quote);
	//dante_print_quote_details(empty);

	//dante_print_struct_sizes();

	dante_print_quote_details(quote);
	dante_print_canto_details(canto);
	dante_print_dante_details(dante);

	dante = dante_delete(dante);
}
