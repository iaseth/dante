#include <stdio.h>

#include "dante.h"

int main (int argc, char const *argv[]) {
	Dante dante = dante_new_dante();
	DanteQuote quote = dante_new_quote_s(dante, "Hello, Dante!");
	DanteCanto canto = dante_new_canto(dante);

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

	canto = dante_delete_canto(canto);
	dante = dante_delete_dante(dante);
}
