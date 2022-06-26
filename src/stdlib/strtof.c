#include <stdlib.h>
#include <ctype.h>

float strtof (const char* nptr, char** endptr) {
	return (float)strtod(nptr, endptr);
}