// Embedded C program for 4*3 keypad interfacing
#include <LPC17xx.h>
// Function to initialize GPIO pins for keypad
void initializeKeypad() {
    // Configure rows as outputs (P2.0 to P2.2)
    LPC_GPIO2->FIODIR |= 0x07;
    // Configure columns as inputs (P2.3 to P2.6)
    LPC_GPIO2->FIODIR &= ~(0x78);
}
// Function to scan the keypad and return the pressed key
char scanKeypad() {
    // Rows: P2.0 to P2.2
    // Columns: P2.3 to P2.6
    // Iterate over each row
    for (int row = 0; row < 3; ++row) {
        // Activate the current row
        LPC_GPIO2->FIOPIN = (1 << row);
        // Check the columns for a pressed key
        for (int col = 3; col < 7; ++col) {
            if (!(LPC_GPIO2->FIOPIN & (1 << col))) {
                // Key pressed, return the corresponding character
                return (char)('1' + row * 3 + (col - 3));
            }
        }
        // Deactivate the current row
        LPC_GPIO2->FIOPIN &= ~(1 << row);
    }
    // No key pressed
    return '\0';
}
int main() {
    // Initialize GPIO for keypad
    initializeKeypad();
    char pressedKey;
    while (1) {
        // Scan the keypad
        pressedKey = scanKeypad();
        // Check if a key is pressed
        if (pressedKey != '\0') {
            // Perform an action based on the pressed key
            // For simplicity, print the pressed key to UART (assumed to be configured)
            // Replace the following line with your desired action.
            // UART_SendChar(pressedKey);
        }
    }
    return 0;
}
