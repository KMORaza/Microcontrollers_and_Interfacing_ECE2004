;;;;;;;;;;;;;;;Assembly code for transfer of data from one memory location to another;;;;;;;;;;;;;;;;;;;

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
;;;;;;;;;;User Code Starts from the next line;;;;;;;;;;;;
; 20BCD7138
; Write an assembly language code to add and subtract the contents of register 
;R0 with R1 and store it in register R3 and R4 respectively.

; User Code
    MOV  R0, #05       ; Move the value 05 into register R0
    MOV  R1, #08       ; Move the value 08 into register R1
    ADD  R3, R0, R1    ; Add the contents of R0 and R1, store result in R3
    SUB  R4, R0, R1    ; Subtract the contents of R1 from R0, store result in R4
    END

		
		