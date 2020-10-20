#ifndef DANTE_DANTE_H_INCLUDED
#define DANTE_DANTE_H_INCLUDED

#include <stdio.h>
#include <stdint.h>

#define DANTE_MINIMUM_CHARS 16
#define DANTE_MINIMUM_QUOTES 16
#define DANTE_MINIMUM_CANTOS 16


struct Dante_t;
struct DanteQuote_t;
struct DanteCanto_t;

typedef struct Dante_t Dante_t;
typedef struct DanteQuote_t DanteQuote_t;
typedef struct DanteCanto_t DanteCanto_t;

typedef struct Dante_t *Dante;
typedef struct DanteQuote_t *DanteQuote;
typedef struct DanteCanto_t *DanteCanto;


struct DanteQuote_t {
	char *buffer;
	uint32_t length;
	uint32_t capacity;
	Dante owner;
};


struct DanteCanto_t {
	DanteQuote *quotes;
	uint32_t quote_count;
	uint32_t quote_capacity;
	Dante owner;
};


struct Dante_t {
	DanteCanto *cantos;
	DanteQuote *quotes;
	uint32_t canto_count;
	uint32_t canto_capacity;
	uint32_t quote_count;
	uint32_t quote_capacity;
};


void dante_print_struct_sizes ();

void dante_print_quote_details (DanteQuote quote);
void dante_print_canto_details (DanteCanto canto);
void dante_print_dante_details (Dante dante);

Dante dante_new_dante ();

void dante_add_quote_to_dante (Dante dante, DanteQuote quote);
void dante_add_canto_to_dante (Dante dante, DanteCanto canto);

Dante dante_delete_dante (Dante dante);




#endif