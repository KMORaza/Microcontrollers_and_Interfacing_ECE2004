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
    LDR   R0, =0x10000000   ; Load the memory address 0x10000000 into register R0
    LDR   R7, =0x10000100   ; Load the memory address 0x10000100 into register R7
    LDR   R8, =0x10000200   ; Load the memory address 0x10000200 into register R8
    MOV   R1, #23           ; Move the value 23 into register R1
    LDR   R2, [R0], #1      ; Load a 32-bit number from the memory at R0 into R2 and increment the address
    UMULL R3, R4, R1, R2    ; Unsigned multiply R1 and R2, store the 64-bit result in R3 and R4
    STR   R3, [R7], #1      ; Store the high 32 bits of the result in memory at the address pointed by R7
    STR   R4, [R8], #1      ; Store the low 32 bits of the result in memory at the address pointed by R8
    END
