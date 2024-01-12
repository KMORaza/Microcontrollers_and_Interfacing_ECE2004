;; Write an ALP for temperature monitoring system for food industry. If temp. of the room is greater than 30 degrees, then fans will be “ON”, otherwise fans will be “OFF”. 
;; Assume temperature of the room is available in 10002000h memory location. 
;; Assume that sending FFh value to 10004000h memory location will “ON” the DC fan and the remaining values, the DC fan will be “OFF’. 
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
            ; Load temperature reading from memory location '10002000H' to register R0
            LDR R0, =0x10002000
            LDRB R0, [R0]
            ; Check if temperature is greater than 30 degrees
            CMP R0, #30
            BLE FansOff  ; If less than or equal, turn OFF fans
            ; Temperature is greater than 30 degrees, turn ON fans
            ; Load the value at memory location '10004000H' to register R1
            LDR R1, =0x10004000
            LDRB R1, [R1]
            ; Check if the value is FFh to turn ON DC fan
            CMP R1, #0xFF
            BNE FansOff  ; If not FFh, turn OFF DC fan
            ; FFh received, turn ON DC fan
            ; Code to turn ON DC fan goes here
            B End
FansOff:
            ; Code to turn OFF fans goes here
End:
            ; End of the program
            END
