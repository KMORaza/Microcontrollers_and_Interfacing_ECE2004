;; Write an assembly language program to copy content present in FFAABBCCH memory location to AABBCCDDH memory location. 
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
            ; Load data from 'FFAABBCCH' to register R0
            LDR R0, =0xFFAABBCC
            LDR R0, [R0]
            ; Store data from register R0 to 'AABBCCDDH'
            STR R0, =0xAABBCCDD
            ; End of the program
            END
