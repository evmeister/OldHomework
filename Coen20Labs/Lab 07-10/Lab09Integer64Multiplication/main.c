#include <stdio.h>
#include <stdint.h>
#include <hw_types.h>
#include <display96x16x1.h>
#include <pushbutton.h>

extern int64_t IntegerProduct64x64(int64_t, int64_t) ;
extern void int64ToAscii(uint64_t, uint32_t, char []) ;

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

void main(void)
	{
	static struct { int64_t multiplier, multiplicand ; } testcase[] =
 		{
		  {0,1},{1,0},{2,2},{-3,3},{3,-100000}
       		} ;
	int k ;

	Display96x16x1Init(false) ;
	for (k = 0;; k = (k + 1) % ENTRIES(testcase))
		{
		char text[20], temp1[20], temp2[20] ;
		int64_t result ;

		Display96x16x1Clear() ;

		result = IntegerProduct64x64(testcase[k].multiplier, testcase[k].multiplicand) ;
 
		int64ToAscii(testcase[k].multiplier, 10, temp1) ;
		int64ToAscii(testcase[k].multiplicand, 10, temp2) ;
		sprintf(text, "%s * %s", temp1, temp2) ;
		Display96x16x1StringDraw(text, 0, 0);
       
		int64ToAscii(result, 10, temp1) ;
		sprintf(text, "= %s", temp1) ;
		Display96x16x1StringDraw(text, 0, 1);

		Wait4PushButton() ;
		}
	}
