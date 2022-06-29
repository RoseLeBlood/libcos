
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
#include <stdlib.h>
#include <ctype.h>
#include "libcos/errno.h"

long strtol(const char *str, char **endptr, int base) {

	long retval = 0;
    int overflow = 0;
    char sign = 0;
    int digit;

    while (isspace(*str)) {
        str++;
    }

    // Moegliches Vorzeichen auswerten
    if (*str == '+' || *str == '-') {
        sign = *str;
        str++;
    }

    // Moegliches 0, 0x und 0X auswerten
    if (*str == '0')
    {
        if (str[1] == 'x' || str[1] == 'X') {
            if (base == 0) {
                base = 16;
            }

            if (base == 16 && isxdigit(str[2])) {
                str += 2;
            }
        } else if (base == 0) {
            base = 8;
        }
    }

    while (*str)
    {
        if (isdigit(*str) && *str - '0' < base) {
            digit = *str - '0';
        } else if(isalpha(*str) && tolower(*str) - 'a' + 10 < base) {
            digit = tolower(*str) - 'a' + 10;
        } else {
            break;
        }

        if (retval > (LONG_MAX - digit) / base) {
            overflow = 1;
        }
        retval = retval * base + digit;

        str++;
    }

    if (endptr != NULL) {
        if(endptr != NULL) *(const char**)endptr = str;
    }

    if (overflow) {
        errno = ERANGE;
        return (sign == '-') ? LONG_MIN : LONG_MAX;
    }

    return (sign == '-') ? -retval : retval;

}