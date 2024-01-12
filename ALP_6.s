;; Write ALP to add contents present in 10002000H and 10003000H memory locations and store result in 10004000H memory location.
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
            ; Load data from memory location '10002000H' to register R0
            LDR R0, =0x10002000
            ; Load data from memory location '10003000H' to register R1
            LDR R1, =0x10003000
            ; Load the contents of memory locations '10002000H' and '10003000H' to registers R2 and R3
            LDR R2, [R0]
            LDR R3, [R1]
            ; Add the contents of R2 and R3
            ADD R4, R2, R3
            ; Store the result in memory location '10004000H'
            STR R4, =0x10004000
            END
