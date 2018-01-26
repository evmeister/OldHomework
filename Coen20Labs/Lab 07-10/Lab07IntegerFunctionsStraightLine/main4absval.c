#include <stdio.h>
#include <stdint.h>
#include <hw_types.h>
#include <display96x16x1.h>
#include <pushbutton.h>

extern uint32_t absval(int32_t) ;

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

void main(void)
	{ 
	static struct { int32_t arg ; } testcase[] =
		{
		{0},{+1000},{-1000},{0x7FFFFFFF},{0x80000001}
		} ;
	int k ;

	Display96x16x1Init(false) ;
	for (k = 0;; k = (k + 1) % ENTRIES(testcase))
		{
		char text[20] ;
		int32_t result ;

		Display96x16x1Clear() ;

		result = absval(testcase[k].arg) ;

		sprintf(text, "| %d |", testcase[k].arg) ;
		Display96x16x1StringDraw(text, 0, 0);

		sprintf(text, "= %d", result) ;
		Display96x16x1StringDraw(text, 0, 1);

		Wait4PushButton() ;
		}
	}
