#ifndef DANTE_DANTE_H_INCLUDED
#define DANTE_DANTE_H_INCLUDED

#include <stdint.h>


typedef struct {
	char *buffer;
	uint32_t length;
	uint32_t capacity;
} DanteQuote_t;

typedef DanteQuote_t *DanteQuote;


typedef struct {
	DanteQuote *quotes;
	uint32_t quote_count;
	uint32_t quote_capacity;
} DanteCanto_t;

typedef DanteCanto_t *DanteCanto;


typedef struct {
	DanteCanto *cantos;
	DanteQuote *quotes;
	uint32_t canto_count;
	uint32_t canto_capacity;
	uint32_t quote_count;
	uint32_t quote_capacity;
} Dante_t;

typedef Dante_t *Dante;


void dante_print_struct_sizes ();

Dante dante_new_dante ();
Dante dante_delete_dante (Dante dante);




#endif