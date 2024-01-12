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
; User Code
    LDR   R2, =0x10002000   ; Load the destination address 0x10002000 into register R2
    LDR   R3, =0x10000000   ; Load the source address 0x10000000 into register R3
    MOV   R1, #0x0A         ; Set the loop counter to 10
Loop
    LDRB  R0, [R3], #1      ; Load a byte from the source address and increment the source address
    STRB  R0, [R2], #1      ; Store the byte to the destination address and increment the destination address
    SUBS  R1, #1            ; Decrement the loop counter
    BNE   Loop              ; Branch back to Loop if the loop counter is not zero
    END
