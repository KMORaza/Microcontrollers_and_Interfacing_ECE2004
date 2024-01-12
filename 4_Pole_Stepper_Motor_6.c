// Write an embedded C program to rotate 4-pole stepper motor in half step clockwise for 10 times and half step anti-clockwise 20 times. Assume Stepper motor pins are connected to P2.3 to P2.0 (4th to 1st pole).
#include <LPC17xx.h>
// Function to initialize GPIO pins
void initializeGPIO() {
    // Configure P2.0 to P2.3 as GPIO for stepper motor
    LPC_PINCON->PINSEL4 &= ~(0xFF);  // Clear bits 0-7
    LPC_GPIO2->FIODIR |= 0x0F;        // P2.0 to P2.3 as output
}
// Function to rotate the stepper motor in half-step mode
void rotateStepperMotorHalfStep(int rotations, int clockwise) {
    // Define the half-step sequence
    uint8_t halfStepSequence[] = {0x09, 0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01};
    for (int rotation = 0; rotation < rotations; ++rotation) {
        for (int step = 0; step < 8; ++step) {
            // Apply the current sequence value to the motor pins
            LPC_GPIO2->FIOPIN = halfStepSequence[step];
            // Add a delay to control the motor speed (adjust as needed)
            for (volatile int i = 0; i < 50000; ++i);
        }
    }
}
int main() {
    // Initialize GPIO for stepper motor
    initializeGPIO();
    // Rotate the stepper motor clockwise in half-step for 10 times
    rotateStepperMotorHalfStep(10, 1);
    // Rotate the stepper motor anti-clockwise in half-step for 20 times
    rotateStepperMotorHalfStep(20, 0);
    return 0;
}
