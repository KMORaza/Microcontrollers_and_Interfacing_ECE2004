// Conditions:
// 1. Initially, the traffic light is RED.
// 2. After a certain duration, the light transitions to GREEN.
// 3. After a certain duration in the GREEN state, it transitions to YELLOW.
// 4. After a short duration in the YELLOW state, it transitions back to RED.
// 5. Repeat the cycle.
#include <LPC17xx.h>
// Function to initialize GPIO pins
void initializeGPIO() {
    // Configure GPIO pins for traffic lights
    LPC_PINCON->PINSEL4 &= ~(0xFF);  // Clear bits 0-7
    LPC_GPIO2->FIODIR |= 0x0F;        // P2.0 to P2.3 as output
}
// Function to control traffic light states
void controlTrafficLight() {
    // RED state
    LPC_GPIO2->FIOPIN = 0x01;  // RED ON, GREEN and YELLOW OFF
    for (volatile int i = 0; i < 5000000; ++i);  // Delay
    // GREEN state
    LPC_GPIO2->FIOPIN = 0x02;  // GREEN ON, RED and YELLOW OFF
    for (volatile int i = 0; i < 5000000; ++i);  // Delay
    // YELLOW state
    LPC_GPIO2->FIOPIN = 0x04;  // YELLOW ON, RED and GREEN OFF
    for (volatile int i = 0; i < 2000000; ++i);  // Delay
}
int main() {
    // Initialize GPIO
    initializeGPIO();
    while (1) {
        // Control the traffic light states in a loop
        controlTrafficLight();
    }
    return 0;
}
