// Write an embedded C program to rotate 4-pole stepper motor in half step clockwise whenever dip switch is pressed. Assume Stepper motor pins are connected to P2.3 to P2.0 (4th to 1st pole) and dip switch is connected to P2.26.
#include <LPC17xx.h>
// Function to initialize GPIO pins
void initializeGPIO() {
    // Configure P2.0 to P2.3 as GPIO for stepper motor
    LPC_PINCON->PINSEL4 &= ~(0xFF);  // Clear bits 0-7
    LPC_GPIO2->FIODIR |= 0x0F;        // P2.0 to P2.3 as output
    // Configure P2.26 as GPIO for dip switch
    LPC_PINCON->PINSEL4 &= ~(3 << 20);  // Clear bits 20 and 21
    LPC_GPIO2->FIODIR &= ~(1 << 26);     // P2.26 as input
}
// Function to check if the dip switch is pressed
int isDipSwitchPressed() {
    return !(LPC_GPIO2->FIOPIN & (1 << 26));
}
// Function to rotate the stepper motor in half-step mode
void rotateStepperMotorHalfStep() {
    // Define the half-step sequence
    uint8_t halfStepSequence[] = {0x09, 0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01};
    while (1) {
        // Check if the dip switch is pressed
        if (isDipSwitchPressed()) {
            for (int step = 0; step < 8; ++step) {
                // Apply the current sequence value to the motor pins
                LPC_GPIO2->FIOPIN = halfStepSequence[step];
                // Add a delay to control the motor speed (adjust as needed)
                for (volatile int i = 0; i < 50000; ++i);
            }
        }
    }
}
int main() {
    // Initialize GPIO for stepper motor and dip switch
    initializeGPIO();
    // Rotate the stepper motor in half-step clockwise when the dip switch is pressed
    rotateStepperMotorHalfStep();
    return 0;
}
