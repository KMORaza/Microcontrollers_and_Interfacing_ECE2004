// Embedded C program to ON exhaust fan whenever DIP switch is pressed.
#include <LPC17xx.h>
// Function to initialize GPIO pins for DIP switch and exhaust fan control
void initializeGPIO() {
    // Configure P2.26 as GPIO for the DIP switch
    LPC_PINCON->PINSEL4 &= ~(3 << 20);  // Clear bits 20 and 21
    LPC_GPIO2->FIODIR &= ~(1 << 26);     // P2.26 as input for DIP switch
    // Configure P2.27 as GPIO for the exhaust fan control
    LPC_PINCON->PINSEL4 &= ~(3 << 22);  // Clear bits 22 and 23
    LPC_GPIO2->FIODIR |= (1 << 27);      // P2.27 as output for exhaust fan control
}
// Function to check if the DIP switch is pressed
int isDIPSwitchPressed() {
    return !(LPC_GPIO2->FIOPIN & (1 << 26));
}
// Function to control the exhaust fan based on DIP switch state
void controlExhaustFan() {
    while (1) {
        if (isDIPSwitchPressed()) {
            // Turn ON the exhaust fan
            LPC_GPIO2->FIOPIN |= (1 << 27);
        } else {
            // Turn OFF the exhaust fan
            LPC_GPIO2->FIOPIN &= ~(1 << 27);
        }
    }
}
int main() {
    // Initialize GPIO for DIP switch and exhaust fan control
    initializeGPIO();
    // Control the exhaust fan based on DIP switch state
    controlExhaustFan();
    return 0;
}
