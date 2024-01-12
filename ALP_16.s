;; Write an ALP to add two numbers present in memory location of F100F200H and F200F100H and store result in FF00F210H memory location.
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
            ; Load data from memory location 'F100F200H' to register R0
            LDR R0, =0xF100F200
            ; Load data from memory location 'F200F100H' to register R1
            LDR R1, =0xF200F100
            ; Add data in R0 and R1 and store result in 'FF00F210H'
            STR R2, =0xFF00F210
            ADD R2, R0, R1
            ; End of the program
            END
