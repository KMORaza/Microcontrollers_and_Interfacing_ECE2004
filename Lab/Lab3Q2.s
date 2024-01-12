;; Write an assembly language code to multiply R2 content with 35 using shift instructions and store the result in memory location 0x10000100.

;;; Directives
          	PRESERVE8
          	THUMB      
 
; Vector Table Mapped to Address 0 at Reset
; Linker requires __Vectors to be exported
 
          	AREA    RESET, DATA, READONLY
          	EXPORT  __Vectors
 
__Vectors
			DCD  0x20001000     ; stack pointer value when stack is empty
          	DCD  Reset_Handler  ; reset vector
 
          	ALIGN
 
; Linker requires Reset_Handler
SRAM_BASE EQU 0x04000000
          	AREA    MYCODE, CODE, READONLY
          	ENTRY
        	EXPORT Reset_Handler

Reset_Handler
; 20BCD7138
	LDR   R7, =0x10000100   ; Load the memory address 0x10000100 into register R7
    MOV   R2, #100          ; Move the value 100 into register R2
    LSL   R1, R2, #5        ; Left shift R2 by 5 (multiply by 32), store result in R1
    LSL   R3, R2, #1        ; Left shift R2 by 1 (multiply by 2), store result in R3
    ADD   R4, R1, R3        ; Add the results of the shifts, store result in R4
    ADD   R5, R4, R2        ; Add the original value of R2, store result in R5
    STR   R5, [R7], #1      ; Store the final result in memory at the address pointed by R7
    END
