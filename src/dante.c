#include <stdio.h>

#include "dante.h"

int main (int argc, char const *argv[]) {
	Dante dante = dante_new_dante();
	DanteQuote quote = dante_new_quote(dante, "Hello, Dante!");
	DanteCanto canto = dante_new_canto(dante);

	dante_print_quote_details(quote);
	dante_print_canto_details(canto);
	dante_print_dante_details(dante);

	//printf("%s\n", *quote);
	dante_print_struct_sizes();

	quote = dante_delete_quote(dante, quote);
	canto = dante_delete_canto(dante, canto);
	dante = dante_delete_dante(dante);
}
