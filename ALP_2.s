;; Write an assembly language program to copy FFAABBCCH data to R0, R1, R2, R3, R4, R5 registers 
            PRESERVE8
            THUMB
            AREA    RESET, DATA, READONLY
            EXPORT  __Vectors
__Vectors
            DCD  0x20001000     ; stack pointer value when stack is empty
            DCD  Reset_Handler  ; reset vector
            ALIGN
SRAM_BASE EQU 0x04000000
            AREA    MYCODE, CODE, READONLY
            ENTRY
          EXPORT Reset_Handler
Reset_Handler
;user code starts from next line
            ; Load data 'FFAABBCCH' to register R0
            LDR R0, =0xFFAABBCC
            LDR R0, [R0]
            ; Load data 'FFAABBCCH' to register R1
            LDR R1, =0xFFAABBCC
            LDR R1, [R1]
            ; Load data 'FFAABBCCH' to register R2
            LDR R2, =0xFFAABBCC
            LDR R2, [R2]
            ; Load data 'FFAABBCCH' to register R3
            LDR R3, =0xFFAABBCC
            LDR R3, [R3]
            ; Load data 'FFAABBCCH' to register R4
            LDR R4, =0xFFAABBCC
            LDR R4, [R4]
            ; Load data 'FFAABBCCH' to register R5
            LDR R5, =0xFFAABBCC
            LDR R5, [R5]
            ; End of the program
            END
