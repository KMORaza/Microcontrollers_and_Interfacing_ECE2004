// Embedded C program for alternative ON/OFF DC motor for some time.
// Assume positive pin and negative pins of DC motor are connected to pin 2.1 and pin 2.0 respectively.
#include <LPC17xx.h>
// Function to initialize GPIO pins for motor control
void initializeMotorGPIO() {
    // Configure P2.0 and P2.1 as GPIO for the DC motor
    LPC_PINCON->PINSEL4 &= ~(0xF);   // Clear bits 0-3
    LPC_GPIO2->FIODIR |= 0x03;       // P2.0 and P2.1 as output
}
// Function to control the DC motor ON/OFF state
void controlMotorState(int motorState) {
    if (motorState) {
        // Set P2.0 as low and P2.1 as high to turn ON the DC motor
        LPC_GPIO2->FIOPIN = (1 << 1);
    } else {
        // Set P2.0 as high and P2.1 as low to turn OFF the DC motor
        LPC_GPIO2->FIOPIN = (1 << 0);
    }
}
// Function to alternate motor ON/OFF state for a given duration
void alternateMotorState(int durationSeconds) {
    int counter;
    for (counter = 0; counter < durationSeconds * 1000000; ++counter) {
        // Alternate between turning ON and OFF every half a second
        controlMotorState(counter % 2 == 0);
    }
    // Turn OFF the motor at the end
    LPC_GPIO2->FIOPIN = 0x00;
}
int main() {
    // Initialize GPIO for the DC motor
    initializeMotorGPIO();
    // Alternate motor ON/OFF state for 10 seconds (adjust as needed)
    alternateMotorState(10);
    return 0;
}
