		rseg CODE:CODE(2)
		THUMB
      
; ------------------------------------------------------------------------------------------
; uint32_t absval(int32_t x)
; ------------------------------------------------------------------------------------------

		EXPORT  absval
absval

	; The first parameter (x) is passed to this function in R0.
	; The function should return the result in R0.

	; Registers R0 through R3 may be modified without 
	; preserving their original content. However, the
	; value of all other registers must be preserved!

	; Insert your code here ...
                CMP R0,#0
                ITE GE
                LDRGE R1,=0
                LDRLT R1,=-1
                ADD R0,R0,R1
                EOR R0,R0,R1

		BX	LR		; return

		END
