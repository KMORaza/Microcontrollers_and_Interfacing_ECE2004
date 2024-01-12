;; Write an assembly language program to copy data present in FFH to R0, R1, R3, R4, R5 registers. 
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
            ; Load data from address 0xFF to register R0
            LDR R0, =0xFF
            LDR R0, [R0]
            ; Load data from address 0xFF to register R1
            LDR R1, =0xFF
            LDR R1, [R1]
            ; Load data from address 0xFF to register R3
            LDR R3, =0xFF
            LDR R3, [R3]
            ; Load data from address 0xFF to register R4
            LDR R4, =0xFF
            LDR R4, [R4]
            ; Load data from address 0xFF to register R5
            LDR R5, =0xFF
            LDR R5, [R5]
            ; End of the program
            END
