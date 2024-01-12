;; Write ALP to perform 64 bit addition. Assume that first number lower 32 bit is present in 10002000H memory location and higher 32 bit first number in 10003000H memory location. 
;; Assume that lower 32 bit is present in 10004000H memory location and higher 32 bit is present in 10005000H memory location. 
;; Store the result of 32 bit in 10006000H memory location and higher 32 bit in 10007000H location.
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
            ; Load the lower 32 bits of the first number to register R0
            LDR R0, =0x10002000
            ; Load the higher 32 bits of the first number to register R1
            LDR R1, =0x10003000
            ; Load the lower 32 bits of the second number to register R2
            LDR R2, =0x10004000
            ; Load the higher 32 bits of the second number to register R3
            LDR R3, =0x10005000
            ; Load the contents of memory locations '10002000H' and '10003000H' to registers R4 and R5
            LDR R4, [R0]
            LDR R5, [R1]
            ; Load the contents of memory locations '10004000H' and '10005000H' to registers R6 and R7
            LDR R6, [R2]
            LDR R7, [R3]
            ; Add the lower 32 bits
            ADD R8, R4, R6
            ; Add the higher 32 bits along with any carry from the lower 32-bit addition
            ADC R9, R5, R7
            ; Store the lower 32 bits of the result in memory location '10006000H'
            STR R8, =0x10006000
            ; Store the higher 32 bits of the result in memory location '10007000H'
            STR R9, =0x10007000
            ; End of the program
            END
