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

static unsigned long _rand_value = 1;

double atof (const char* nptr) {
	double a = 0.0;
	int e = 0;
	int c;
	int sign = 1;
	int i = 0;

	while ((c = *nptr++) != '\0' && isdigit(c)) {
		a = a * 10.0 + (c - '0');
	}

	if (c == '.') {
		while ((c = *nptr++) != '\0' && isdigit(c)) {
			a = a * 10.0 + (c - '0');
			e = e-1;
		}
	}

	if (c == 'e' || c == 'E') {
		c = *nptr++;
		if (c == '+') { c = *nptr++; sign = 1; }
		else if (c == '-') { c = *nptr++; sign = -1; }

		while (isdigit(c)) {
			i = i * 10 + (c - '0');
			c = *nptr++;
		}
		e += i * sign;
	}

	if( e > 0) {
		do {
			a *= 10.0; e--;
		} while(e > 0);
	} else if(e < 0) {
		do {
			a *= 0.1; e++;
		} while(e > 0);
	} 

	return a;
}

int atoi(const char* str) {
	int result = 0;
	bool neg = false;

	while (isspace(*str)) str++;

    if(*str == '-') { neg = true; str++; }
	if(*str == '+') { neg = false; str++; }

	while (isdigit(*str))
		result = (result * 10) + (*(str++) - '0');
	return result;
}

long int atol(const char* str) {
    long int result = 0;
    bool neg = false;

	while (isspace(*str)) str++;

	if(*str == '-') { neg = true; str++; }
	if(*str == '+') { neg = false; str++; }
	
	while (isdigit(*str))
			result = (result * 10) + (*(str++) - '0');
	return neg ? -result : result; 
}

long long int atoll(const char* str) {
    long long result = 0;
	bool neg = false;

	while(isspace(*str)) str++;

	if(*str == '-') { neg = true; str++; }
	if(*str == '+') { neg = false; str++; }

	while(isdigit(*str)) 
		result = (result * 10) + (*(str++) - '0');
	return neg ? -result : result;                         
}

int abs(int j) {
    return (j < 0) ? (-j) : j;
}

long int labs(long int j) {
    return (j < 0) ? (-j) : j;
}

long long int llabs(long long int j) {
    return (j < 0) ? (-j) : j;
}

div_t div(int numer, int denom) {
	div_t result;
	result.quot = numer / denom;
	result.rem = numer % denom;
	return result;
}

ldiv_t ldiv(long int numer, long int denom)  {
	ldiv_t result;
	result.quot = numer / denom;
	result.rem = numer % denom;
	return result;
}

lldiv_t lldiv(long long int numer, long long int denom) {
    lldiv_t retval;

	retval.quot = numer / denom;
	retval.rem = numer % denom;

	if(numer >= 0 && retval.rem < 0) {
		retval.quot++;
		retval.rem -= denom;
	}
	return retval;
}

int mblen(const char *s, size_t n) {
	if (s == (const char *)NULL) return 0;
	if (n <= 0) return 0;
	return (*s != 0);
}
int mbtowc(wchar_t *pwc, register const char *s, size_t n) {
	if (s == (const char *)NULL) return 0;
	if (n <= 0) return 0;
	if (pwc) *pwc = *s;
	return (*s != 0);
}
int wctomb  (char* s, wchar_t wchar) {
	if (!s) return 0;             
  
	*s = wchar;
	return 1;
}
size_t mbstowcs(register wchar_t *pwcs, register const char *s, size_t n) {
	register int i = n;

	while (--i >= 0) {
		if (!(*pwcs++ = *s++))
			return n - i - 1;
	}
	return n - i;
}
size_t  wcstombs(register char *s, register const wchar_t *pwcs, size_t n) {
	register int i = n;

	while (--i >= 0) {
		if (!(*s++ = *pwcs++)) break;
	}
	return n - i - 1;
}
void srand(unsigned int seed) {
	_rand_value = seed;
}

int rand() {
	unsigned int next = _rand_value;
  	int result;

 	next *= 1103515245;
  	next += 12345;
  	result = (unsigned int) (next / 65536) % 2048;

  	next *= 1103515245;
  	next += 12345;
  	result <<= 10;
 	result ^= (unsigned int) (next / 65536) % 1024;

  	next *= 1103515245;
  	next += 12345;
  	result <<= 10;
  	result ^= (unsigned int) (next / 65536) % 1024;


  	_rand_value = next;

   	return result;
}
int rand_m(int32_t min, int32_t max) {
	return min + rand() % ( max - min + 1 );
}
uint8_t* rand_bytes(uint8_t* buf, size_t size) {
	int i = 0;

	while(i < size) {
		buf[i] = (int8_t)rand_m(0, 255);
		i++;
	}

	return buf;
}