;; Write an ALP to add two 128-bit data present in memory location FF00FF10H and FA00FA10H memory location and store result in FFBBFFBBH memory location.
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
            ; Load the first 32 bits of data from memory location 'FF00FF10H' to register R0
            LDR R0, =0xFF00FF10
            LDR R1, =0xFF00FF14
            LDR R2, =0xFF00FF18
            LDR R3, =0xFF00FF1C
            ; Load the second 32 bits of data from memory location 'FA00FA10H' to register R4
            LDR R4, =0xFA00FA10
            LDR R5, =0xFA00FA14
            LDR R6, =0xFA00FA18
            LDR R7, =0xFA00FA1C
            ; Add the first pair of 32 bits
            ADD R8, R0, R4
            ADC R9, R1, R5
            ADC R10, R2, R6
            ADC R11, R3, R7
            ; Store the result in memory location 'FFBBFFBBH'
            STR R8, =0xFFBBFF10
            STR R9, =0xFFBBFF14
            STR R10, =0xFFBBFF18
            STR R11, =0xFFBBFF1C
            ; End of the program
            END
