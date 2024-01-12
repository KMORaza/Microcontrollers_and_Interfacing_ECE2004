;; Write an ALP to add two 64-bit data present in memory location FF00FF10H and FA00FA10H memory location and store result in FFBBFFBBH memory location.
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
            ; Load the next 32 bits of data from memory location 'FF00FF14H' to register R1
            LDR R1, =0xFF00FF14
            ; Load the third 32 bits of data from memory location 'FA00FA10H' to register R2
            LDR R2, =0xFA00FA10
            ; Load the last 32 bits of data from memory location 'FA00FA14H' to register R3
            LDR R3, =0xFA00FA14
            ; Add the first pair of 32 bits
            ADD R4, R0, R2
            ; Add the second pair of 32 bits with carry from the first addition
            ADC R5, R1, R3
            ; Store the result in memory location 'FFBBFFBBH'
            STR R4, =0xFFBBFFBB
            STR R5, =0xFFBBFFBF  ; Assuming 64-bit result, adjust as needed
            ; End of the program
            END
