// Embedded C program to blink the LED connected to the P2.0 to P2.3
#include <LPC17xx.h>
// Function to initialize GPIO pins
void initializeGPIO() {
    // Configure P2.0 to P2.3 as GPIO
    LPC_PINCON->PINSEL4 &= ~(0xFF);  // Clear bits 0-7
    LPC_GPIO2->FIODIR |= 0x0F;        // P2.0 to P2.3 as output
}
// Function to toggle the LED state
void toggleLEDs() {
    LPC_GPIO2->FIOPIN ^= 0x0F;  // Toggle P2.0 to P2.3 states
}
int main() {
    // Initialize GPIO
    initializeGPIO();
    while (1) {
        // Toggle the LEDs every second (adjust as needed)
        toggleLEDs();
        for (volatile int i = 0; i < 1000000; ++i);  // Delay
    }
    return 0;
}
