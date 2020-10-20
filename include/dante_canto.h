#ifndef DANTE_CANTO_H_INCLUDED
#define DANTE_CANTO_H_INCLUDED

#include "dante_book.h"

DanteCanto dante_new_canto (DanteBook book);
DanteCanto dante_delete_canto (DanteCanto canto);

void dante_canto_double_capacity (DanteCanto canto);
void dante_add_quote_to_canto (DanteCanto canto, DanteQuote quote);

DanteCanto dante_split_words (DanteQuote quote);
DanteCanto dante_split_lines (DanteQuote quote);
DanteCanto dante_split_c (DanteQuote quote, char c);
DanteCanto dante_split_s (DanteQuote quote, char *s);
DanteCanto dante_split_q (DanteQuote quote, DanteQuote q);



#endif