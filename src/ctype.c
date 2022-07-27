
/*
* MIT License
*
* Copyright (c) 2022 Amber-Sophia Schröck

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "types.h"

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

typedef union _priv_convert {
    unsigned long long l;
    double d;
} _priv_convert_t;

int isnan(double d) {
    _priv_convert_t _conv;
    _conv.d = d;

    return (_conv.l == 0x7FF8000000000000ll || 
            _conv.l == 0x7FF0000000000000ll || 
            _conv.l == 0xfff8000000000000ll);
}
int isinf(double d) {
    _priv_convert_t _conv;
    _conv.d = d;

    return (_conv.l == 0x7FF0000000000000ll ? 1 : 
            _conv.l == 0xFFF0000000000000ll ? -1 : 0);
}