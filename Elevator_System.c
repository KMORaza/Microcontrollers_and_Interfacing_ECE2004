#include <LPC17xx.h>
// Define floor constants
#define FLOOR_0 0
#define FLOOR_1 1
#define FLOOR_2 2
// Define GPIO pins for buttons
#define BUTTON_UP   (1 << 10)  // Assume P1.10 for the UP button
#define BUTTON_DOWN (1 << 11)  // Assume P1.11 for the DOWN button
#define BUTTON_0    (1 << 12)  // Assume P1.12 for the button to go to floor 0
#define BUTTON_1    (1 << 13)  // Assume P1.13 for the button to go to floor 1
#define BUTTON_2    (1 << 14)  // Assume P1.14 for the button to go to floor 2
// Function to initialize GPIO pins for buttons and elevator indicator LEDs
void initializeGPIO() {
    // Configure P1.10 to P1.14 as GPIO for elevator buttons
    LPC_PINCON->PINSEL3 &= ~(0x3FF);  // Clear bits 20-29
    LPC_GPIO1->FIODIR &= ~(BUTTON_UP | BUTTON_DOWN | BUTTON_0 | BUTTON_1 | BUTTON_2);  // Set as input
    // Configure P2.0 to P2.2 as GPIO for elevator indicator LEDs
    LPC_PINCON->PINSEL4 &= ~(0xFF);  // Clear bits 0-7
    LPC_GPIO2->FIODIR |= 0x07;        // Set as output
}
// Function to check if a button is pressed
int isButtonPressed(int button) {
    return !(LPC_GPIO1->FIOPIN & button);
}
// Function to control the elevator based on button presses
void controlElevator() {
    int currentFloor = FLOOR_0;  // Start at floor 0
    while (1) {
        // Check for button presses
        if (isButtonPressed(BUTTON_UP)) {
            // Move the elevator up
            if (currentFloor < FLOOR_2) {
                ++currentFloor;
                // Implement elevator motor control to move up
            }
        } else if (isButtonPressed(BUTTON_DOWN)) {
            // Move the elevator down
            if (currentFloor > FLOOR_0) {
                --currentFloor;
                // Implement elevator motor control to move down
            }
        } else if (isButtonPressed(BUTTON_0)) {
            // Go to floor 0
            // Implement elevator motor control to move to floor 0
            currentFloor = FLOOR_0;
        } else if (isButtonPressed(BUTTON_1)) {
            // Go to floor 1
            // Implement elevator motor control to move to floor 1
            currentFloor = FLOOR_1;
        } else if (isButtonPressed(BUTTON_2)) {
            // Go to floor 2
            // Implement elevator motor control to move to floor 2
            currentFloor = FLOOR_2;
        }
        // Update elevator indicator LEDs based on the current floor
        LPC_GPIO2->FIOPIN = currentFloor;
    }
}
int main() {
    // Initialize GPIO for buttons and elevator indicator LEDs
    initializeGPIO();
    // Control the elevator based on button presses
    controlElevator();
    return 0;
}
