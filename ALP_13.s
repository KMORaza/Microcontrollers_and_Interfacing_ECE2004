;; Write an ALP to multiply R2 content with 35 using shift instructions and store result in R4 register
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
            ; Load content of R2 to R4 (initial value)
            MOV R4, R2
            ; Shift R4 left by 5 (2^5 = 32) to multiply by 32
            LSL R4, R4, #5
            ; Add R4 and the original value in R2 to get the result of 35 * R2
            ADD R4, R4, R2
            ; End of the program
            END
