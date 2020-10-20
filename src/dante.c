#include <stdio.h>

#include "dante.h"

int main (int argc, char const *argv[]) {
	Dante dante = dante_new_dante();
	DanteQuote quote = dante_new_quote(dante, "Hello, Dante!");

	dante_print_quote_details(quote);
	dante_print_dante_details(dante);

	//printf("%s\n", *quote);
	dante_print_struct_sizes();

	quote = dante_delete_quote(dante, quote);
	dante = dante_delete_dante(dante);
}
