
#include "libcos/types.h"

int isblank(int c) {
    return (c == ' ' || c == '\t');
}

int iscntrl(int c)     {
    return c >= 0x0 && c <= 0x8;
}

int isdigit(int c) {
        return c >= '0' && c <= '9';
}

int ispunct(int c) {
     return (c >= 0x21 && c <= 0x2F) || (c >= 0x3A && c <= 0x40) || (c >= 0x5B && c <= 0x60) || (c >= 0x7B && c <= 0x7E);
}

int isspace(int c) {
    return c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\f' || c == '\v';
}

int islower(int c) {
    return c >= 'a' && c <= 'z';
}

int isupper(int c) {
     return c >= 'A' && c <= 'Z';
}

#undef isxdigit
int isxdigit(int c)  {
    return isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

int tolower(int c) {
	if (isupper(c)) return c + 'a' - 'A';
	return c;
}

int toupper(int c) {
	if (islower(c))  return c - 'a' + 'A';
	return c;
}


int isalpha(int c) {
    return islower(c) || isupper(c);
}

int isalnum(int c) {
     return isalpha(c) || isdigit(c);
}

int isgraph(int c) {
    return ispunct(c) || isalnum(c);
}

int isprint(int c)  {
    return isgraph(c) || isspace(c);
}


int ispoint (int c) {
    return (c == '.');
}
int isexponent(int c) {
    return (c == 'e' || c == 'E') ;
}
