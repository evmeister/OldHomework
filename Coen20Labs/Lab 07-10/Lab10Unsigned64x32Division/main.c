#include <stdio.h>
#include <stdint.h>
#include <hw_types.h>
#include <display96x16x1.h>
#include <pushbutton.h>

extern uint32_t UDivide64x32(uint64_t dividend64, uint32_t divisor32) ;
extern void uint64ToAscii(uint64_t, uint32_t, char []) ;

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

void main(void)
	{
	static struct { uint64_t dividend; uint32_t divisor ; } testcase[] =
 		{
		{100,3},{200,3},{300,4},{0x400000000ULL,0x400}
       		} ;
	int k ;

	Display96x16x1Init(false) ;
	for (k = 0;; k = (k + 1) % ENTRIES(testcase))
		{
		char text[20], temp1[20] ;
		uint32_t result ;

		Display96x16x1Clear() ;

		result = UDivide64x32(testcase[k].dividend, testcase[k].divisor) ;

		uint64ToAscii(testcase[k].dividend, 10, temp1) ;
                sprintf(text, "%s/%lu", temp1, testcase[k].divisor) ;
 		Display96x16x1StringDraw(text, 0, 0);
       
		sprintf(text, "= %lu", result) ;
		Display96x16x1StringDraw(text, 0, 1);

		Wait4PushButton() ;
		}
	}
