#include <stdio.h>

#include "dante.h"

int main (int argc, char const *argv[]) {
	Dante dante = dante_new_dante();
	DanteQuote quote = dante_new_quote(dante);
	quote = dante_delete_quote(dante, quote);
	dante = dante_delete_dante(dante);
}
