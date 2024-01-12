;; Write an embedded C program to operate car parking barrier with stepper motor and IR sensor and to operate exhaust fan with DC motor and digital PIR sensor. 
;; Assume stepper motor is connected to P2.3 to P2.0 (3rd to 0th pole), DC exhaust is connected to P2.21(-ve), P2.22(+ve), IR sensor is connected to P2.18 and digital PIR sensor is connected to P2.27
#include <LPC17xx.h>
// Function to initialize GPIO pins
void initializeGPIO() {
    // Configure GPIO for stepper motor (P2.0 to P2.3)
    LPC_PINCON->PINSEL4 &= ~(0xFF);  // P2.0 to P2.3 as GPIO
    LPC_GPIO2->FIODIR |= 0x0F;       // P2.0 to P2.3 as output
    // Configure GPIO for DC exhaust fan (P2.21 and P2.22)
    LPC_PINCON->PINSEL4 &= ~(0xC00000);  // P2.21 and P2.22 as GPIO
    LPC_GPIO2->FIODIR |= (1 << 21) | (1 << 22);  // P2.21 and P2.22 as output
    // Configure GPIO for IR sensor (P2.18)
    LPC_PINCON->PINSEL4 &= ~(3 << 4);  // P2.18 as GPIO
    LPC_GPIO2->FIODIR &= ~(1 << 18);   // P2.18 as input
    // Configure GPIO for digital PIR sensor (P2.27)
    LPC_PINCON->PINSEL4 &= ~(3 << 22);  // P2.27 as GPIO
    LPC_GPIO2->FIODIR &= ~(1 << 27);    // P2.27 as input
}
// Function to operate car parking barrier
void operateBarrier() {
    // Check if the IR sensor is activated
    if (LPC_GPIO2->FIOPIN & (1 << 18)) {
        // Barrier open (stepper motor clockwise rotation)
        LPC_GPIO2->FIOPIN = (0x01);  // Assume 0x01 corresponds to clockwise rotation
    } else {
        // Barrier closed (stepper motor counter-clockwise rotation)
        LPC_GPIO2->FIOPIN = (0x0A);  // Assume 0x0A corresponds to counter-clockwise rotation
    }
}
// Function to operate exhaust fan
void operateExhaustFan() {
    // Check if the digital PIR sensor is activated
    if (LPC_GPIO2->FIOPIN & (1 << 27)) {
        // Exhaust fan ON (DC motor ON)
        LPC_GPIO2->FIOPIN |= (1 << 21);  // P2.21 as HIGH (DC motor ON)
    } else {
        // Exhaust fan OFF (DC motor OFF)
        LPC_GPIO2->FIOPIN &= ~(1 << 21);  // P2.21 as LOW (DC motor OFF)
    }
}
int main() {
    initializeGPIO();  // Initialize GPIO pins
    while (1) {
        operateBarrier();      // Operate car parking barrier based on IR sensor
        operateExhaustFan();   // Operate exhaust fan based on digital PIR sensor
    }
    return 0;
}
