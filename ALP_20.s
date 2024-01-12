;; Write an ALP for Temperature Monitoring Unit of Food Industry.
;;   1. If Temp>200 C then Cooler must be ON
;;   2. If Temp<200 C then Cooler must be OFF
;; -------------------------------------------------------------
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
            ; Assuming temperature sensor reading logic and cooler control logic here
            ; Load the temperature value into a register (replace with actual reading logic)
            LDR R0, =210  ; Example value, replace with actual reading
            ; Compare the temperature with 200 C
            CMP R0, #200
            ; If Temp > 200 C, turn on the cooler
            BGT CoolerON
            ; If Temp <= 200 C, turn off the cooler
CoolerOFF   MOV R1, #0
            STR R1, [GPIO2, #0]  ; Assuming Cooler is connected to GPIO pin P2.0
            B End
CoolerON    MOV R1, #1
            STR R1, [GPIO2, #0]  ; Assuming Cooler is connected to GPIO pin P2.0
End         B End
