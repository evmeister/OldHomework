#include <stdint.h>

//This function computes and returns the absolute value of its argument

uint32_t absval(int32_t x)
	{
	uint32_t signext ;

	signext = (x >= 0) ? 0 : -1 ;	// You can do this with an ASR instruction

	return (x + signext) ^ signext ;
	}
