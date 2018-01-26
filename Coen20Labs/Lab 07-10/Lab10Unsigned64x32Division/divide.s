        rseg CODE:CODE(2)
        THUMB

; ------------------------------------------------------------------------------------------
; uint32_t UDivide64x32(uint64_t dividend64, uint32_t divisor32)
; ------------------------------------------------------------------------------------------

		EXPORT  UDivide64x32
UDivide64x32

	; The two parameters are passed to this function as follows:
	;
	; dividend64 is in register pair R1.R0
	; divisor32 is in register R2
	;
	; The quotient must be returned in register R0

                PUSH{R4}
                LDR R3,=0
           for: LSR R4,R1,#31
                LSL R1,R1,#1
                ORR R1,R1,R0,LSR#31
                LSL R0,R0,#1
                CMP R4,#1
                BEQ do
                CMP R1,R2
                BLO end
            do: SUB R1,R1,R2
                ADD R0,R0,#1
           end: ADD R3,R3,#1
                CMP R3,#32
                BLT for
                POP {R4}
		BX	LR			; Return to calling program.

       		END
