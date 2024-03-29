/* Write an embedded C code for Automated Gate.
   1. When any car is in front of gate then Gate will OPEN. 
   2. When NO car is in front of gate then gate will CLOSED.
*/
#include <LPC17xx.h>
// Function to initialize GPIO pins
void initializeGPIO() {
    // Configure GPIO for car sensor (Assume connected to P2.0)
    LPC_PINCON->PINSEL4 &= ~(3 << 0);   // P2.0 as GPIO
    LPC_GPIO2->FIODIR &= ~(1 << 0);     // P2.0 as input
    // Configure GPIO for gate control (Assume gate connected to P2.1)
    LPC_PINCON->PINSEL4 &= ~(3 << 2);   // P2.1 as GPIO
    LPC_GPIO2->FIODIR |= (1 << 1);      // P2.1 as output
}
// Function to control the gate based on car presence
void controlGate() {
    if (LPC_GPIO2->FIOPIN & (1 << 0)) {
        // Car is present, open the gate
        LPC_GPIO2->FIOPIN |= (1 << 1);  // P2.1 as HIGH (gate open)
    } else {
        // No car, close the gate
        LPC_GPIO2->FIOPIN &= ~(1 << 1);  // P2.1 as LOW (gate closed)
    }
}
int main() {
    initializeGPIO();  // Initialize GPIO pins
    while (1) {
        controlGate();  // Control the gate based on car presence
    }
    return 0;
}
