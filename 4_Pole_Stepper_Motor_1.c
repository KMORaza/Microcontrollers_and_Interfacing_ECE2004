// Write embedded C program to rotate 4-pole stepper motor in clockwise for 5 times. Assume Stepper motor pins are connected to P2.3 to P2.0 (4th to 1st pole)
#include <LPC17xx.h>
// Function to initialize GPIO pins
void initializeGPIO() {
    // Configure P2.0 to P2.3 as GPIO
    LPC_PINCON->PINSEL4 &= ~(0xFF);  // Clear bits 0-7
    LPC_GPIO2->FIODIR |= 0x0F;        // P2.0 to P2.3 as output
}
// Function to rotate the stepper motor in a clockwise direction
void rotateClockwise() {
    // Define the stepping sequence for clockwise rotation
    uint8_t sequence[] = {0x09, 0x03, 0x06, 0x0C};
    // Iterate through the sequence for 5 rotations
    for (int rotation = 0; rotation < 5; ++rotation) {
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
    // Rotate the stepper motor in a clockwise direction
    rotateClockwise();
    while (1) {
        // Your main program loop
    }
    return 0;
}
