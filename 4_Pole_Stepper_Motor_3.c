// Write an embedded C program to rotate 4-pole stepper motor in clockwise for 10 times and anti-clockwise 20 times. Assume Stepper motor pins are connected to P2.3 to P2.0 (4th to 1st pole).
#include <LPC17xx.h>
// Function to initialize GPIO pins
void initializeGPIO() {
    // Configure P2.0 to P2.3 as GPIO
    LPC_PINCON->PINSEL4 &= ~(0xFF);  // Clear bits 0-7
    LPC_GPIO2->FIODIR |= 0x0F;        // P2.0 to P2.3 as output
}
// Function to rotate the stepper motor in a specified direction for a given number of rotations
void rotateStepperMotor(uint8_t direction, int rotations) {
    // Define the stepping sequences
    uint8_t clockwiseSequence[] = {0x09, 0x03, 0x06, 0x0C};
    uint8_t antiClockwiseSequence[] = {0x0C, 0x06, 0x03, 0x09};
    // Select the appropriate sequence based on the direction
    uint8_t *sequence = (direction == 1) ? clockwiseSequence : antiClockwiseSequence;
    // Iterate through the sequence for the specified number of rotations
    for (int rotation = 0; rotation < rotations; ++rotation) {
        for (int step = 0; step < 4; ++step) {
            // Apply the current sequence value to the motor pins
            LPC_GPIO2->FIOPIN = sequence[step];
            // Add a delay to control the motor speed (adjust as needed)
            for (volatile int i = 0; i < 50000; ++i);
        }
    }
}
int main() {
    // Initialize GPIO for stepper motor
    initializeGPIO();
    // Rotate the stepper motor in a clockwise direction for 10 times
    rotateStepperMotor(1, 10);
    // Rotate the stepper motor in an anti-clockwise direction for 20 times
    rotateStepperMotor(0, 20);
    while (1) {
        // Your main program loop
    }
    return 0;
}
