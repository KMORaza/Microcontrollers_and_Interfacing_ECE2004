;; Write an assembly language code to multiply the contents of R0 and R1 and store it in memory location 0x10000000.

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
; User Code
	LDR   R2, =0x10000000   ; Load the memory address 0x10000000 into register R2
    MOV   R0, #123          ; Move the value 123 into register R0
    MOV   R1, #0x2C         ; Move the value 0x2C into register R1
    MUL   R3, R0, R1        ; Multiply the contents of R0 and R1, store result in R3
    STR   R3, [R2], #1      ; Store the result in memory at the address pointed by R2, and increment the address
    END
