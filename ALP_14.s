;; Write an ALP to set 19th bit and 9th bit of R2 without disturbing the remaining bits and store the value in FF00FF11H memory location.
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
            ; Load the initial value from memory location 'FF00FF11H' to register R2
            LDR R2, =0xFF00FF11
            ; Set the 19th bit (bit 18) without disturbing the remaining bits
            ORR R2, R2, (1 << 18)
            ; Set the 9th bit (bit 8) without disturbing the remaining bits
            ORR R2, R2, (1 << 8)
            ; Store the result in memory location 'FF00FF11H'
            STR R2, =0xFF00FF11
            ; End of the program
            END
