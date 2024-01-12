;; Write an ALP to reset D12 of R0 without disturbing remaining bits.
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
            ; Reset (clear) D12 bit without disturbing other bits
            BIC R0, R0, #0x00001000  ; Clear bit 12 (D12)
            ; End of the program
            END
