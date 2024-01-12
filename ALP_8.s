;; Write an ALP to set D3 bit of R0 register without disturbing remaining bits.
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
            ; Load the current value of R0
            LDR R0, =0x12345678  ; Replace with your actual value
            ; Set D3 bit without disturbing other bits
            ORR R0, R0, #0x08    ; Set bit 3 (D3)
            ; End of the program
            END
