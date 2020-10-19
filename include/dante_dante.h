#ifndef DANTE_DANTE_H_INCLUDED
#define DANTE_DANTE_H_INCLUDED

#include <stdint.h>


typedef struct {
	char *buffer;
	uint8_t length;
	uint8_t capacity;
} DanteQuote_t;

typedef DanteQuote_t *DanteQuote;


typedef struct {
	DanteQuote *quotes;
	uint8_t quote_count;
	uint8_t quote_capacity;
} DanteCanto_t;

typedef DanteCanto_t *DanteCanto;


typedef struct {
	DanteCanto *cantos;
	uint8_t canto_count;
	uint8_t canto_capacity;

	DanteQuote *quotes;
	uint8_t quote_count;
	uint8_t quote_capacity;
} Dante_t;

typedef Dante_t *Dante;


Dante dante_new_dante ();

Dante dante_delete_dante (Dante dante);




#endif