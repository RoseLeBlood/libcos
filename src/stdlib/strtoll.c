#include <stdlib.h>
#include <ctype.h>

long long int strtoll (const char* nptr, char** endptr, int base) {
	const char* _ptr = nptr;
	long long int result;
	int _char;
	long long int _cutoff;
	bool _neg = false;
	int any;
	int cutlim;

	if(base < 0 || base > 36) {
		if(endptr) *endptr = (char*)(uintptr_t)nptr;
		return 0;
	}
	do {
		_char = (unsigned char)*_ptr++;
	} while(isspace(_char));


	if(_char == '-') {
		_neg = true;
		_char = *_ptr++;
	}
	else if(_char == '+') {
		_char = *_ptr++;
	}

	if((base == 0 || base == 16) && _char == '0' && (*_ptr == 'x' || *_ptr == 'X')) {
		_char = _ptr[1];
		_ptr += 2;
		base = 16;
	}
	else if((base == 0 || base == 2) && _char == '0' && (*_ptr == 'b' || *_ptr == 'B')) {
		_char = _ptr[1];
		_ptr += 2;
		base = 2;
	}

	if(base == 0) base = _char == '0' ? 8 : 10;
	
	_cutoff = _neg ? -LLONG_MIN : LLONG_MAX;
	cutlim = (int)(_cutoff % base);
	_cutoff /= base;

	for(result = 0, any = 0;; _char = *_ptr++) {
		if(isdigit(_char)) _char -= '0';
		else if(isalpha(_char)) _char -= isupper(_char) ? 'A' - 10 : 'a' - 10;
		else break;

		if(_char >= base) break;

		if(any < 0 || result > _cutoff || (result == _cutoff && _char > cutlim))
			any = -1;
		else {
			any = 1;
			result *= base;
			result += _char;
		}
	}

	if(any < 0) result = _neg ? LLONG_MIN : LLONG_MAX;
	else if(_neg) result = -result;

	if(endptr != 0) *endptr = (char*)(uintptr_t)(any ? _ptr - 1 : nptr);

	return (long)(result);
}