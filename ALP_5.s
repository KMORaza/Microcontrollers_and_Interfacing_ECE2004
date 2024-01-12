;; Write an ALP to add AAh and 77h contents and store the result in R8 register
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
            ; Load data from 'AAh' to register R0
            LDR R0, =0xAA
            ; Load data from '77h' to register R1
            LDR R1, =0x77
            ; Add the contents of R0 and R1
            ADD R8, R0, R1
            END
