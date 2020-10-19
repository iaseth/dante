#include <stdio.h>

#include "dante.h"

int main (int argc, char const *argv[]) {
	Dante dante = dante_new_dante();
	DanteQuote quote = dante_new_quote(dante, "Hello, Dante!");

	printf("%p == %p\n", quote->buffer, quote);
	dante_print_struct_sizes();

	quote = dante_delete_quote(dante, quote);
	dante = dante_delete_dante(dante);
}
