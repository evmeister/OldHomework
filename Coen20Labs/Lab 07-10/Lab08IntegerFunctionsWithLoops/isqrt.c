#include <stdint.h>

// Integer square root - adapted from Warren, "Hacker's Delight", Addison Wesley, 2003.

uint32_t isqrt(uint32_t x)
	{
	uint32_t m, y, b ;

	y = 0 ;
	m = 0x40000000 ;
	while (m != 0)	// repeats 16 times
		{
		b = y | m ;
		y = y >> 1 ;
		if (b <= x)
			{
			x = x - b ;
			y = y | m ;
			}
		m = m >> 2 ;
		}
	return y ;
	}

