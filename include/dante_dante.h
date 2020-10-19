#ifndef DANTE_DANTE_H_INCLUDED
#define DANTE_DANTE_H_INCLUDED

#include "dante_canto.h"
#include "dante_quote.h"

#include <stdint.h>


typedef struct {
	char *buffer;
	uint8_t length;
	uint8_t capacity;
} DanteQuote_t;

typedef DanteQuote_t *DanteQuote;


typedef struct {
	DanteQuote *quotes;
	uint8_t length;
	uint8_t capacity;
} DanteCanto_t;

typedef DanteCanto_t *DanteCanto;


typedef struct {
	DanteCanto *cantos;
	uint8_t number_of_cantos;
	DanteQuote *quotes;
	uint8_t number_of_quotes;
} Dante_t;

typedef Dante_t *Dante;


Dante dante_new_dante ();
DanteQuote dante_new_quote (Dante dante);
DanteCanto dante_new_canto (Dante dante);

Dante dante_delete_dante (Dante dante);
DanteQuote dante_delete_quote (Dante dante, DanteQuote quote);
DanteCanto dante_delete_canto (Dante dante, DanteCanto canto);




#endif