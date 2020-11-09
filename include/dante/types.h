#ifndef DANTE_TYPES_H_INCLUDED
#define DANTE_TYPES_H_INCLUDED


#include <stdio.h>

#define DANTE_MINIMUM_CHARS 16
#define DANTE_MINIMUM_QUOTES 16
#define DANTE_MINIMUM_CANTOS 16


struct DanteBook;
struct DanteQuote;
struct DanteCanto;

typedef struct DanteBook *DanteBook;
typedef struct DanteQuote *DanteQuote;
typedef struct DanteCanto *DanteCanto;


struct DanteQuote {
	DanteBook book;
	size_t length;
	size_t capacity;
	char *buffer;
};


struct DanteCanto {
	DanteBook book;
	size_t quote_count;
	size_t quote_capacity;
	DanteQuote *quotes;
};


struct DanteBook {
	size_t canto_count;
	size_t canto_capacity;
	DanteCanto *cantos;

	size_t quote_count;
	size_t quote_capacity;
	DanteQuote *quotes;
};

void dante_print_struct_sizes ();

void dante_print_quote_details (DanteQuote quote);
void dante_print_canto_details (DanteCanto canto);
void dante_print_dante_details (DanteBook book);




#endif