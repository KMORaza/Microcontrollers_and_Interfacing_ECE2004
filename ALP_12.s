;; Write an assembly language code to evaluate X= ([2^10 (Y+Z^2+Y^4)]/32+55 )  by reading Y and Z contents from the memory locations 0X00002000 and 0X00003000 and write the result X into 0X00004000 memory location. 
;; Assume the variables X, Y, and Z corresponding to R0, R1, and R2 registers in assembly language. Use shift operation.
            PRESERVE8
            THUMB
            AREA    RESET, DATA, READONLY
            EXPORT  __Vectors
__Vectors
            DCD  0x20001000     ; stack pointer value when stack is empty
            DCD  Reset_Handler  ; reset vector
            ALIGN
SRAM_BASE EQU 0x04000000
            AREA    MYCODE, CODE, READWRITE
            ENTRY
          EXPORT Reset_Handler
Reset_Handler
;user code starts from next line
            ; Load Y and Z from memory locations '0x00002000' and '0x00003000' to registers R1 and R2
            LDR R1, =0x00002000  ; Load address of Y
            LDR R2, [R1]         ; Load Y to R2
            LDR R1, =0x00003000  ; Load address of Z
            LDR R3, [R1]         ; Load Z to R3
            ; Calculate Y + Z^2 + Y^4
            MOV R4, #2           ; Power of 2 for Z^2
            LSL R5, R3, R4       ; Z^2
            MOV R4, #4           ; Power of 4 for Y^4
            LSL R6, R2, R4       ; Y^4
            ADD R7, R2, R5       ; Y + Z^2
            ADD R7, R7, R6       ; Y + Z^2 + Y^4
            ; Calculate 2^10 * (Y + Z^2 + Y^4)
            MOV R4, #10
            LSL R7, R7, R4       ; 2^10 * (Y + Z^2 + Y^4)
            ; Calculate (2^10 * (Y + Z^2 + Y^4))/32
            MOV R4, #5
            LSR R7, R7, R4       ; (2^10 * (Y + Z^2 + Y^4))/32
            ; Calculate (2^10 * (Y + Z^2 + Y^4))/32 + 55
            MOV R4, #55
            ADD R7, R7, R4       ; (2^10 * (Y + Z^2 + Y^4))/32 + 55
            ; Store the result X in memory location '0x00004000'
            LDR R1, =0x00004000  ; Load address of X
            STR R7, [R1]         ; Store the result in X
            ; End of the program
            END
