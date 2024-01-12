// Embedded C program to blink the LED connected to the P2.26
#include <LPC17xx.h>
// Function to initialize GPIO pins
void initializeGPIO() {
    // Configure P2.26 as GPIO
    LPC_PINCON->PINSEL4 &= ~(3 << 20);  // Clear bits 20 and 21
    LPC_GPIO2->FIODIR |= (1 << 26);     // P2.26 as output
}
// Function to toggle the LED state
void toggleLED() {
    LPC_GPIO2->FIOPIN ^= (1 << 26);  // Toggle P2.26 state
}
int main() {
    // Initialize GPIO
    initializeGPIO();
    while (1) {
        // Toggle the LED every second (adjust as needed)
        toggleLED();
        for (volatile int i = 0; i < 1000000; ++i);  // Delay
    }
    return 0;
}
