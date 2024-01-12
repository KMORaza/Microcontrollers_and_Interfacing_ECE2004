;; Write an ALP for Automated Light system.
;;  1. When person is present in room then LED light must be ON.
;;  2. When no person is present in room then LED light must be OFF.
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
            ; Assuming presence sensor reading logic and LED control logic here
            ; Load the presence value into a register (replace with actual reading logic)
            LDR R0, =1  ; Example value, replace with actual reading
            ; Compare the presence value with 0
            CMP R0, #0
            ; If Person is present, turn on the LED Light
            BEQ LEDLightON
            ; If no person is present, turn off the LED Light
LEDLightOFF MOV R1, #0
            STR R1, [GPIO2, #0]  ; Assuming LED is connected to GPIO pin P2.0
            B End
LEDLightON  MOV R1, #1
            STR R1, [GPIO2, #0]  ; Assuming LED is connected to GPIO pin P2.0
End         B End
