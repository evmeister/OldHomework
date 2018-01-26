#include <stdint.h>

// Integer exponentiation - adapted from Warren, "Hacker's Delight", Addison Wesley, 2003.

int32_t iexp(int32_t x, int32_t n)
	{
	int32_t p, y ;

	y = 1 ;
	p = x ;
	while (1)
		{
		if ((n & 1) != 0) y = p * y ;
		n = n >> 1 ;
		if (n == 0) break ;
		p = p * p ;
		}
	return y ;
	}
