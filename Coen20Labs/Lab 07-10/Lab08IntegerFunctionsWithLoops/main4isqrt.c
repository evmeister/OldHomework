#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <hw_types.h>
#include <display96x16x1.h>
#include <pushbutton.h>

extern uint32_t isqrt(uint32_t) ;

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

void main(void)
	{ 
	static struct { uint32_t squared ; } testcase[] =
		{
		{0*0},{1*1},{2*2},{1000*1000},{32767*32767}
		} ;
	int k ;

	Display96x16x1Init(false) ;
	for (k = 0;; k = (k + 1) % ENTRIES(testcase))
		{
		char text[20] ;
		uint32_t result ;

		Display96x16x1Clear() ;

		result = isqrt(testcase[k].squared) ;

		sprintf(text, "sqrt(%u)", testcase[k].squared) ;
 		Display96x16x1StringDraw(text, 0, 0);

		sprintf(text, "= %u", result) ;
		Display96x16x1StringDraw(text, 0, 1);

		Wait4PushButton() ;
		}
	}
