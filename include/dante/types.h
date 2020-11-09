#ifndef DANTE_TYPES_H_INCLUDED
#define DANTE_TYPES_H_INCLUDED


#include <stdio.h>


// minimum chars in a quote
#define DANTE_MINIMUM_CHARS 16

// minimum quotes in a canto/book
#define DANTE_MINIMUM_QUOTES 16

// minimum cantos in a book
#define DANTE_MINIMUM_CANTOS 16


// structs for internal use
struct DanteBook;
struct DanteQuote;
struct DanteCanto;

// typedeffed pointer types for external use
typedef char *DanteString;
typedef struct DanteBook *DanteBook;
typedef struct DanteQuote *DanteQuote;
typedef struct DanteCanto *DanteCanto;


// for internal use
struct DanteBookNamespace;
struct DanteCantoNamespace;
struct DanteQuoteNamespace;
struct DanteStringNamespace;

// const pointer types that are available as globals
typedef const struct DanteBookNamespace *const DanteBookNamespace;
typedef const struct DanteCantoNamespace *const DanteCantoNamespace;
typedef const struct DanteQuoteNamespace *const DanteQuoteNamespace;
typedef const struct DanteStringNamespace *const DanteStringNamespace;


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


struct DanteBookNamespace {
	//
};

struct DanteCantoNamespace {
	//
};

struct DanteQuoteNamespace {
	//
};

struct DanteStringNamespace {
	//
};


void dante_print_struct_sizes ();

void dante_print_quote_details (DanteQuote quote);
void dante_print_canto_details (DanteCanto canto);
void dante_print_dante_details (DanteBook book);




#endif