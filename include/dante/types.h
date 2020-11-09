#ifndef DANTE_TYPES_H_INCLUDED
#define DANTE_TYPES_H_INCLUDED


#include <stdio.h>

#define DANTE_MINIMUM_CHARS 16
#define DANTE_MINIMUM_QUOTES 16
#define DANTE_MINIMUM_CANTOS 16


struct DanteBook_t;
struct DanteQuote_t;
struct DanteCanto_t;

typedef struct DanteBook_t DanteBook_t;
typedef struct DanteQuote_t DanteQuote_t;
typedef struct DanteCanto_t DanteCanto_t;

typedef struct DanteBook_t *DanteBook;
typedef struct DanteQuote_t *DanteQuote;
typedef struct DanteCanto_t *DanteCanto;


struct DanteQuote_t {
	DanteBook book;
	size_t length;
	size_t capacity;
	char *buffer;
};


struct DanteCanto_t {
	DanteBook book;
	size_t quote_count;
	size_t quote_capacity;
	DanteQuote *quotes;
};


struct DanteBook_t {
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