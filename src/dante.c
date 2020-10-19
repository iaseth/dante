#include <stdio.h>

#include "dante.h"

int main (int argc, char const *argv[]) {
	Dante dante = dante_new_dante();
	dante = dante_delete_dante(dante);
}
