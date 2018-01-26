		rseg CODE:CODE(2)
		THUMB
      
; ------------------------------------------------------------------------------------------
; int32_t iexp(int32_t x, uint32_t n)
; ------------------------------------------------------------------------------------------

		EXPORT  iexp
iexp

	; The first parameter (x) is passed to this function in R0.
	; The second parameter (n) is passed to this function in R1.
	; The function should return the result in R0.

	; Registers R0 through R3 may be modified without 
	; preserving their original content. However, the
	; value of all other registers must be preserved!

	        ;R0<- X
                ;R1<- N
                PUSH {R4}
                LDR R2,=1 ;R2<- Y=1
                MOV R3,R0  ;R3<- P=X
            top:
                AND R4,R1,#1
                CMP R4,#0
                IT NE
                MULNE R2,R3,R2
                LSR R1,R1,#1
                CMP R1,#0
                BEQ break
                MUL R3,R3,R3
                B top
          break:
                MOV R0,R2
                POP {R4}

		BX	LR		; return

		END
