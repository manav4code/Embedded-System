#include <reg51.h>

// Function to initialize serial communication
void init_serial(void) {
    TMOD = 0x20;   // Set timer mode for baud rate generation
    TH1 = -3;      // Load TH1 with a value for desired baud rate
    TR1 = 1;       // Start Timer 1
    SCON = 0x50;   // Set serial communication mode and enable receiver
}

void main(void) {
    unsigned char code *x = 0x45;  // Define a pointer to a code location
    unsigned char code *r0 = 0x60;  // Define another pointer to a code location
    unsigned char i;

    init_serial();   // Initialize serial communication

    // Send the first 10 bytes pointed to by x
    for (i = 0; i < 10; i++) {
        SBUF = *x;    // Load the byte pointed to by x into the serial buffer
        while (!TI);  // Wait for transmission to complete
        TI = 0;       // Clear the transmit interrupt flag
        x++;          // Increment the pointer
    }

    // Send the byte pointed to by r0 repeatedly
    while (1) {
        SBUF = (*r0);   // Load the byte pointed to by r0 into the serial buffer
        while (!TI);    // Wait for transmission to complete
        TI = 0;         // Clear the transmit interrupt flag
    }
}
