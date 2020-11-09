#ifndef DANTE_STRING_H_INCLUDED
#define DANTE_STRING_H_INCLUDED

#include "dante/types.h"

DanteString dante_new_string ();
DanteString dante_new_string_s (char *source);
DanteString dante_new_string_n (size_t length);
DanteString dante_new_string_d (DanteString dsource);

DanteString dante_delete_string (DanteString d);



#endif