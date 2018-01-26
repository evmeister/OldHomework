#include <stdio.h>
#include <stdint.h>
#include <hw_types.h>
#include <display96x16x1.h>
#include <pushbutton.h>

extern int32_t disc(int32_t, int32_t, int32_t) ;

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

void main(void)
	{ 
	static struct { int32_t a, b, c ; } testcase[] =
		{
		{1,1,1},{-1,2,3},{1,3,-2}
		} ;
	int k ;

	Display96x16x1Init(false) ;
	for (k = 0;; k = (k + 1) % ENTRIES(testcase))
		{
		char text[20] ;
		int32_t result ;

		Display96x16x1Clear() ;

		result = disc(testcase[k].a, testcase[k].b, testcase[k].c) ;

		sprintf(text, "disc(%d,%d,%d)", testcase[k].a, testcase[k].b, testcase[k].c) ;
		Display96x16x1StringDraw(text, 0, 0);

		sprintf(text, "= %d", result) ;
		Display96x16x1StringDraw(text, 0, 1);

		Wait4PushButton() ;
		}
	}
