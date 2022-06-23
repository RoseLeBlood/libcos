#include <stdlib.h>
#include <ctype.h>

static unsigned long _rand_value = 1;

double atof (const char* nptr) {
        return (strtod(nptr, NULL));
}

int atoi(const char* str) {
        int result = 0;
		bool neg = false;

        while (isspace(*str))
                str++;

        switch(*str) {
	        case '-':  neg = true; break;
		case '+': str++; break;
	}

        while (isdigit(*str))
                result = (result * 10) + (*(str++) - '0');
        return result;
}

long int atol(const char* str) {
        long int result = 0;
        bool neg = false;

        while (isspace(*str))
                str++;
        switch(*str) {
	        case '-':  neg = true; break;
		case '+': str++; break;
	}
        while (isdigit(*str))
                result = (result * 10) + (*(str++) - '0');
        return neg ? -result : result; 
}

long long int atoll(const char* str) {
        long long result = 0;
	bool neg = false;

        while(isspace(*str)) 
                str++;
	
        switch(*str) {
	        case '-':  neg = true; break;
		case '+': str++; break;
	}  
        while(isdigit(*str)) 
                result = (result * 10) + (*(str++) - '0');
        return neg ? -result : result;                         
}

double                          strtod  (const char* nptr, char** endptr);
float                           strtof          (const char* nptr, char** endptr);

long double strtold (const char* nptr, char** endptr) {
        return (long double)strtod(nptr, endptr);
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

int mblen(const char *s, size_t n)
{
      if (s == (const char *)NULL) return 0;
      if (n <= 0) return 0;
      return (*s != 0);
}
int mbtowc(wchar_t *pwc, register const char *s, size_t n)
{
	  if (s == (const char *)NULL) return 0;
	  if (n <= 0) return 0;
	  if (pwc) *pwc = *s;
	  return (*s != 0);
}
int wctomb  (char* s, wchar_t wchar)
{
	if (!s) return 0;               /* no state dependent codings */
  
          *s = wchar;
          return 1;
}
size_t mbstowcs(register wchar_t *pwcs, register const char *s, size_t n)
{
	  register int i = n;

	  while (--i >= 0) {
	          if (!(*pwcs++ = *s++))
	                  return n - i - 1;
	  }
	  return n - i;
}
size_t  wcstombs(register char *s, register const wchar_t *pwcs, size_t n)
{
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
int rand_m(uint32_t min, uint32_t max) {
        int random = rand() % (max-min) + min;
        return random;
}
