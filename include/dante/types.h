#ifndef DANTE_TYPES_H_INCLUDED
#define DANTE_TYPES_H_INCLUDED


#include <stdio.h>
#include <stdbool.h>


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
	DanteString (*new) (size_t length);
	DanteString (*from) (char *s);
	DanteString (*delete) (DanteString d);

	DanteString (*reserve) (DanteString d, size_t length);
	DanteString (*resize)  (DanteString d, size_t length);

	DanteString (*pad_start)  (DanteString d, char c);
	DanteString (*pad_end)    (DanteString d, char c);

	DanteString (*pads_start) (DanteString d);
	DanteString (*pads_end)   (DanteString d);

	DanteString (*append)  (DanteString d, DanteString d2, long index);
	DanteString (*prepend) (DanteString d, DanteString d2, long index);
	DanteString (*insert)  (DanteString d, DanteString d2, long index);

	DanteString (*slice)   (DanteString d, long start, long end);
	DanteString (*sub)     (DanteString d, long start, size_t length);
	DanteString (*prefix)  (DanteString d, size_t length);
	DanteString (*suffix)  (DanteString d, size_t length);
	DanteString (*copy)    (DanteString d);

	// functions that never allocate new memory return DanteStringNamespace allowing them to be chained
	DanteStringNamespace (*lower) (DanteString d);
	DanteStringNamespace (*title) (DanteString d);
	DanteStringNamespace (*upper) (DanteString d);

	DanteStringNamespace (*reverse) (DanteString d);

	DanteStringNamespace (*trim)  (DanteString d, DanteString d2);
	DanteStringNamespace (*ltrim) (DanteString d, DanteString d2);
	DanteStringNamespace (*rtrim) (DanteString d, DanteString d2);

	DanteStringNamespace (*trimc)  (DanteString d, char c);
	DanteStringNamespace (*ltrimc) (DanteString d, char c);
	DanteStringNamespace (*rtrimc) (DanteString d, char c);

	DanteStringNamespace (*trims)  (DanteString d);
	DanteStringNamespace (*ltrims) (DanteString d);
	DanteStringNamespace (*rtrims) (DanteString d);

	bool (*is_alpha) (DanteString d);
	bool (*is_alnum) (DanteString d);
	bool (*is_digit) (DanteString d);

	bool (*is_lower) (DanteString d);
	bool (*is_title) (DanteString d);
	bool (*is_upper) (DanteString d);

	bool (*starts_with) (DanteString d, DanteString d2);
	bool (*ends_with)   (DanteString d, DanteString d2);

	bool (*contains) (DanteString d, DanteString d2);
};


void dante_print_struct_sizes ();

void dante_print_quote_details (DanteQuote quote);
void dante_print_canto_details (DanteCanto canto);
void dante_print_dante_details (DanteBook book);




#endif