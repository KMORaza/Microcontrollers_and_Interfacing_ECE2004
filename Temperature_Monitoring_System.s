;; Write an assembly language program to temperature monitoring system for food industry. 
;; If temperature is greater than 40 Degree C fan and AC will on, if temperature is between 270 to 40 Degree C only fan will be ON if temperature is less than 27 both fan and AC will be OFF. 
;; Assume that temperature reading is available in 10001000H memory location when FFH is sent to 10002000H then fan will be ON and OFF the remaining values. 
;;When FFH is sent to 10003000H then AC will be ON and OFF for remaining values. 
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
            ; Load temperature reading from memory location '10001000H' to register R0
            LDR R0, =0x10001000
            ; Check if temperature is greater than 40 Degree C
            CMP R0, #40
            BGT FanAndACOn
            ; Check if temperature is between 27 to 40 Degree C
            CMP R0, #27
            BLT FanOn
            B FanAndACOff
FanAndACOn:
            ; Turn ON Fan and AC
            STRB #0xFF, =0x10002000  ; Fan ON
            STRB #0xFF, =0x10003000  ; AC ON
            B End
FanOn:
            ; Turn ON Fan only
            STRB #0xFF, =0x10002000  ; Fan ON
            STRB #0x00, =0x10003000  ; AC OFF
            B End
FanAndACOff:
            ; Turn OFF Fan and AC
            STRB #0x00, =0x10002000  ; Fan OFF
            STRB #0x00, =0x10003000  ; AC OFF
End:
            ; End of the program
            END
