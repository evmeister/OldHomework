#include <stdint.h>

static int _uint64ToAscii(uint64_t number, uint32_t base, char *text, int index)
	{
	if (number >= base) index = _uint64ToAscii(number / base, base, text, index) ;
	text[index++] = '0' + (number % base) ;
	text[index] = '\0' ;
	return index ;
	}

void uint64ToAscii(uint64_t number, uint32_t base, char *text)
	{
	_uint64ToAscii(number, base, text, 0) ;
	}

void int64ToAscii(int64_t number, uint32_t base, char *text)
	{
	if (number < 0)
		{
		*text++ = '-' ;
		number = -number ;
		}

	uint64ToAscii(number, base, text) ;
	}




