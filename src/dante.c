#include <stdio.h>

#include "dante.h"

int main (int argc, char const *argv[]) {
	Dante dante = dante_new_dante();
	DanteQuote quote = dante_new_quote_s(dante, "Hello, Dante!");
	DanteCanto canto = dante_new_canto(dante);

	dante_print_quote_details(quote);
	dante_print_canto_details(canto);
	dante_print_dante_details(dante);

	DanteQuote license = dante_new_quote_from_file(dante, "LICENSE");
	if (license != NULL) {
		//dante_print_quote_details(license);
	}

	DanteQuote empty = dante_duplicate_quote(dante, quote);
	dante_print_quote_details(empty);

	dante_print_struct_sizes();

	empty = dante_delete_quote(dante, empty);
	license = dante_delete_quote(dante, license);
	quote = dante_delete_quote(dante, quote);
	canto = dante_delete_canto(dante, canto);
	dante = dante_delete_dante(dante);
}
