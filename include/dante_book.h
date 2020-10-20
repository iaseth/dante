#ifndef DANTE_BOOK_H_INCLUDED
#define DANTE_BOOK_H_INCLUDED

#include "dante_types.h"

#define dante_new dante_new_dante
#define dante_delete dante_delete_dante


DanteBook dante_new_dante ();

void dante_add_quote_to_book (DanteBook book, DanteQuote quote);
void dante_add_canto_to_book (DanteBook book, DanteCanto canto);

DanteBook dante_delete_dante (DanteBook book);




#endif