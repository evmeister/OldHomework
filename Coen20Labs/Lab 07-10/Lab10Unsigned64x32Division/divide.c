#include <stdint.h>

#define LSW(x)	((uint32_t *) &(x))[0]	/* Least-significant 32 bits of 64-bit double word */
#define MSW(x)	((uint32_t *) &(x))[1]	/*  Most-significant 32 bits of 64-bit double word */

// Shift and subtract algorithm for division

uint32_t UDivide64x32(uint64_t dividend64, uint32_t divisor32)
	{
	int k, cout ;

	for (k = 0; k < 32; k++)
		{
		// These two lines are a 64-bit left shift with carry out
		cout = MSW(dividend64) >> 31 ;
		dividend64 = dividend64 << 1 ;

		if (cout == 1 || MSW(dividend64) >= divisor32)
			{
			MSW(dividend64) = MSW(dividend64) - divisor32 ;
			LSW(dividend64) = LSW(dividend64) + 1 ;
			}
		}

	// LSW(dividend64) = Quotient
	// MSW(dividend64) = Rmeainder

	return LSW(dividend64) ; 
	}

