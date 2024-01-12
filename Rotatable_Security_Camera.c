// Conditions:
// 1. The 6-pole stepper motor is connected to pins P2.0 to P2.5 (or any other suitable GPIO pins) on an LPC17xx microcontroller.
// 2. The system can rotate the camera in both clockwise and anti-clockwise directions.
// 3. User input is provided through a set of buttons connected to different GPIO pins. For simplicity, let's assume one button each for clockwise and anti-clockwise rotation.
// 4. The system continuously monitors the user input to adjust the camera's position accordingly.
#include <LPC17xx.h>
// Function to initialize GPIO pins for motor control
void initializeMotorGPIO() {
    // Configure P2.0 to P2.5 as GPIO for the 6-pole stepper motor
    LPC_PINCON->PINSEL4 &= ~(0xFF);  // Clear bits 0-7
    LPC_GPIO2->FIODIR |= 0x3F;        // P2.0 to P2.5 as output
}
// Function to initialize GPIO pins for button inputs
void initializeButtonGPIO() {
    // Configure P0.10 and P0.11 as GPIO for clockwise and anti-clockwise buttons
    LPC_PINCON->PINSEL0 &= ~(0xF << 20);  // Clear bits 20-23
    LPC_GPIO0->FIODIR &= ~(1 << 10);      // P0.10 as input (clockwise button)
    LPC_GPIO0->FIODIR &= ~(1 << 11);      // P0.11 as input (anti-clockwise button)
}
// Function to control motor rotation based on user input
void rotateCamera() {
    // Define the stepping sequences for the motor
    uint8_t clockwiseSequence[] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09};
    uint8_t antiClockwiseSequence[] = {0x09, 0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01};
    while (1) {
        // Check if the clockwise button is pressed
        if (!(LPC_GPIO0->FIOPIN & (1 << 10))) {
            for (int step = 0; step < 8; ++step) {
                // Apply the current sequence value to the motor pins
                LPC_GPIO2->FIOPIN = clockwiseSequence[step];

                // Add a delay to control the motor speed (adjust as needed)
                for (volatile int i = 0; i < 50000; ++i);
            }
        }
        // Check if the anti-clockwise button is pressed
        else if (!(LPC_GPIO0->FIOPIN & (1 << 11))) {
            for (int step = 0; step < 8; ++step) {
                // Apply the current sequence value to the motor pins
                LPC_GPIO2->FIOPIN = antiClockwiseSequence[step];
                // Add a delay to control the motor speed (adjust as needed)
                for (volatile int i = 0; i < 50000; ++i);
            }
        }
        else {
            // Stop the motor or maintain the current position
            LPC_GPIO2->FIOPIN = 0x00;
        }
    }
}
int main() {
    // Initialize GPIO for motor and buttons
    initializeMotorGPIO();
    initializeButtonGPIO();
    // Rotate the camera based on user input
    rotateCamera();
    return 0;
}
