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
; User Code
    LDR   R8, =0x10000000   ; Load the memory address 0x10000000 into register R8
    LDR   R1, =0x00080200   ; Load the value 0x00080200 into register R1
    ORR   R2, R2, R1        ; Set the 19th and 9th bits, without disturbing the remaining bits
    LDR   R3, =0xFFBFFF7F   ; Load a value with the 22nd and 7th bits reset
    AND   R2, R2, R3        ; Reset the 22nd and 7th bits, without disturbing the remaining bits
    STR   R2, [R8], #1      ; Store the modified value in memory at the address pointed by R8
    END
