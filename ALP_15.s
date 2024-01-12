;; Write an ALP to add and subtract two data present F00F1122H and EF00FF22H memory location and store result in R10 and R11 registers respectively.
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
            ; Load data from memory location 'F00F1122H' to register R0
            LDR R0, =0xF00F1122
            ; Load data from memory location 'EF00FF22H' to register R1
            LDR R1, =0xEF00FF22
            ; Add data in R0 and R1 and store result in R10
            ADD R10, R0, R1
            ; Subtract data in R1 from R0 and store result in R11
            SUB R11, R0, R1
            ; End of the program
            END
