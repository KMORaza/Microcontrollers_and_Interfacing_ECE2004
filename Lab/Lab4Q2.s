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
    LDR   R2, =0x10002000   ; Load the destination address 0x10002000 into register R2
    LDR   R3, =0x10000000   ; Load the source address 0x10000000 into register R3
    MOV   R1, #10            ; Set the loop counter to 10
    MOV   R5, #0             ; Initialize R5 for summation
LOOP
    LDRB  R0, [R3], #1      ; Load a byte from the source address and increment the source address
    ADD   R5, R5, R0         ; Add the loaded byte to the running sum in R5
    SUBS  R1, R1, #1         ; Decrement the loop counter
    BNE   LOOP               ; Branch back to LOOP if the loop counter is not zero
    STRH  R5, [R2], #2       ; Store the 16-bit sum in memory at the address pointed by R2 and increment the address
STOP
    B	  STOP               ; Infinite loop to stop the program
    END
