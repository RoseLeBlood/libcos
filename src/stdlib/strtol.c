
#include <stdlib.h>
#include <ctype.h>
#include "libcos/errno.h"

#undef strtol
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