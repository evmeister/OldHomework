#include <stdint.h>

#define Lower32Bits(a)	((uint32_t *) &a)[0]
#define Upper32Bits(a)	((uint32_t *) &a)[1]

// Simulates normal 32-bit unsigned multiplication, producing a 64-bit product.
uint64_t UnsignedProduct32x32(uint32_t a, uint32_t b)
	{
	return ((uint64_t) a) * ((uint64_t) b) ;
	}

// The only difference in signed vs. unsigned integer multiplication is
// in the most-significant half of the double-width product. Since we always
// discard those bits, the one routine below will work for either data type.

int64_t IntegerProduct64x64(int64_t a, int64_t b)
	{
	int64_t product, loXlo, loXhi, hiXlo ; ;

	// Compute three of four cross-products

	loXlo = UnsignedProduct32x32(Lower32Bits(a), Lower32Bits(b)) ;
	hiXlo = UnsignedProduct32x32(Lower32Bits(a), Upper32Bits(b)) ;
	loXhi = UnsignedProduct32x32(Upper32Bits(a), Lower32Bits(b)) ;

	// Assemble the lower 64 bits of the 128-bit product

	product = loXlo ;
	Upper32Bits(product) += Lower32Bits(loXhi) ;
	Upper32Bits(product) += Lower32Bits(hiXlo) ;

	return product ;
	}

