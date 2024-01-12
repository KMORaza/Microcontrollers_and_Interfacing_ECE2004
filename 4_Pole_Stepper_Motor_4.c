// Write an embedded C program to rotate 4-pole stepper motor in clockwise whenever dip switch is pressed. Assume stepper motor pins are connected to P2.3 to P2.0 (4th to 1st pole) and dip switch is connected to P2.26
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
// Function to rotate the stepper motor in a clockwise direction
void rotateClockwise() {
    // Define the stepping sequence for clockwise rotation
    uint8_t sequence[] = {0x09, 0x03, 0x06, 0x0C};
    while (1) {
        // Check if the dip switch is pressed
        if (isDipSwitchPressed()) {
            for (int step = 0; step < 4; ++step) {
                // Apply the current sequence value to the motor pins
                LPC_GPIO2->FIOPIN = sequence[step];
                // Add a delay to control the motor speed (adjust as needed)
                for (volatile int i = 0; i < 50000; ++i);
            }
        }
    }
}
int main() {
    // Initialize GPIO for stepper motor and dip switch
    initializeGPIO();
    // Rotate the stepper motor in a clockwise direction when the dip switch is pressed
    rotateClockwise();
    return 0;
}
