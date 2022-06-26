#ifndef KLIBC_CTYPE_H
#define KLIBC_CTYPE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <types.h>


int             isalnum (int c);
int             isalpha (int c);
int             isblank (int c);
int             iscntrl (int c);
int             isdigit (int c);
int             isgraph (int c);
int             islower (int c);
int             isprint (int c);
int             ispunct (int c);
int             isspace (int c);
int             isupper (int c);
int             isxdigit(int c);
int             tolower (int c);
int             toupper (int c);

int             ispoint (int c);
int             isexponent(int c);


#ifdef __cplusplus
};
#endif

#endif