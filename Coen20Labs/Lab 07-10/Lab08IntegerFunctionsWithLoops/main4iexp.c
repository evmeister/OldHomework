#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <hw_types.h>
#include <display96x16x1.h>
#include <pushbutton.h>

extern int32_t iexp(int32_t x, uint32_t n) ;

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

void main(void)
	{ 
	static struct { int32_t base; uint32_t exponent; } testcase[] =
 		{
		{0,0},{2,0},{2,1},{-2,1},{2,3},{-2,3}
		} ;
	int k ;

	Display96x16x1Init(false) ;
	for (k = 0;; k = (k + 1) % ENTRIES(testcase))
		{
		char text[20] ;
		int32_t result ;

		Display96x16x1Clear() ;

		result = iexp(testcase[k].base, testcase[k].exponent) ;

		sprintf(text, "iexp(%d,%u)", testcase[k].base, testcase[k].exponent) ;
		Display96x16x1StringDraw(text, 0, 0);

		sprintf(text, "= %d", result) ;
		Display96x16x1StringDraw(text, 0, 1);

		Wait4PushButton() ;
		}
	}
