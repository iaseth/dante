#ifndef DANTE_QUOTE_H_INCLUDED
#define DANTE_QUOTE_H_INCLUDED

#include "dante_dante.h"

DanteQuote dante_new_quote (Dante dante, char *text);
DanteQuote dante_delete_quote (Dante dante, DanteQuote quote);



#endif