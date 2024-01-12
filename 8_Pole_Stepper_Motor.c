;; Write an embedded C program to rotate 8-pole stepper motor in half step clockwise direction up to 225 degrees steps whenever we press 2 in 2x2 keypad and rotate in anti-clockwise direction 
;; to its original position when we press 3 in 2x2 keypad. Assume Stepper motor pins are connected to P2.15 to P2.8 (8th to 1st pole) and R1, R2, C1, C2 are connected to P3.7, P3.6, P3.5, and P3.4 respectively.
#include <LPC17xx.h>
// Function to initialize GPIO pins
void initializeGPIO() {
    // Configure GPIO for stepper motor (P2.8 to P2.15)
    LPC_PINCON->PINSEL4 &= ~(0xFF << 16);  // P2.8 to P2.15 as GPIO
    LPC_GPIO2->FIODIR |= 0xFF << 8;       // P2.8 to P2.15 as output
    // Configure GPIO for keypad (P3.4, P3.5, P3.6, P3.7)
    LPC_PINCON->PINSEL7 &= ~(0xFF << 16);  // P3.4, P3.5, P3.6, P3.7 as GPIO
    LPC_GPIO3->FIODIR &= ~(0xF << 4);      // P3.4, P3.5, P3.6, P3.7 as input
    LPC_GPIO3->FIOMASK |= (0xF << 4);      // Set P3.4, P3.5, P3.6, P3.7 as mask bits
}
// Function to control stepper motor in clockwise direction
void rotateClockwise() {
    for (int i = 0; i < 8; ++i) {
        // Set the appropriate bit pattern for half-step in clockwise direction
        LPC_GPIO2->FIOPIN = (1 << (15 - i)) | (1 << (8 + i));

        // Add a delay for smooth rotation (adjust as needed)
        for (volatile int j = 0; j < 100000; ++j);
    }
}
// Function to control stepper motor in anti-clockwise direction
void rotateAntiClockwise() {
    for (int i = 0; i < 8; ++i) {
        // Set the appropriate bit pattern for half-step in anti-clockwise direction
        LPC_GPIO2->FIOPIN = (1 << (8 + i)) | (1 << (15 - i));

        // Add a delay for smooth rotation (adjust as needed)
        for (volatile int j = 0; j < 100000; ++j);
    }
}
// Function to read keypad input
int readKeypadInput() {
    // Check for Row 1 (R1)
    LPC_GPIO3->FIOMASK &= ~(0xF << 4);
    LPC_GPIO3->FIOMASK |= (0xE << 4);
    if ((LPC_GPIO3->FIOPIN & (1 << 7)) == 0) {
        while ((LPC_GPIO3->FIOPIN & (1 << 7)) == 0);
        return 1;
    }
    // Check for Row 2 (R2)
    LPC_GPIO3->FIOMASK &= ~(0xF << 4);
    LPC_GPIO3->FIOMASK |= (0xD << 4);
    if ((LPC_GPIO3->FIOPIN & (1 << 6)) == 0) {
        while ((LPC_GPIO3->FIOPIN & (1 << 6)) == 0);
        return 2;
    }
    // Check for Row 3 (R3)
    LPC_GPIO3->FIOMASK &= ~(0xF << 4);
    LPC_GPIO3->FIOMASK |= (0xB << 4);
    if ((LPC_GPIO3->FIOPIN & (1 << 5)) == 0) {
        while ((LPC_GPIO3->FIOPIN & (1 << 5)) == 0);
        return 3;
    }
    // Check for Row 4 (R4)
    LPC_GPIO3->FIOMASK &= ~(0xF << 4);
    LPC_GPIO3->FIOMASK |= (0x7 << 4);
    if ((LPC_GPIO3->FIOPIN & (1 << 4)) == 0) {
        while ((LPC_GPIO3->FIOPIN & (1 << 4)) == 0);
        return 4;
    }
    return 0;  // No key pressed
}
int main() {
    initializeGPIO();  // Initialize GPIO pins
    while (1) {
        int key = readKeypadInput();
        switch (key) {
            case 2:
                rotateClockwise();  // Rotate clockwise for key 2
                break;
            case 3:
                rotateAntiClockwise();  // Rotate anti-clockwise for key 3
                break;
            default:
                break;
        }
    }
    return 0;
}
