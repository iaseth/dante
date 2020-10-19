#ifndef DANTE_CANTO_H_INCLUDED
#define DANTE_CANTO_H_INCLUDED

#include "dante_quote.h"
#include <stdint.h>

typedef struct {
	DanteQuote *quotes;
	uint8_t length;
	uint8_t capacity;
} DanteCanto_t;

typedef DanteCanto_t *DanteCanto;




#endif