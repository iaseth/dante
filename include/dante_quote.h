#ifndef DANTE_QUOTE_H_INCLUDED
#define DANTE_QUOTE_H_INCLUDED

#include "dante_book.h"

DanteQuote dante_new_quote (DanteBook book);
DanteQuote dante_new_quote_n (DanteBook book, uint32_t length);
DanteQuote dante_new_quote_s (DanteBook book, char *text);
DanteQuote dante_new_quote_q (DanteQuote source_quote);
DanteQuote dante_duplicate_quote (DanteQuote source_quote);
DanteQuote dante_new_quote_from_file (DanteBook book, char *filename);

DanteQuote dante_append_quote (DanteQuote q1, DanteQuote q2);

DanteQuote dante_delete_quote (DanteQuote quote);



#endif