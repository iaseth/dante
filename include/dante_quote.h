#ifndef DANTE_QUOTE_H_INCLUDED
#define DANTE_QUOTE_H_INCLUDED

#include <stdint.h>

typedef struct {
	char *buffer;
	uint8_t length;
	uint8_t capacity;
} DanteQuote_t;

typedef DanteQuote_t *DanteQuote;



#endif