		rseg CODE:CODE(2)
		THUMB
      
; ------------------------------------------------------------------------------------------
; uint32_t isqrt(uint32_t x)
; ------------------------------------------------------------------------------------------

		EXPORT  isqrt
isqrt

	; The one parameter (x) is passed to this function in R0.
	; The function should return the result in R0

	; Registers R0 through R3 may be modified without 
	; preserving their original content. However, the
	; value of all other registers must be preserved!

	        LDR R1,=0 ;R1<-Y=0
                LDR R2,=0x40000000 ;R2<-M=Ox...
            top:  
                CMP R2,#0
                BEQ done
                ORR R3,R1,R2 ;R3<-b = Y|M
                LSR R1,R1,#1
                CMP R3,R0
                ITT LS
                SUBLS R0,R0,R3
                ORRLS R1,R1,R2
                LSR R2,R2,#2
                B top
           done: 
                MOV R0,R1
                

		BX	LR	; return

        	END
