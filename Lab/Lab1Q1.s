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
; 20BCD7138
; Write an assembly language code to copy content of memory location 0x10000100 to the memory location 0x10000200.
	LDR    R1, =0x10000100   ; Load the source address into register R1
	LDR    R2, =0x10000200   ; Load the destination address into register R2
    LDRB   R3, [R1]        ; Load a byte from the source address
    STRB   R3, [R2]        ; Store the byte to the destination address
	END
