#ifndef DANTE_QUOTE_H_INCLUDED
#define DANTE_QUOTE_H_INCLUDED

#include "dante_dante.h"

DanteQuote dante_new_quote (Dante dante);
DanteQuote dante_new_quote_n (Dante dante, uint32_t length);
DanteQuote dante_new_quote_q (Dante dante, DanteQuote quote);
DanteQuote dante_new_quote_s (Dante dante, char *text);
DanteQuote dante_new_quote_from_file (Dante dante, char *filename);

DanteQuote dante_delete_quote (Dante dante, DanteQuote quote);



#endif